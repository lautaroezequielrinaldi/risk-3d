#ifndef __VIEWCONTINENTSFRAME_H__
#define __VIEWCONTINENTSFRAME_H__

#include<gtkmm/frame.h> // Para definiciòn de Gtk::Frame.
#include<gtkmm/treemodel.h> // Para definiciòn de Gtk::TreeModel.
#include<gtkmm/treeview.h> // Para definiciòn de Gtk::View.
#include<glibmm/refptr.h> // Para definiciòn de Glib::RefPtr.

#include "observer.h" // Para definiciòn de Observer.
#include "subject.h" // Para definiciòn de Subject.
#include "editor.h" // Para definiciòn de Editor.
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
         * Almacena el modelo de tree usado para la lista de continentes.
         */
        Glib::RefPtr<Gtk::TreeModel> treeModel;
        /**
         * Almacena la vista de tree usado para la lista de continentes.
         */
        Gtk::TreeView treeView;

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
     * Mètodos pùblicos de la clase ViewContinentesFrame.
     */
    public:
        /**
         * Constructor de la clase ViewContinentsFrame.
         */
        ViewContinentsFrame();
        /**
         * Constructor de la clase ViewContinentsFrame.
         */
        ViewContinentsFrame(const ReferenceCountPtr<Editor>& editor);
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
        void update(const Subject* subject);
        /**
         * Destructor virtual de la clase ViewContinentsFrame.
         */
        virtual ~ViewContinentsFrame();
};

        
#endif /** __VIEWCONTINETNSFRAME_H__ */

