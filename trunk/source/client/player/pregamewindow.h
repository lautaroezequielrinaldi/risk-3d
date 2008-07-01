#ifndef __PREGAMEWINDOW_H__
#define __PREGAMEWINDOW_H__

#include<gtkmm/main.h>
#include<gtkmm/window.h>
#include<gtkmm/box.h>
#include<gtkmm/button.h>
#include<gtkmm/label.h>
#include<gtkmm/textview.h>
#include<gtkmm/entry.h>
#include<gtkmm/stock.h>
#include<gtkmm/messagedialog.h>
#include<gtkmm/dialog.h>
#include "../../common/commands/uijoingame.h"
#include "../../common/commands/uireadytoplay.h"
#include "../../common/commands/uiquit.h"
#include "../../common/model/gamemanager.h"
#include "../../common/state/stateobserver.h"
#include "../../common/smartpointer/referencecountptr.h"

/**
 * Representa la presala del juego donde puede haber chat y seleccion de mapa.
 */
class PreGameWindow: public StateObserver, public Gtk::Window {
	/**
	 * Atributos privados de la clase PreGameWindow.
	 */
	private:
		/**
		 * Almacena la referencia al server proxy a conectarse.
		 */
		ReferenceCountPtr<ServerProxy> serverProxy;
		/**
		 * Almacena la referencia al GameManager.
		 */
		ReferenceCountPtr<GameManager> gameManager;
		/**
		 * Almacena el layout vertical de la ventana.
		 */
		Gtk::VBox verticalBox;
		/**
		 * Almacena el layout horizontal de la ventana.
		 */
		Gtk::HBox horizontalBox;
		/**
		 * Almacena el textview para mostrar los mensajes de chat.
		 */
		Gtk::TextView messageTextView;
		/**
		 * Almacena el entry para ingresar los mensajes de chat.
		 */
		Gtk::Entry messageEntry;
		/**
		 * Almacena el boton para enviar mensajes de chat.
		 */
		Gtk::Button sendMessageButton;
		/**
		 * Almacena el boton para enviar ready to play.
		 */
		Gtk::Button readyToPlayButton;
		/**
		 * Almacena una referencia al boton de dialogo de conexion.
		 */
		Gtk::Button connectionDialogButton;
		/**
		 * Almacena una referencia al boton quit para salir.
		 */
		Gtk::Button quitButton;
		/**
		 * Almacena si se ha conectado.
		 */
		bool connected;
        /**
		 * Almacena si se ha salido.
		 */
        bool hasQuit;
	/**
	 * Metodos privados de la clase PreGameWindow.
	 */
	private:
		/**
		 * Constructor copia de la clase PreGameWindow.
		 */
		PreGameWindow(const PreGameWindow& otherInstance);
		/**
		 * Operador de asignacion de la clase PreGameWindow.
		 */
		PreGameWindow& operator=(const PreGameWindow& otherInstance);
	/**
	 * Metodos protegidos de la clase PreGameWindow.
	 */
	protected:
		/**
		 * Muestra el cuadro de dialogo de conexion con el servidor.
		 */
		void showConnectionDialog();
		/**
		 * Manejador de la senial signal_clicked del boton connection dialog button.
		 */
		void onConnectionDialogButtonClicked();
		/**
		 * Manejador de la senial signal_clicked del boton send messsage button.
		 */
		void onSendMessageButtonClicked();
		/**
		 * Manejador de la senial signal_clicked del boton ready to play button.
		 */
		void onReadyToPlayButtonClicked();
		/**
		 * Manejador de la senial signal_clicked del boton quit.
		 */
		void onQuitButtonClicked();
	/**
	 * Metodos publicos de la clase PreGameWindow.
	 */
	public:
		/**
		 * Constructor de la clase PreGameWindow.
		 */
		PreGameWindow(ReferenceCountPtr<GameManager>& gameManager);
		/**
		 * Obtiene el game manager usado durante la presala.
		 */
		ReferenceCountPtr<GameManager> getGameManager();
		/**
		 * Devuelve si ha salido el jugador presionando el boton quit.
		 */
		bool userHasQuit();
		/**
		 * Destructor virtual de la clase PreGameWindow.
		 */
		virtual ~PreGameWindow();
};

#endif /** __PREGAMEWINDOW_H__ */

