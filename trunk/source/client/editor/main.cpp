#include<gtkmm/main.h>
#include<gtkmm/window.h>
#include<gtkmm/scrolledwindow.h>
#include<gtkmm/viewport.h>
#include<gtkmm/adjustment.h>
#include "addcontinentframe.h"
#include "viewcontinentsframe.h"
#include "viewcontinentcountriesframe.h"
#include "addcountrytocontinentframe.h"
#include "mapdrawingarea.h"
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

    Gtk::Adjustment vadjustment(30.0, 0.0, 50.0);
    Gtk::Adjustment hadjustment(30.0, 0.0, 50.0);
    Gtk::Viewport viewport(hadjustment, vadjustment);
    Gtk::ScrolledWindow scrolled;

    AddContinentFrame addFrame;
    ViewContinentsFrame viewFrame;
    ViewContinentCountriesFrame countryFrame;
    AddCountryToContinentFrame addCountryFrame;
    MapDrawingArea mapDrawingArea;
    mapDrawingArea.loadImage("/home/pablo/Workspace/risk-3d/mapa.jpg");
    scrolled.add(mapDrawingArea);
    Gtk::Window window;
    Gtk::VBox box;

    //editor->registerObserver(&addFrame);
    editor->registerObserver(&viewFrame);
    editor->registerObserver(&countryFrame);
    editor->registerObserver(&addCountryFrame);
    editor->registerObserver(&mapDrawingArea);

    addFrame.setEditor(editor);
    viewFrame.setEditor(editor);
    countryFrame.setEditor(editor);
    addCountryFrame.setEditor(editor);
    mapDrawingArea.setEditor(editor);

//    box.add(addFrame);
//    box.add(viewFrame);
//    box.add(countryFrame);
//    box.add(addCountryFrame);
    box.pack_start(scrolled);

    window.add(box);
    window.show_all_children();
//    window.set_size_request(500,500);
//    window.maximize();

    Gtk::Main::run(window);

    return 0;
}

