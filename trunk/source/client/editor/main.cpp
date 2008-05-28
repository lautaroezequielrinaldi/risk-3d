#include<gtkmm/main.h>
#include<gtkmm/window.h>
#include "addcontinentframe.h"
#include "viewcontinentsframe.h"
#include "viewcontinentcountriesframe.h"
#include "addcountrytocontinentframe.h"
#include "editor.h"
#include "../../common/smartpointer/referencecountptr.h"

int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);
    ReferenceCountPtr<Continente> continente = new Continente("ASIA", 15);
    ReferenceCountPtr<Pais> china = new Pais("CHINA");
    continente->agregarPais(china);

    ReferenceCountPtr<Editor> editor( new Editor());

    editor->getMapa()->agregarContinente(continente);
    editor->getMapa()->agregarPais(china);

    AddContinentFrame addFrame;
    ViewContinentsFrame viewFrame;
    ViewContinentCountriesFrame countryFrame;
    AddCountryToContinentFrame addCountryFrame;
    Gtk::Window window;
    Gtk::VBox box;

    //editor->registerObserver(&addFrame);
    editor->registerObserver(&viewFrame);
    editor->registerObserver(&countryFrame);
    editor->registerObserver(&addCountryFrame);

    addFrame.setEditor(editor);
    viewFrame.setEditor(editor);
    countryFrame.setEditor(editor);
    addCountryFrame.setEditor(editor);

    box.add(addFrame);
    box.add(viewFrame);
    box.add(countryFrame);
    box.add(addCountryFrame);

    window.add(box);
    window.show_all_children();
    window.maximize();

    Gtk::Main::run(window);

    return 0;
}

