#include "pregamewindow.h"
#include<iostream>
#include<iostream>
#include<iostream>

PreGameWindow::PreGameWindow(ReferenceCountPtr<GameManager>& gameManager):
	StateObserver(),
	Gtk::Window(),
	gameManager(gameManager),
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
	// Se registra como listener de cambios de estados en el game manager.
	if (gameManager != NULL) {
		gameManager->registerObserver(this);
	}
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
	serverUrlEntry.set_text("localhost");
	Gtk::Dialog connectionDialog("Conectar al servidor");
	connectionDialog.get_vbox()->add(serverUrlLabel);
	connectionDialog.get_vbox()->add(serverUrlEntry);
	connectionDialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
	connectionDialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_OK);
	connectionDialog.show_all();
	int result = connectionDialog.run();
	if (result == Gtk::RESPONSE_OK) {
		try {
			std::cout << "Se va a transformar en string" << std::endl;
			std::string url = serverUrlEntry.get_text();
			std::cout << "Se llego a tranformar en string" << std::endl;
			Socket* socket = new Socket(url, 2000);
			std::cout << "Se va a crear socket" << std::endl;

			// que pasa si ...
			//                  = new ServerProxy(new Socket("localhost", 2000), gamemanager); ?

			ReferenceCountPtr<ServerProxy> serverProxy = new ServerProxy(socket, gameManager);
			gameManager->add(serverProxy);
			UIJoinGame* cmd = new UIJoinGame();
			gameManager->execute(cmd);
			delete cmd;
			sendMessageButton.set_sensitive(true);
			readyToPlayButton.set_sensitive(true);
        	connectionDialogButton.set_sensitive(false);
			serverProxy->start();
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
	std::cout << "TODO: Deberia mandar mensajes pero no esta implementado... Fuck!!!" << std::endl;
}

void PreGameWindow::onReadyToPlayButtonClicked() {
	UIReadyToPlay* cmd = new UIReadyToPlay();
	gameManager->execute(cmd);
	delete cmd;
	readyToPlayButton.set_sensitive(false);
}

void PreGameWindow::onQuitButtonClicked() {
	if (connected) {
		UIQuit* cmd = new UIQuit();
		gameManager->execute(cmd);
		delete cmd;
		hasQuit	= true;
	}
	Gtk::Main::quit();
}

bool PreGameWindow::userHasQuit() {
	return hasQuit;
}

PreGameWindow::~PreGameWindow() {
	// No realiza ninguna accion.
}

