#include<gtkmm/main.h>
#include<gtkmm/window.h>
#include "viewcontinentsframe.h"
#include "editor.h"
#include "../../common/smartpointer/referencecountptr.h"

int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);
    ReferenceCountPtr<Editor> editor( new Editor());
    ViewContinentsFrame frame;
    Gtk::Window window;

    editor->registerObserver((Observer*) &frame);
    frame.setEditor(editor);

    window.add(frame);
    window.show_all_children();
    window.maximize();

    Gtk::Main::run(window);

    return 0;
}

