#include "mapdrawingarea.h"

MapDrawingArea::MapDrawingArea(const ReferenceCountPtr<Editor>& editor):
    Observer(),
    ImageDrawingArea(),
    editor(editor) {

    // Se agrega como observer del editor.
    if (this->editor != NULL) {
        this->editor->registerObserver(this);
    }

    // Conecta la señal signal_button_press_event al mètodo
    // on_click_event del map drawing area.
    this->set_events(Gdk::BUTTON_PRESS_MASK);
    this->signal_button_press_event().connect(
        sigc::mem_fun(*this, &MapDrawingArea::onClicked) );
}

bool MapDrawingArea::on_expose_event(GdkEventExpose* event) {
    // Invoca al manejador de eventos on_expose_event de la clase padre.
    ImageDrawingArea::on_expose_event(event);
    // Obtengo la ventana del widget.
    Glib::RefPtr<Gdk::Window> window = this->get_window();
    // Obtengo el contexto cairo sobre el cual dibujar.
    Cairo::RefPtr<Cairo::Context> context = window->create_cairo_context();

    // Verifico si esta asociado a un editor.
    if (this->editor != NULL && this->editor->getMapa() != NULL) {
        // Obtengo el mapa del editor
        ReferenceCountPtr<Mapa> map = editor->getMapa();
        // Defino iterador de paises del mapa.
        Mapa::IteradorPais countryIter;

        // Itero por cada pais
        for (countryIter = map->primerPais();
            countryIter != map->ultimoPais(); ++countryIter) {
            // Obtengo pais actual.
            ReferenceCountPtr<Pais> country = *countryIter;
            // Obtengo la posicion del pais dentro del mapa.
            MapPosition position = country->getPosition();
            
            // Dibujo un circulo en dicha posicion.
            context->save();
            context->set_source_rgb(0.8, 0.0, 0.0);
            context->arc(position.getX(), position.getY(), 10.0, 0.0, 2* M_PI);
            context->fill_preserve();
            context->restore();
            context->stroke();
        }

        for (countryIter = map->primerPais();
            countryIter != map->ultimoPais(); ++countryIter) {
            // Obtengo el pais actual.
            ReferenceCountPtr<Pais> country = *countryIter;
            // Obtengo la posicion del pais dentro del mapa.
            MapPosition position = country->getPosition();

            // Defino iterador de paises adaycentes.
            Pais::Iterador adyacentIter;
            // Itero por cada pais adyacente.
            for (adyacentIter = country->primerAdyacente(); 
                adyacentIter != country->ultimoAdyacente(); ++adyacentIter) {
                // Obtengo  pais adyacente actual.
                ReferenceCountPtr<Pais> adyacent = *adyacentIter;
                // Obtengo la posiciòn del pais adyacente dentro del mapa.
                MapPosition adyacentPosition = adyacent->getPosition();
                // Dibujo linea que une ambos paises,
                context->save();
                context->move_to(position.getX(), position.getY());
                context->line_to(adyacentPosition.getX(),
                    adyacentPosition.getY());
                context->restore();
                context->stroke();
            }
        }
    }
    return true;
}

bool MapDrawingArea::onClicked(GdkEventButton* event) {
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

void MapDrawingArea::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;

    // Se agrega como observer del editor.
    if (this->editor != NULL) {
        this->editor->registerObserver(this);
    }

    // Redibuja el mapa con la informaciòn del nuevo editor.
    this->redraw();
}

ReferenceCountPtr<Editor>& MapDrawingArea::getEditor() {
    return this->editor;
}

void MapDrawingArea::update(Subject* subject) {
    this->redraw();
}

MapDrawingArea::~MapDrawingArea() {
    // No realiza ninguna acciòn.
}

