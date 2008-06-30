#include "pregamewindow.h"

PreGameWindow::PreGameWindow(ReferenceCountPtr<GameManager>& gameManager):
	StateObserver(),
	Gtk::Window(),
	gameManager(gameManager),
	verticalBox(),
	connectionDialogButton() {
	// Se registra como listener de cambios de estados en el game manager.
	if (gameManager != NULL) {
		gameManager->registerObserver(this);
	}
	// Establece el titulo de la ventana
	this->set_title("Pre sala de juego Risk3d");
	
	// Establece el label del boton de dialogo de conexion.
	connectionDialogButton.set_label("Connect to server...");
	// Agrega el boton de dialogo de conexion al vertical box.
	verticalBox.pack_end(connectionDialogButton, Gtk::PACK_SHRINK);
	// Agrega el vertical layout a la ventana.
	add(verticalBox);
	// Conecta el signal_clicked del boton connnectionDialogButton con su manejador.
	connectionDialogButton.signal_clicked().connect(sigc::mem_fun(*this,
		&PreGameWindow::onConnectionDialogButtonClicked));
	// Muestro todos los widgets.
	show_all();
}

void PreGameWindow::showConnectionDialog() {
	Gtk::Label serverUrlLabel("Url del servidor:");
	Gtk::Entry serverUrlEntry;
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
			ReferenceCountPtr<ServerProxy> serverProxy = new ServerProxy(socket, gameManager);
			gameManager->add(serverProxy);
            UIJoinGame * cmd = new UIJoinGame();
            gameManager->execute("uiJoinGame", cmd->serialize());
            delete(cmd);
	        connectionDialogButton.set_sensitive(false);
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

PreGameWindow::~PreGameWindow() {
	// No realiza ninguna accion.
}

