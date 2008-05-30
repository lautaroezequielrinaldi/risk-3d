#include "mapdrawingarea.h"
MapDrawingArea::MapDrawingArea():
    Observer(),
    Gtk::DrawingArea(),
    editor() {
    // No realiza ninguna acciòn.
}

bool MapDrawingArea::on_expose_event(GdkEventExpose* event) {
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
        for (countryIter = map->primerPais(); countryIter != map->ultimoPais(); ++countryIter) {
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

        for (countryIter = map->primerPais(); countryIter != map->ultimoPais(); ++countryIter) {
            // Obtengo el pais actual.
            ReferenceCountPtr<Pais> country = *countryIter;
            // Obtengo la posicion del pais dentro del mapa.
            MapPosition position = country->getPosition();

            // Defino iterador de paises adaycentes.
            Pais::Iterador adyacentIter;
            // Itero por cada pais adyacente.
            for (adyacentIter = country->primerAdyacente(); adyacentIter != country->ultimoAdyacente();
                ++adyacentIter) {
                // Obtengo  pais adyacente actual.
                ReferenceCountPtr<Pais> adyacent = *adyacentIter;
                // Obtengo la posiciòn del pais adyacente dentro del mapa.
                MapPosition adyacentPosition = adyacent->getPosition();
                // Dibujo linea que une ambos paises,
                context->save();
                context->move_to(position.getX(), position.getY());
                context->line_to(adyacentPosition.getX(), adyacentPosition.getY());
                context->restore();
                context->stroke();
            }
        }
    }
    return false;
}

void MapDrawingArea::redraw() {
    // Obtengo la ventana de widget.
    Glib::RefPtr<Gdk::Window> window = this->get_window();
    // Si existe ventana.    
    if (window) {
        // Creo un rectangulo del tamaño de la ventana.
        Gdk::Rectangle rectangle(0, 0, this->get_allocation().get_width(),
                    this->get_allocation().get_height());
        // Invalido el rectangulo de la ventana.
        window->invalidate_rect(rectangle, false);
    }
}

void MapDrawingArea::setEditor(const ReferenceCountPtr<Editor>& editor) {
    this->editor = editor;
    this->redraw();
}

ReferenceCountPtr<Editor>& MapDrawingArea::getEditor() {
    return this->editor;
}

void MapDrawingArea::update(Subject* subject) {
    redraw();
}

MapDrawingArea::~MapDrawingArea() {
    // No realiza ninguna acciòn.
}
