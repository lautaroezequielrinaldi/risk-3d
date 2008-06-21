#include "imagedrawingarea.h"

ImageDrawingArea::ImageDrawingArea():
    Gtk::DrawingArea(),
    imageContext(),
    imageSurface(),
    image(),
    imageLoaded(false) {
    // No realiza ninguna acciòn.
}

bool ImageDrawingArea::on_expose_event(GdkEventExpose* event) {
    // Si la imagen no se cargo retorna.
    if (!imageLoaded) {
        return true;
    }
    // Crea el contexto para el widget.
    Cairo::RefPtr<Cairo::Context> context =
        this->get_window()->create_cairo_context();
    // Selecciona el rectangulo a modificar.
    context->rectangle(event->area.x, event->area.y,
        event->area.width, event->area.height);
    context->clip();
    // Almacena el contenido del contexto.
    context->save();
    // Dibuja la imagen en el contexto del widget.
    context->set_source(this->imageSurface, 0.0, 0.0);
    context->rectangle(0.0, 0.0, this->image->get_width(),
        this->image->get_height());
    context->clip();
    context->paint();
    // Restaura el contenido del contexto.
    context->restore();
    // Retorna.
    return true;
}

void ImageDrawingArea::redraw() {
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

bool ImageDrawingArea::loadImage(const std::string& imageFileName) {
    // Cargo la imagen.
    this->image = Gdk::Pixbuf::create_from_file(imageFileName);
    // Verifico si se cargo la imagen.
    if (image) {
        // Detecta colores transparentes para la imagen cargada.
        Cairo::Format format = Cairo::FORMAT_RGB24;
        if (this->image->get_has_alpha()) {
            format = Cairo::FORMAT_ARGB32;
        }
        // Crea una nueva superficie para la imagen.
        this->imageSurface = Cairo::ImageSurface::create(format,
            this->image->get_width(), this->image->get_height());
        // Crea el contexto de la superficie.
        this->imageContext = Cairo::Context::create(this->imageSurface);
        // Dibuja la imagen en el contexto de la imagen.
        Gdk::Cairo::set_source_pixbuf(this->imageContext, this->image, 0.0,
            0.0);
        this->imageContext->paint();

        // Establece el tamaño minimo del widget.
        this->set_size_request(this->image->get_width(),
            this->image->get_height());
        // Marca la imagen como cargada.
        this->imageLoaded = true;
        // Redibuja el widget.
        this->redraw();
        // Retorna.
        return true;
    } else {
        // Retorna.
        return false;
    }
}

ImageDrawingArea::~ImageDrawingArea() {
    // No realiza ninguna acciòn.
}

