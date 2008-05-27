#ifndef __VIEWCONTINENTSFRAME_H__
#define __VIEWCONTINENTSFRAME_H__

#include<gtkmm/frame.h> // Para definiciòn de Gtk::Frame.
#include<gtkmm/liststore.h> // Para definiciòn de Gtk::ListStore.
#include<gtkmm/treeview.h> // Para definiciòn de Gtk::TreeView.
#include<glibmm/refptr.h> // Para definiciòn de Glib::RefPtr.

#include "continentcolumns.h" // Para definiciòn de ContinentColumns.

#include "observer.h" // Para definiciòn de Observer.
#include "subject.h" // Para definiciòn de Subject.
#include "editor.h" // Para definiciòn de Editor.
#include "../../common/model/mapa.h" // Para definiciòn de Mapa.
#include "../../common/model/continente.h" // Para definiciòn de Continente.
#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es mostrar un frame con una lista de continentes en el
 * mapa.
 */
class ViewContinentsFrame: public Observer, public  Gtk::Frame {
    /**
     * Atributos privados de la clase ViewContinentsFrame.
     */
    private:
        /**
         * Almacena el editor del cual va a tomar los datos a mostrar.
         */
        ReferenceCountPtr<Editor> editor;
        /**
         * Almacena el registro de columnas usado para la lista de continentes.
         */
        ContinentColumns continentColumns;
        /**
         * Almacena el modelo de tree usado para la lista de continentes.
         */
        Glib::RefPtr<Gtk::ListStore> continentTreeModel;
        /**
         * Almacena la vista de tree usado para la lista de continentes.
         */
        Gtk::TreeView continentTreeView;

    /**
     * Mètodos privados de la clase ViewContinentesFrame.
     */
    private:
        /**
         * Contructor copia de la clase ViewContientsFrame.
         */
        ViewContinentsFrame(const ViewContinentsFrame& otherInstance);
        /**
         * Operador de asignaciòn de la clse ViewContinentsFrame.
         */
        ViewContinentsFrame& operator=(
            const ViewContinentsFrame& otherInstance);
        /**
         * Inicializa el modelo de la lista de continentes.
         */
        void initializeContinentTreeModel(); 
        /**
         * Inicializa la lista de continentes.
         */
        void initializeContinentTreeView();
        /**
         * Popula la lista de continentes.
         */
        void populate();
    /**
     * Mètodos pùblicos de la clase ViewContinentesFrame.
     */
    public:
        /**
         * Constructor de la clase ViewContinentsFrame.
         */
        ViewContinentsFrame();
        /**
         * Establece el editor del cual va a tomar la lista de continentes.
         */
        void setEditor(const ReferenceCountPtr<Editor>& editor);
        /**
         * Obtiene el editor del cual va a tomar la lista de continentes.
         */
        ReferenceCountPtr<Editor> getEditor();
        /**
         *
         */
        void update(Subject* subject);
        /**
         * Destructor virtual de la clase ViewContinentsFrame.
         */
        virtual ~ViewContinentsFrame();
};

        
#endif /** __VIEWCONTINETNSFRAME_H__ */

