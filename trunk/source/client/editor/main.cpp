#include<gtkmm/main.h>
#include<gtkmm/window.h>
#include "addcontinentframe.h"
#include "viewcontinentsframe.h"
#include "editor.h"
#include "../../common/smartpointer/referencecountptr.h"

int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);
    ReferenceCountPtr<Editor> editor( new Editor());
    AddContinentFrame addFrame;
    ViewContinentsFrame viewFrame;
    Gtk::Window window;
    Gtk::VBox box;

    //editor->registerObserver(&addFrame);
    editor->registerObserver(&viewFrame);

    addFrame.setEditor(editor);
    viewFrame.setEditor(editor);

    box.add(addFrame);
    box.add(viewFrame);

    window.add(box);
    window.show_all_children();
    window.maximize();

    Gtk::Main::run(window);

    return 0;
}

