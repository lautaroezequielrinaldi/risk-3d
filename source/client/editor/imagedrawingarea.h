#ifndef __IMAGEDRAWINGAREA_H__
#define __IMAGEDRAWINGAREA_H__

#include<gtkmm/drawingarea.h> // Para definiciòn de Gtk::DrawingArea.
#include<gdkmm/pixbuf.h> // Para definiciòn de Gdk::Pixbuf.
#include<gdkmm/general.h> // Para definiciòn del namespace Gdk::Cairo.
#include<cairomm/surface.h> // Para definiciòn de Cairo::ImageSurface.
#include<gdk/gdkevents.h> // Para definiciòn de GdkEventExpose.

/**
 * Clase cuyo propòsito es encapsular un drawing area para dibujar una imagen
 * en el mismo y poder dibujar sobre la imagen.
 */
class ImageDrawingArea: public Gtk::DrawingArea {
    /**
     * Atributos privados de la clase ImageDrawingArea.
     */
    private:
        /**
         * Almacena el contexto de la imagen a dibujar.
         */
        Cairo::RefPtr<Cairo::Context> imageContext;
        /**
         * Almacena la sueprficie de la imagen a dibujar.
         */
        Cairo::RefPtr<Cairo::ImageSurface> imageSurface;
        /**
         * Almacena la imagen a dibujar.
         */
        Glib::RefPtr<Gdk::Pixbuf> image;
        /**
         * Almacena flag booleano indicando si la imagen se cargo o no.
         */
        bool imageLoaded;

    /**
     * Mètodos privados de la clase ImageDrawingArea.
     */
    private:
        /**
         * Constructor copia de la clase ImageDrawingArea.
         */
        ImageDrawingArea(const ImageDrawingArea& otherInstance);
        /**
         * Operador de asignacion de la clase ImageDrawingArea.
         */
        ImageDrawingArea& operator=(const ImageDrawingArea& otherInstance);

    /**
     * Mètodos protegidos de la clase ImageDrawingArea.
     */
    protected:
        /**
         * Manejador del evento on_expose_event de la clase ImageDrawingArea.
         */
        virtual bool on_expose_event(GdkEventExpose* event);
        /**
         * Redibuja en pantalla la informaciòn del editor.
         */
        void redraw();

    /**
     * Mètodos pùblicos de la clase ImageDrawingArea.
     */
    public:
        /**
         * Constructor de la clase ImageDrawingArea.
         */
        ImageDrawingArea();
        /**
         * Mètodo cuyo propòsito es cargar una imagen de disco y dibujarla
         * en el mismo.
         */
        bool loadImage(const std::string& imageFileName);
        /**
         * Destructor virtual de la clase ImageDrawingArea.
         */
        virtual ~ImageDrawingArea();
};

#endif /** __IMAGEDRAWINGAREA_H__ */
