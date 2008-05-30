#ifndef __ADDCOUNTRYTOCONTINENTFRAME_H__
#define __ADDCOUNTRYTOCONTINENTFRAME_H__

#include<gtkmm/frame.h> // Para definiciòn de Gtk::Frame.
#include<gtkmm/box.h> // Para definiciòn de Gtk::VBox.
#include<gtkmm/liststore.h> // Para definiciòn de Gtk::ListStore.
#include<gtkmm/label.h> // Para definiciòn de Gtk::Label.
#include<gtkmm/combobox.h> // Para definiciòn de Gtk::ComboBox.
#include<gtkmm/button.h> // Para definiciòn de Gtk::Button.
#include<glibmm/refptr.h> // Para definiciòn de Glib::RefPtr.

#include "continentcolumns.h" // Para definiciòn de ContinentColumns.
#include "countrycolumns.h" // Para definiciòn de CountryColumns.

#include "observer.h" // Para definiciòn de Observer.
#include "subject.h" // Para definiciòn de Subject.
#include "editor.h" // Para definiciòn de Editor.
#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es mostrar un frame permitiendo al usuario seleccionar un pais y un continente de un combo
 * box para luego relacionarlos entre ellos.
 */
class AddCountryToContinentFrame: public Observer, public Gtk::Frame {
    /**
     * Atributos privados de la clase AddCountryToContinentFrame.
     */
    private:
        /**
         * Almacena el editor del cual se van a tomar los datos a mostrar.
         */
        ReferenceCountPtr<Editor> editor;
        /**
         * Almacena el vertical layout sobre el cual se van agregar los demas widgets.
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
         * Almacena el modelo de tree usado para la lista de continentes.
         */
        Glib::RefPtr<Gtk::ListStore> countryTreeModel;
        /**
         * Almacena el label usado para la lista de continentes.
         */
        Gtk::Label continentLabel;
        /**
         * Almacena el label usado para la lista de paises.
         */
        Gtk::Label countryLabel;
        /**
         * Almacena el combo box usado para la lista de continentes.
         */
        Gtk::ComboBox continentComboBox;
        /**
         * Almacena el combo box usado para la lista de paises.
         */
        Gtk::ComboBox countryComboBox;
        /**
         * Almacena el boton usado para agregar el pais al continente.
         */
        Gtk::Button addButton;

    /**
     * Mètodos privados de la clase AddCountryToContinentFrame.
     */
    private:
        /**
         * Constructor copia de la clase AddCountryToContinentFrame.
         */
        AddCountryToContinentFrame(const AddCountryToContinentFrame& otherInstance);
        /**
         * Operador de asignaciòn de la clase AddCountryToContinentFrame.
         */
        AddCountryToContinentFrame& operator=(const AddCountryToContinentFrame& otherInstance);
        /**
         * Inicializa el modelo de tree  usado para la lista de continentes.
         */
        void initializeContinentTreeModel();
        /**
         * Inicializo el modelo de tree usado para la lista de paises.
         */
        void initializeCountryTreeModel();
        /**
         * Inicializo el combo box usado para la lista de continentes.
         */
        void initializeContinentComboBox();
        /**
         * Inicializo el combo box usado para la lista de paises.
         */
        void initializeCountryComboBox();
        /**
         * Popula la lista de paises y continentes.
         */
        void populate();
        /**
         * Manejador de la señal signal_clicked del boton addButton.
         */
        void onAddButtonClicked();

    /**
     * Mètodos pùblicos de la clase AddCountryToContinentFrame.
     */
    public:
        /**
         * Constructor de la clase AddCountryToContinentFrame.
         */
        AddCountryToContinentFrame();
        /**
         * Establece el editor del cual va a tomar los datos a mostrar.
         */
        void setEditor(const ReferenceCountPtr<Editor>& editor);
        /**
         * Obtiene el editor del cual se va a tomar los datos a mostrar.
         */
        ReferenceCountPtr<Editor>& getEditor();
        /**
         * 
         */
        void update(Subject* subject);
        /**
         * Destructor virtual de la clase AddCountryToContinentFrame.
         */
        virtual ~AddCountryToContinentFrame();
};

#endif /** __ADDCOUNTRYTOCONTINENTFRAME_H__ */

