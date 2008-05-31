#include "mapdrawingareaframe.h"

MapDrawingAreaFrame::MapDrawingAreaFrame(
    const ReferenceCountPtr<Editor>& editor):
    Gtk::Frame(),
    editor(editor),
    scrolledWindow(),
    eventBox(),
    mapDrawingArea(editor) {

    // Agrega el area de dibujo del mapa al event box.
    this->eventBox.add(this->mapDrawingArea);
    // Agrega el event box al scrolled window.
    this->scrolledWindow.add(this->eventBox);
    // Agrega el scrolled window al frame.
    this->add(this->scrolledWindow);

    // Asocia el la señal signal_button_press_event con el manejador
    // de eventos
    this->eventBox.set_events(Gdk::BUTTON_PRESS_MASK);
    this->eventBox.signal_button_press_event().connect(
        sigc::mem_fun(*this, &MapDrawingAreaFrame::onMapDrawingAreaPressed) );
}

bool MapDrawingAreaFrame::onMapDrawingAreaPressed(GdkEventButton* event) {

}

void MapDrawingAreaFrame::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;

    // Establezco el editor en el area de dibujo del frame.
    this->mapDrawingArea.setEditor(editor);
}

ReferenceCountPtr<Editor>& MapDrawingAreaFrame::getEditor() {
    return this->editor;
}

void MapDrawingAreaFrame::loadImage(const std::string& imageFileName) {
    this->mapDrawingArea.loadImage(imageFileName);
}

MapDrawingAreaFrame::~MapDrawingAreaFrame() {
    // No realiza ninguna acciòn.
}

