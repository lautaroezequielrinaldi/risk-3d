#ifndef __VIEWCONTINENTCOUNTRIESFRAME_H__
#define __VIEWCONTINENTCOunTRIESFRAME_H__

#include<gtkmm/frame.h> // Para definiciòn de Gtk::Frame.
#include<gtkmm/box.h> // Para definiciòn de Gtk::VBox.
#include<gtkmm/liststore.h> // Para definiciòn de Gtk::ListStore.
#include<gtkmm/treeview.h> // Para definiciòn de Gtk::TreeView.
#include<gtkmm/combobox.h> // Para definiciòn de Gtk::ComboBox.
#include<glibmm/refptr.h> // Para definiciòn de Glib::RefPtr.

#include "continentcolumns.h" // Para definiciòn de ContinentColumns.
#include "countrycolumns.h" // Para definiciòn de CountryColumns.

#include "observer.h" // Para definiciòn de Observer.
#include "subject.h" // Para definiciòn de Subject.
#include "editor.h" // Para definiciòn de Editor.
#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es mostrar un frame donde el usuario puede seleccionar.
 * un continente para luego visualizar en una grilla los paises que contiene
 * dicho continente.
 */
class ViewContinentCountriesFrame: public Observer, public Gtk::Frame {
    /**
     * Atributos privados de la clase ViewContinentCountriesFrame.
     */
    private:
        /**
         * Almacena el editor desde el cual se van a tomar los datos.
         */
        ReferenceCountPtr<Editor> editor;
        /**
         * Almacena el vertical layout sobre el cual se van a agregar los demas widgets.
         */
        Gtk::VBox verticalBox;
        /**
         * Almacena el registro de columnas usado para la lista de continentes.
         */
        ContinentColumns continentColumns;
        /**
         * Almacena el registro de columnas usado para la lista de paises.
         */
        CountryColumns countryColumns;
        /**
         * Almacena el modelo de tree usado para la lista de continentes.
         */
        Glib::RefPtr<Gtk::ListStore> continentTreeModel;
        /**
         * Almacena el modelo de tree usado para la lista de paises.
         */
        Glib::RefPtr<Gtk::ListStore> countryTreeModel;
        /**
         * Almacena el combobox usado para la lista de continentes.
         */
        Gtk::ComboBox continentComboBox;
        /**
         * Almacena el tree view usado para la lista de paises.
         */
        Gtk::TreeView countryTreeView;

    /**
     * Mètodos privados de la clase ViewContinentCountriesFrame.
     */
    private:
        /**
         * Constructor copia de la clase ViewContinentCountriesFrame.
         */
        ViewContinentCountriesFrame(
            const ViewContinentCountriesFrame& otherInstance);
        /**
         * Operador de asignaciòn de la clase ViewContinentCountriesFrame.
         */
        ViewContinentCountriesFrame& operator=(
            const ViewContinentCountriesFrame& otherInstance);
        /**
         * Inicializa el modelo de tree usado para la lista de continentes.
         */
        void initializeContinentTreeModel();
        /**
         * Inicializa el modelo de tree usado para la lista de paises.
         */
        void initializeCountryTreeModel();
        /**
         * Inicializa el combobox usdo para la lista de continentes,
         */
        void initializeContinentComboBox();
        /**
         * Inicializa el tree view usado para la lista de paises.
         */
        void initializeCountryTreeView();
        /**
         * Popula la lista de continentes.
         */
        void populateContinentComboBox();
        /**
         * Popula la lista de paises.
         */
        void populateCountryTreeView();
        /**
         * Popula la lista de continentes y la lista de paises.
         */
        void populate();
        /**
         * Manejador del signal_changed de la lista de continentes.
         */
        void onContinentComboBoxChanged();
    /**
     * Mètodos pùblicos de la clase ViewContinentCountriesFrame.
     */
    public:
        /**
         *  Constructor de la clase ViewContinentCountriesFrame.
         */
        ViewContinentCountriesFrame(
            const ReferenceCountPtr<Editor>& editor = NULL);
        /**
         * Establece el editor desde el cual se van a tomar los datos.
         */
        void setEditor(const ReferenceCountPtr<Editor>& editor);
        /**
         * Obtiene el editor desde el cual se van a tomar los datos.
         */
        ReferenceCountPtr<Editor>& getEditor();
        /**
         * 
         */
        void update(Subject* subject);
        /**
         * Destructor virtual de la clase ViewContinentCountriesFrame.
         */
        virtual ~ViewContinentCountriesFrame();
};

#endif /** __VIEWCONTINENTCOUNTRIESFRAME_H__ */

