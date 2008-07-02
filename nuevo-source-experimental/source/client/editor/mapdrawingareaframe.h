#ifndef __MAPDRAWINGAREAFRAME_H__
#define __MAPDRAWINGAREAFRAME_H__

#include<string> // Para definiciòn de std::string.
#include<gtkmm/frame.h> // Para definiciòn de Gtk::Frame.
#include<gtkmm/scrolledwindow.h> // Para definiciòn de Gtk::ScrolledWindow.
#include<gtkmm/eventbox.h> // Para definiciòn de Gtk::EventBox
#include<gdk/gdkevents.h> // Para definiciòn de GdkEventButton.

#include "mapdrawingarea.h" // Para definiciòn de MapDrawingArea.

#include "editor.h" // Para definiciòn de Editor.
#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es encapsular a un frame que contiene un area de dibujo
 * del mapa para añadirle scroll bars en caso de ser necesario y capturar los
 * eventos de mouse sobre el drawing area.
 */
class MapDrawingAreaFrame: public Gtk::Frame {
    /**
     * Atributos privados de la clase MapDrawingAreaFrame.
     */
    private:
        /**
         * Almacena el editor usado para tomar los datos a mostrar.
         */
        ReferenceCountPtr<Editor> editor;
        /**
         * Almacena el scrolled window usado para poner barras de scroll
         * al area de dibujo del mapa.
         */
        Gtk::ScrolledWindow scrolledWindow;
        /**
         * Almacena el event box usado para detectar eventos de click sobre
         * el area de dibujod el mapa.
         */
        Gtk::EventBox eventBox;
        /**
         * Almacena el area de dibujo del mapa.
         */
        MapDrawingArea mapDrawingArea;

    /**
     * Mètodos privados de la clase MapDrawingAreaFrame.
     */
    private:
        /**
         * Constructor copia de la clase MapDrawingAreaFrame.
         */
        MapDrawingAreaFrame(const MapDrawingAreaFrame& otherInstance);
        /**
         * Operador de asignaciòn de la clase MapDrawingAreaFrame.
         */
        MapDrawingAreaFrame& operator=(
            const MapDrawingAreaFrame& otherInstance);
        /**
         * Manejador de la señal signal_pressed del eventbox.
         */
        bool onMapDrawingAreaPressed(GdkEventButton* event);

    /**
     * Mètodos pùblicos de la clase MapDrawingAreaFrame.
     */
    public:
        /**
         * Constructor de la clase MapDrawingAreaFrame.
         */
        MapDrawingAreaFrame(const ReferenceCountPtr<Editor>& editor = NULL);
        /**
         * Establece el editor del cual va a tomar los datos a mostrar.
         */
        void setEditor(const ReferenceCountPtr<Editor>& editor);
        /**
         * Obtiene el editor del cual va a tomar los datos a mostrar.
         */
        ReferenceCountPtr<Editor>& getEditor();
        /**
         * Carge en el area de dibujo del mapa la imagen del mapa a mostrar.
         */
        void loadImage(const std::string& imageFileName);
        /**
         * Destructor virtual de la clase MapDrawingAreaFrame.
         */
        virtual ~MapDrawingAreaFrame();
};

        
#endif /** __MAPDRAWINGAREAFRAME_H__ */

