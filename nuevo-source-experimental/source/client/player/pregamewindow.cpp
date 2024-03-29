#include "pregamewindow.h"
#include "../../common/commands/chat.h"
#include "../../common/commands/quit.h"
#include "../../common/commands/selectmap.h"
#include "gamewindow.h"

#include "../../common/parser/mapaparser.h"
#include<gtkmm/liststore.h> // Para definiciòn de Gtk::ListStore.
#include<gtkmm/combobox.h> // Para definiciòn de Gtk::ComboBox.
#include<iostream>
#include<sstream>
#include<fstream>

PreGameWindow::PreGameWindow(ReferenceCountPtr<Game>& game):
    CommandObserver(),
    game(game),
	Gtk::Window(),
	verticalBox(),
	horizontalBox(),
	messageTextView(),
	messageEntry(),
	sendMessageButton(),
	readyToPlayButton(),
	connectionDialogButton(),
	quitButton(),
	connected(false),
	hasQuit(false) {
		
	this->mapList = NULL;
	this->youAre = NULL;
	this->readyToPlay=NULL;
	this->cantJugadoresConectados=0;

		
    // Establece el titulo de la ventana
	this->set_title("Pre sala de juego Risk3d");
	// Establece el label del boton send message.
	sendMessageButton.set_label("Send Message");
	sendMessageButton.set_sensitive(false);
	// Establece el label del boton ready to play.
	readyToPlayButton.set_label("Ready To Play");
	readyToPlayButton.set_sensitive(false);
	// Establece el label del boton de dialogo de conexion.
	connectionDialogButton.set_label("Connect to server...");
	// Establece el label del boton de salir.
	quitButton.set_label("Quit");

	// Agrega el entry de mensajes al horizontal box.
	horizontalBox.pack_start(messageEntry, Gtk::PACK_SHRINK);
	// Agrega el button de enviar mensajes al horizontal box.
	horizontalBox.pack_start(sendMessageButton, Gtk::PACK_SHRINK);
	// Agrega el button ready to play al horizontal box.
	horizontalBox.pack_start(readyToPlayButton, Gtk::PACK_SHRINK);
	// Agrega el boton de dialogo de conexion al horizontal box.
	horizontalBox.pack_start(connectionDialogButton, Gtk::PACK_SHRINK);
	// Agrega el boton de quit al horizontal box.
	horizontalBox.pack_start(quitButton, Gtk::PACK_SHRINK);

	// Agrega el text view de mensajes al vertical box.
	verticalBox.pack_start(messageTextView, Gtk::PACK_SHRINK);
	// Agrega el horizontal box al vertical box.
	verticalBox.pack_start(horizontalBox, Gtk::PACK_SHRINK);
	// Agrega el vertical layout a la ventana.
	add(verticalBox);
	// Conecta el signal_clicked del boton connnectionDialogButton con su manejador.
	connectionDialogButton.signal_clicked().connect(sigc::mem_fun(*this,
		&PreGameWindow::onConnectionDialogButtonClicked));
	// Conecta el signal_clicked del boton readyToPlayButton con su manejador.
	sendMessageButton.signal_clicked().connect(sigc::mem_fun(*this,
			&PreGameWindow::onSendMessageButtonClicked));
	// Conecta el signal_clicked del boton readyToPlayButton con su manejador.
	readyToPlayButton.signal_clicked().connect(sigc::mem_fun(*this,
		&PreGameWindow::onReadyToPlayButtonClicked));
	// Conecta el signal_clicked del boton quit con su manejador.
	quitButton.signal_clicked().connect(sigc::mem_fun(*this,
			&PreGameWindow::onQuitButtonClicked));
	
	
			
	// Muestro todos los widgets.
	show_all();
}

void PreGameWindow::showConnectionDialog() {
	Gtk::Label serverUrlLabel("Url del servidor:");
	Gtk::Entry serverUrlEntry;
	serverUrlEntry.set_text("localhost:2000");
	Gtk::Dialog connectionDialog("Conectar al servidor");
	connectionDialog.get_vbox()->add(serverUrlLabel);
	connectionDialog.get_vbox()->add(serverUrlEntry);
	connectionDialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
	connectionDialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_OK);
	connectionDialog.show_all();
	int result = connectionDialog.run();
	if (result == Gtk::RESPONSE_OK) {
		try {
			std::string url = serverUrlEntry.get_text();
            // Parsea la URL
            UrlParser parser(url);
            // Conecta el socket
            std::cout << parser.getDomain() << std::endl;
            std::cout << parser.getPort() << std::endl;

			Socket* socket = new Socket(parser.getDomain(), parser.getPort());

			serverProxy = new ServerProxy(socket, game);
						
			// conecta la señal lanzada por el dispatcher que maneja la llegada de un map List
			this->serverProxy->getDispatcherMapList().connect(sigc::mem_fun(*this, &PreGameWindow::on_map_list_selection));
			// conecta la señal lanzada por el dispatcher que maneja la llegada de un you are
			this->serverProxy->getDispatcherYouAre().connect(sigc::mem_fun(*this, &PreGameWindow::on_you_are_arrival));

			// conecta la señal lanzada por el dispatcher que maneja la llegada de un ready to play
			this->serverProxy->getDispatcherReadyToPlay().connect(sigc::mem_fun(*this, &PreGameWindow::on_Ready_to_play_arrival));

			// conecta la señal lanzada por el dispatcher que maneja la llegada de un ready to play
			this->serverProxy->getDispatcherNoRoom().connect(sigc::mem_fun(*this, &PreGameWindow::on_no_room_arrival));		
			
			
			JoinGame* cmd = new JoinGame();
			serverProxy->notify(*cmd);
			delete cmd;
			
			
			
			sendMessageButton.set_sensitive(true);
			readyToPlayButton.set_sensitive(false);
        	connectionDialogButton.set_sensitive(false);
            
            serverProxy->registerCommandObserver(this);
			
			serverProxy->start();

			std::cerr<<"INICIO THREAD"<<std::endl;
			connected = true;
			
		} catch (SocketConnectionException& exception) {
			Gtk::MessageDialog errorDialog(*this, "No se pudo conectar al servidor!!!", false,
				Gtk::MESSAGE_ERROR);
			errorDialog.set_title("Error");
			errorDialog.run();
		}
	}
}

void PreGameWindow::onConnectionDialogButtonClicked() {
	this->showConnectionDialog();
	
	
	
}

void PreGameWindow::onSendMessageButtonClicked() {
	if (connected) {
		Chat* cmd = new Chat();
		std::string message = messageEntry.get_text();
		cmd->setMainMsg(message);
		serverProxy->notify(*cmd);
        delete cmd;
		messageEntry.set_text("");
	}	
}

void PreGameWindow::onReadyToPlayButtonClicked() {

	
	ReadyToPlay* cmd = new ReadyToPlay();
	//indico que cliente manda el ready para saber a cual marcar en el servidor
	cmd->setFrom(this->serverProxy->getMe());	
	
	serverProxy->notify(*cmd);
	
	delete cmd;
	
	readyToPlayButton.set_sensitive(false);
}

void PreGameWindow::onQuitButtonClicked() {
	if (connected) {
		//Quit cmd;
	    //serverProxy->notify(cmd);	
		//serverProxy->cancel();
		//this->serverProxy->join();
		//	Gtk::Main::quit();
		this->serverProxy->kill();
		//serverProxy->meTenesHarta = false;
	}
	//std::cerr<<"llegue a quit!!!!!!!!!!!!!!!!!!!!!!"<<std::endl;
	
	//hasQuit = true;

}

bool PreGameWindow::userHasQuit() {
	return hasQuit;
}



void PreGameWindow::commandExecuted(Map & cmd){


	// grabo en un archivo el contenido del xml que contiene map
	std::ofstream fileTempMapa;
	std::string pathNom = "mapa.xml";    // "./maps/mapaTemporal";
	fileTempMapa.open(pathNom.c_str(),std::ios_base::out);
	
	//grabo en el archivo el mapa que trajo el comando.
	std::string contenido ( cmd.getMap() );
	
	//std::cerr<<"CONTENIDO:"<< std::endl << contenido << std::endl;
	
	fileTempMapa <<  contenido;
	
	MapaParser mapaParser;
	
	//levanto el mapa desde archivo xml a memoria
	ReferenceCountPtr<Mapa> mapa = mapaParser.loadMap("mapa.xml");//("./maps/mapaTemporal");

	//seteo el mapa que se usara en el modelo del juego
	this->serverProxy->getGame()->setMapa(mapa);
	
	std::cerr<<"Cantidad de paises en el game que se jugara: "<<this->serverProxy->getGame()->getMapa()->getCantidadPaises() <<std::endl;
	
	fileTempMapa.flush();
	fileTempMapa.close();
	
	std::cerr<<"Termino de cargar el mapa en todos los clientes....."<<std::endl;
	

	
}

void PreGameWindow::commandExecuted(TurnToOccupy & cmd){
	
	std::cerr<<"Termina presala, llego TurnToOccupy........"<<std::endl;
	
	//oculta pre sala
	this->hide();
	
    iniciarOpenGL();
}

void PreGameWindow::commandExecuted(YouAre & cmd){
	
	this->youAre = &cmd;
	std::cerr<<"almaceno youAre en preGameWindow....."<<std::endl;
	
	
}

void PreGameWindow::commandExecuted(MapList& cmd){
	
	if ( &cmd == NULL )
		std::cerr<<"MAPLIST LLEGA A PREGAMEWINDOW COMO NULL....."<<std::endl;
		
	this->mapList = &cmd;
	std::cerr<<"almaceno mapList en preGameWindow....."<<std::endl;
	
}


void PreGameWindow::commandExecuted(ReadyToPlay & cmd){
	
	this->readyToPlay = &cmd;
	std::cerr<<"almaceno readyToPlay en preGameWindow....."<<std::endl;
	
	
	if ( this->readyToPlay == NULL )
		std::cerr<<"PERO ES NULL....."<<std::endl;
}

ReferenceCountPtr<ServerProxy> PreGameWindow::getServerProxy() {
    return serverProxy;
}

void PreGameWindow::commandExecuted(Chat& cmd) {
	std::string buffer = messageTextView.get_buffer()->get_text();
	buffer =  buffer + "\r\n" + cmd.getMainMsg();
	messageTextView.get_buffer()->set_text(buffer);
}

void PreGameWindow::on_you_are_arrival(){
		
	std::string saludo;
	
	//si me=0 es porque el jugador al que se esta notificando es el nuevo 	
  	if ( this->serverProxy->getMe() == 0 ){		
  		//cambiar getJugador por getCantPLayersActivos 
  		this->serverProxy->setMe( this->youAre->getTo() );
  		std::cerr<<"Se almacena 'me' con valor "<< this->serverProxy->getMe() <<std::endl;
	}
	else
		std::cerr<<"El jugador ya tenia asignado me con valor: "<< this->serverProxy->getMe() <<std::endl;
  		
	// si hay que notificar al jugador que se conecto
	if ( this->serverProxy->getMe() == this->youAre->getTo() )
  		saludo = this->youAre->getMainMsg();
  	else
  		saludo =this->youAre->getSecMsg();		
  		
	//creacion del dialogo de bienvenida y aviso de nuevo jugador conectado
  	Gtk::Label saludoLabel(saludo);	
	Gtk::Dialog selectMapDialog("Bienvenido al Risk-3d");
	selectMapDialog.get_vbox()->add(saludoLabel);
	selectMapDialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
	selectMapDialog.show_all();
	selectMapDialog.run();
	
	readyToPlayButton.set_sensitive(true);
	
}

void PreGameWindow::on_no_room_arrival(){
	
	// si hay que notificar al jugador que no tiene lugar en la sala
	if ( this->serverProxy->getMe() == 0 ){		
  		
		//creacion del dialogo 
	  	Gtk::Label noRoomLabel("No hay mas lugar en la sala, intenta en otro momento");	
		Gtk::Dialog selectMapDialog("-Aviso-");
		selectMapDialog.get_vbox()->add(noRoomLabel);
		//selectMapDialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
		selectMapDialog.show_all();
		selectMapDialog.run();
	}


}

void PreGameWindow::on_Ready_to_play_arrival(){
	
/*			
	//creacion del dialogo de ready to play para todos.
	Gtk::Dialog selectMapDialog("-Aviso-");
	Gtk::Label readyLabel("Todos los jugadores estan listos para jugar,Se Pasara a modo juego");	
	selectMapDialog.get_vbox()->add(readyLabel);
	selectMapDialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
	selectMapDialog.show_all();
	int resul = selectMapDialog.run();
*/
	
	//creo todos los players en el game del serverProxy
	for (int i=0; i < this->readyToPlay->getTo() ; i++){
		
		this->serverProxy->getGame()->addPlayer();
		std::cerr<<"Se creo jugador numero "<<i+1<<"en game del ServerProxy....."<<std::endl;
	} 
	

}

void PreGameWindow::iniciarOpenGL(){
	
		GameWindow gameWindow(this->serverProxy); 
	
		char* argv = "risk3d-client";
	
    	gameWindow.run(1, &argv);	
	
}

void PreGameWindow::on_map_list_selection(){
	
	
	
	class ModelColumns : public Gtk::TreeModel::ColumnRecord
  	{
  		public:

    		ModelColumns(){
    			add(m_col_name); 
    		}

    	Gtk::TreeModelColumn<int> m_col_id;
    	Gtk::TreeModelColumn<Glib::ustring> m_col_name;
  	};

	//modelo para la columna del combo
  	ModelColumns m_Column;

 	//Child widgets:
  	Gtk::ComboBox m_Combo;
  	//m_Combo.signal_changed().connect( sigc::mem_fun(*this, &PreGameWindow::on_combo_changed) );
  	  
  	Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

	//creo tree model
	m_refTreeModel = Gtk::ListStore::create(m_Column);
  	m_Combo.set_model(m_refTreeModel);

  	//completo el combo box con la lista de paises que trae el comando selectMap
  	
  	if ( this->mapList == NULL )
  		std::cerr<<"COMMAND MAP LIST GUARDADO EN PREGAMEWIN ES NULL....."<<std::endl;
  	
  
  	std::vector<std::string> vecMapas = this->mapList->getMapList();

  	Gtk::TreeModel::Row row ;//= *(m_refTreeModel->append());
  		
	for ( unsigned int i =0; i< vecMapas.size() ; i++ ){
  		
  		row = *(m_refTreeModel->append());
  		row[m_Column.m_col_name] = vecMapas.at(i);

	}


  	m_Combo.pack_start(m_Column.m_col_name);
  	//seteo quue por defecto este seleccionado el 1er mapa de la lista
	m_Combo.set_active(0);
	
	int jugNum = this->youAre->getTo();
	
	std::ostringstream strNumeroJugador;
	strNumeroJugador << jugNum;
	
	std::string saludo = "Sos el jugador numero " + strNumeroJugador.str();

	Gtk::Label bienve ( "Bienvenido al Risk-3d");
  	Gtk::Label saludoLabel(saludo);			
	Gtk::Label seleccionLabel("Selecciona el mapa sobre el cual se jugara:");
	Gtk::Dialog selectMapDialog("Seleccion de mapa");
	selectMapDialog.get_vbox()->add(bienve);
	selectMapDialog.get_vbox()->add(saludoLabel);
	selectMapDialog.get_vbox()->add(seleccionLabel);
	selectMapDialog.get_vbox()->add(m_Combo);
	
	selectMapDialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
	
	selectMapDialog.show_all();
	
	int result = selectMapDialog.run();
	
	if (result == Gtk::RESPONSE_OK) {
		//muestro la opcion eleigida
		Gtk::TreeModel::iterator iter = m_Combo.get_active();
		if(iter)
  		{
    		Gtk::TreeModel::Row row = *iter;
    		if(row){
      			//obtengo datos de la fila seleccionada del combo
      			Glib::ustring mapaSeleccionado = row[m_Column.m_col_name];
      			//std::cerr <<"Mapa seleccionado: "<< mapaSeleccionado << std::endl;
      			
      			std::vector<std::string> vecParam;
      			
      			std::ostringstream strNumeroJugador;
				strNumeroJugador << "1";

				//agrego al vec los parametros para construir selectMap
				vecParam.push_back(strNumeroJugador.str());
				vecParam.push_back(mapaSeleccionado);

      			
      			//construyo comando selectMap para notificar al servidor el mapa elegido.
      			SelectMap* commandMap = new SelectMap(vecParam);
      			
      			serverProxy->notify(*commandMap);
      			delete commandMap;
    		}
  		}
  		
  		readyToPlayButton.set_sensitive(true);
	}
	
	this->serverProxy->setMe(1);
	
}


void PreGameWindow::setActivePlayerCount( int playerCount ){
	this->cantJugadoresConectados = playerCount;
}
		
int PreGameWindow::getActivePlayerCount(){
	return this->cantJugadoresConectados;
}		



PreGameWindow::~PreGameWindow() {
	// No realiza ninguna accion.
}

