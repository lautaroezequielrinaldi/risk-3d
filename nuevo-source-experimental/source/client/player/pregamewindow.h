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
#include "../../common/commands/joingame.h"
#include "../../common/commands/readytoplay.h"
#include "../../common/commands/maplist.h"
#include "../../common/commands/youare.h"
#include "../../common/commands/quit.h"
#include "../../common/commands/commandobserver.h"
#include "net/serverproxy.h"
#include "../../common/smartpointer/referencecountptr.h"

/**
 * Representa la presala del juego donde puede haber chat y seleccion de mapa.
 */
class PreGameWindow: public CommandObserver, public Gtk::Window {
	/**
	 * Atributos privados de la clase PreGameWindow.
	 */
	private:
		/**
		 * Almacena la referencia al server proxy a conectarse.
		 */
		ReferenceCountPtr<ServerProxy> serverProxy;
        /**
         * Almacena una referencia al game.
         */
        ReferenceCountPtr<Game>& game;
        
        /**
         * Almacena una referencia a un comando que se envia al cliente.
         */
        // Command* command;
        MapList* mapList;
        
        YouAre* youAre;
        
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
		 * Manejador de la señal realizada por el dispatcher encargado de la notificacion de un map List.
		 */
		void on_map_list_selection();
		
		/**
		 * Manejador de la señal realizada por el dispatcher encargado de la notificacion de un you are.
		 */		
		void on_you_are_arrival();
		
		
	/**
	 * Metodos publicos de la clase PreGameWindow.
	 */
	public:
		/**
		 * Constructor de la clase PreGameWindow.
		 */
		PreGameWindow(ReferenceCountPtr<Game>& game);
		/**
		 * Obtiene el game manager usado durante la presala.
		 */
		ReferenceCountPtr<ServerProxy> getServerProxy();
		/**
		 * Devuelve si ha salido el jugador presionando el boton quit.
		 */
		bool userHasQuit();
		/**
		 * Responde ante la llegada de un commando mapList.
		 */
		virtual void commandExecuted(SelectMap& cmd);
		/**
		 * Responde ante la llegada de un comando chat.
		 */
		virtual void commandExecuted(Chat& cmd);
		
		/**
		 * Responde ante la llegada de un comando mapList.
		 */
		virtual void commandExecuted(MapList& cmd);
		
		virtual void commandExecuted(YouAre& cmd);
		
		/**
		 * Destructor virtual de la clase PreGameWindow.
		 */
		virtual ~PreGameWindow();
};

#endif /** __PREGAMEWINDOW_H__ */

