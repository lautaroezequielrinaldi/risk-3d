#include<cstdlib> // Para definiciòn de EXIT_SUCCESS.
#include<gtkmm/main.h> // Para definiciòn de Gtk::Main.
#include "mainwindow.h" // Para definiciòn de MainWindow.

int main (int argc, char ** argv){
	// Inicializa Gtkmm.
	Gtk::Main main(argc, argv);

	// Crea ventana principal.
	MainWindow mainWindow;

	// Ejecuta la aplicacion Gtkmm.
	main.run(mainWindow);

	// Retorna EXIT_SUCCESS
	return EXIT_SUCCESS;

	// estados
	// nada -> click en un lugar virgen -> crea ciudad
	// nada -> click en una ciudad -> relacionando ciudad
	// nada -> click en un continente -> relacionando continente
	// relacionando ciudad -> click en un lugar virgen -> crea ciudad y relacion -> nada
	// relacionando ciudad -> click en una ciudad sin relacion -> relaciona ciudad -> nada
	// relacionando ciudad -> click en una ciudad con relacion -> anula relacion -> nada
	// relacionnado ciudad -> click en un continente sin relacion ... y asi
	// nada -> doble click en una ciudad / continente -> renombrar -> nombre vacio -> eliminar -> nada

	// relacionando continente -> click en un continente -> error -> nada
	// hay un area para poner el nombre y un boton para salvar (accion que se hara en el servidor)

	// hay una zona rectangular 2d arriba para crear y relacionar continentes
}
