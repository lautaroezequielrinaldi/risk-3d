#include "mapview.h"

MapView::MapView():
    Gtk::DrawingArea(),
    editor() {
    // No realiza ninguna acciòn.
}

bool MapView::on_expose_event(GdkEventExpose* event) {
    // Aca redibujaria el mapa.
    return true;
}

void MapView::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;
    this->redraw();
}

ReferenceCountPtr<Editor> MapView::getEditor() {
    return this->editor;
}

void MapView::redraw() {
    // Aca redibujaria el mapa.
}

MapView::~MapView() {
    // No realiza ninguna acciòn.
}

