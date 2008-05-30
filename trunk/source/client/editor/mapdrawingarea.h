#ifndef __MAPDRAWINGAREA_H__
#define __MAPDRAWINGAREA_H__

#include<gdk/gdkevents.h> // Para definiciòn de GdkEventExpose.

#include "imagedrawingarea.h" // Para definiciòn de ImageDrawingArea.
#include "editor.h" // Para definiciòn de Editor.
#include "subject.h" // Para definiciòn de Subject.
#include "observer.h" // Para definiciòn de Observer.
#include "../../common/model/mapa.h" // Para definiciòn de Mapa.

/**
 * Clase que representa un area dibujable en pantalla donde se muestra la imagen
 * del mapa y sobre ella se dibuja informacion relacionada con el mapa.
 */
class MapDrawingArea: public Observer, public ImageDrawingArea {
    /**
     * Atributos privados de la clase MapDrawingArea.
     */
    private:
        /**
         * Almacena el editor del cual va a tomar los datos a mostrar.
         */
        ReferenceCountPtr<Editor> editor;
    /**
     * Mètodos privados de la clase MapDrawingArea.
     */
    private:
        /**
         * Constructor copia de la clase MapDrawingArea.
         */
        MapDrawingArea(const MapDrawingArea& otherInstance);
        /**
         * Operador de asignaciòn de la clase MapDrawingArea.
         */
        MapDrawingArea& operator=(const MapDrawingArea& otherInstance);

    /**
     * Mètodos protegidos de la clase MapDrawingArea.
     */
    protected:
        /**
         * Dibuja en pantalla la informaciòn del editor.
         */
        bool on_expose_event(GdkEventExpose* event);

    /**
     * Mètodos pùblicos de la clase MapDrawingArea.
     */
    public:
        /**
         * Constructor de la clase MapDrawingArea.
         */
        MapDrawingArea();
        /**
         * Establece el editor de donde tomar los datos a mostrar.
         */
        void setEditor(const ReferenceCountPtr<Editor>& editor);
        /**
         * Obtiene el editor de donde tomar los datos a mostrar.
         */
        ReferenceCountPtr<Editor>& getEditor();
        /**
         *
         */
        void update(Subject* subject);
        /**
         * Destructor virtual de la clase MapDrawingArea.
         */
        virtual ~MapDrawingArea();
};

    
#endif /** __MAPDRAWINGAREA_H__ */

