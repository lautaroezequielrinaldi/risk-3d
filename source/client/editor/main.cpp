#include<gtkmm/main.h>
#include<gtkmm/window.h>
#include<gtkmm/scrolledwindow.h>
#include<gtkmm/viewport.h>
#include<gtkmm/adjustment.h>
#include "continentpage.h"
#include "mapdrawingareaframe.h"
#include "editor.h"
#include "../../common/smartpointer/referencecountptr.h"

int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);
    ReferenceCountPtr<Continente> continente = new Continente("ASIA", 15);
    MapPosition position(50,50);
    MapPosition position2(100,100);
    MapPosition position3(400, 200);

    ReferenceCountPtr<Pais> china = new Pais("CHINA", position);
    continente->agregarPais(china);
    ReferenceCountPtr<Pais> birmania = new Pais("BIRMANIA", position2);
    ReferenceCountPtr<Pais> japon = new Pais("JAPON", position3);

    china->agregarAdyacente(birmania);
    birmania->agregarAdyacente(china);
    china->agregarAdyacente(japon);
    japon->agregarAdyacente(china);
    japon->agregarAdyacente(birmania);
    birmania->agregarAdyacente(japon);

    ReferenceCountPtr<Editor> editor = new Editor();

    editor->getMapa()->agregarContinente(continente);
    editor->getMapa()->agregarPais(china);
    editor->getMapa()->agregarPais(birmania);
    editor->getMapa()->agregarPais(japon);

    ContinentPage continentPage(editor);
    MapDrawingAreaFrame mapDrawingArea(editor);
    mapDrawingArea.loadImage("mapa.jpg");
    Gtk::Window window;
    Gtk::HBox box;

    box.add(mapDrawingArea);
    box.add(continentPage);

    window.add(box);
    window.show_all_children();
    window.maximize();

    Gtk::Main::run(window);

    return 0;
}

