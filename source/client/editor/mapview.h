#ifndef __MAPVIEW_H__
#define __MAPVIEW_H__

#include<gtkmm/drawingarea.h> // Para definiciòn de Gtk::DrawingArea.
#include<gdk/gdk.h> // Para definiciòn de GdkEventExpose.

#include "editor.h" // Para definiciòn de Editor.
#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceConutPtr.

/**
 * Clase cuyo propòsito es encapsular a un Gtk::DrawingArea para dibujar
 * la imagen del mapa y resaltas las ciudades.
 */
class MapView: public Gtk::DrawingArea {
    /**
     * Atributos privados de la clase MapView.
     */
    private:
        /**
         * Almacena el editor del cual va a tomar los datos a dibujar.
         */
        ReferenceCountPtr<Editor> editor;

    /**
     * Mètodos privados de la clase MapView,
     */
    private:
        /**
         * Constructor copia de la clase MapView.
         */
        MapView(const MapView& otherInstance);
        /**
         * Operador de asignaciòn de la clase MapView.
         */
        MapView& operator=(const MapView& otherInstance);

    /**
     * Mètodos protegidos de la clase MapView.
     */
    protected:
        /**
         * Manejador del signal_expose de la clase MapView.
         */
        bool on_expose_event(GdkEventExpose* event);

    /**
     * Mètodos pùblicos de la clase MapView.
     */
    public:
        /**
         * Constructor de la clase MapView.
         */
        MapView();
        /**
         * Establece el editor del cual va a tomar los datos a dibujar.
         */
        void setEditor(const ReferenceCountPtr<Editor>& editor);
        /**
         * Obtiene el editor del cual se va a tomar los datos a dibujar.
         */
        ReferenceCountPtr<Editor> getEditor();
        /**
         * Redibuja el mapa junto con los datos del mapa a dibujar.
         */
        void redraw();
        /**
         * Destructor de la clse MapView.
         */
        ~MapView();
};
 
#endif /** __MAPVIEW_H__ */

