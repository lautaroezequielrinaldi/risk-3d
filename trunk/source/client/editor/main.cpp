#include<gtkmm/main.h>
#include<gtkmm/window.h>
#include<gtkmm/scrolledwindow.h>
#include<gtkmm/viewport.h>
#include<gtkmm/notebook.h>
#include<gtkmm/adjustment.h>
#include "continentpage.h"
#include "countrypage.h"
#include "gamecardpage.h"
#include "mapdrawingareaframe.h"
#include "editor.h"
#include "../../common/smartpointer/referencecountptr.h"

int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);

    ReferenceCountPtr<Editor> editor = new Editor();

    Gtk::Window window;
    Gtk::HBox box;
    Gtk::Notebook notebook;
    ContinentPage continentPage(editor);
    CountryPage countryPage(editor);
	GameCardPage gameCardPage(editor);

    MapDrawingAreaFrame mapDrawingArea(editor);
    mapDrawingArea.loadImage("mapa.jpg");

    notebook.append_page(continentPage, "CONTINENTES");
    notebook.append_page(countryPage, "PAISES");
	notebook.append_page(gameCardPage, "CARTAS DE JUEGO");

    box.pack_start(mapDrawingArea, Gtk::PACK_EXPAND_WIDGET);
    box.pack_start(notebook, Gtk::PACK_SHRINK);

    window.add(box);
    window.show_all_children();
    window.maximize();

    Gtk::Main::run(window);

    return 0;
}

