#include<gtkmm/main.h>
#include<gtkmm/window.h>
#include<gtkmm/scrolledwindow.h>
#include<gtkmm/viewport.h>
#include<gtkmm/adjustment.h>
#include "addcontinentframe.h"
#include "viewcontinentsframe.h"
#include "viewcontinentcountriesframe.h"
#include "addcountrytocontinentframe.h"
#include "mapdrawingareaframe.h"
#include "editor.h"
#include "../../common/smartpointer/referencecountptr.h"

int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);
    ReferenceCountPtr<Continente> continente = new Continente("ASIA", 15);
    MapPosition position(50,50);
    MapPosition position2(100,100);

    ReferenceCountPtr<Pais> china = new Pais("CHINA", position);
    continente->agregarPais(china);
    ReferenceCountPtr<Pais> birmania = new Pais("BIRMANIA", position2);
    china->agregarAdyacente(birmania);
    birmania->agregarAdyacente(china);

    ReferenceCountPtr<Editor> editor( new Editor());

    editor->getMapa()->agregarContinente(continente);
    editor->getMapa()->agregarPais(china);
    editor->getMapa()->agregarPais(birmania);

    AddContinentFrame addFrame(editor);
    ViewContinentsFrame viewFrame(editor);
    ViewContinentCountriesFrame countryFrame(editor);
    AddCountryToContinentFrame addCountryFrame(editor);
    MapDrawingAreaFrame mapDrawingArea(editor);
    mapDrawingArea.loadImage("/home/pablo/Workspace/risk-3d/mapa.jpg");
    Gtk::Window window;
    Gtk::VBox box;

//    box.add(addFrame);
//    box.add(viewFrame);
//    box.add(countryFrame);
//    box.add(addCountryFrame);
    box.pack_start(mapDrawingArea);

    window.add(box);
    window.show_all_children();
//    window.set_size_request(500,500);
//    window.maximize();

    Gtk::Main::run(window);

    return 0;
}

