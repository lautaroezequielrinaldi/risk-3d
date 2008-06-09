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
    // Verifico si esta asociado a un editor
    if (this->editor != NULL) {
        // Creo un label para pedirle el nombre del pais al usuario.
        Gtk::Label countryNameLabel("Nombre de Pais:");
        // Creo un etry para pedirle el nombre del pais al usuario.
        Gtk::Entry countryNameEntry;
        // Creo el dialogo.
        Gtk::Dialog dialog("Agregar pais");
        // Agrego el label al dialogo.
        dialog.get_vbox()->add(countryNameLabel);
        // Agrego el entry al dialogo.
        dialog.get_vbox()->add(countryNameEntry);
        // Agrego el boton de OK al dialogo.
        dialog.add_button(Gtk::Stock::OK, Gtk::RESPONSE_OK);
        // Agrego el boton de CANCEL al dialogo.
        dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
        // Muestro el label.
        countryNameLabel.show();
        // Muestro el entry.
        countryNameEntry.show();
        // Muestro el dialogo.
        int result = dialog.run();
        // Proceso resultado de dialogo.
        if (result == Gtk::RESPONSE_OK) {
            // Creo una nuva posicion de mapa.
            MapPosition position((int) event->x, (int) event->y);
            // Obtengo nombre de pais.
            std::string countryName = countryNameEntry.get_text();
            // Creo un nuevo pais.
            ReferenceCountPtr<Pais> pais = new Pais(countryName, position);
            // Agrego pais al mapa.
            this->editor->getMapa()->agregarPais(pais);
            // Notifico que el editor cambio.
            this->editor->notify();
        }
    }
    return true;
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

