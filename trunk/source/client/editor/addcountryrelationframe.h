#ifndef __ADDCOUNTRYRELATIONFRAME_H__
#define __ADDCOUNTRYRELATIONFRAME_H__

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
 * Clase cuyo propòsito es mostrar un frame con controles para que el usuario
 * seleccione dos paises y agregue una relacion de adyacencia entre ambos.
 */
class AddCountryRelationFrame: public Observer, public Gtk::Frame {
    /**
     * Atributos privados de la clase AddCountryRelationFrame.
     */
    private:
        /**
         * Almacena el editor del cual tomar todos los datos.
         */
        ReferenceCountPtr<Editor> editor;
        /**
         * Almacena el vertical box donde se colocaràn los widgets.
         */
        Gtk::VBox verticalBox;
        /**
         * Almacena el registro de columnas usado para la lista de paises.
         */
        CountryColumns countryColumns;
        /**
         * Almacena el modelo de tree para el primer combo de pais.
         */
        Glib::RefPtr<Gtk::ListStore> firstCountryTreeModel;
        /**
         * Almacena el modelo de tree par el segundo combo de pais.
         */
        Glib::RefPtr<Gtk::ListStore> secondCountryTreeModel;
        /**
         * Almacena el label para el primer pais.
         */
        Gtk::Label firstCountryLabel;
        /**
         * Almacena el label para el segundo pais.
         */
        Gtk::Label secondCountryLabel;
        /**
         * Almacena el combo box para el primer pais.
         */
        Gtk::ComboBox firstCountryComboBox;
        /**
         * Almacena el combo box para el segundo pais.
         */
        Gtk::ComboBox secondCountryComboBox;
        /**
         * Almacena el boton de agregar relacion.
         */
        Gtk::Button addRelationButton;

    /**
     * Mètodos privados de la clase AddCountryRelationFrame.
     */
    private:
        /**
         * Constructor copia de la clase AddCountryRelationFrame.
         */
        AddCountryRelationFrame(const AddCountryRelationFrame& otherInstance);
        /**
         * Operador de asignaciòn de la clase AddCountryRelationFrame.
         */
        AddCountryRelationFrame& operator=(
            const AddCountryRelationFrame& otherInstance);
        /**
         * Inicializa el modelo de tree para el primer pais.
         */
        void initializeFirstCountryTreeModel();
        /**
         * Inicializa el modelo de tree para el segundo pais.
         */
        void initializeSecondCountryTreeModel();
        /**
         * Inicializa el combo box para el primer pais.
         */
        void initializeFirstCountryComboBox();
        /**
         * Inicializa el combo box para el segundo pais.
         */
        void initializeSecondCountryComboBox();
        /**
         * Popula la lista de paises con datos del editor.
         */
        void populate();

        /**
         * Manejador de la señal signal_clicked del boton addRelationButton.
         */
        void onAddRelationButtonClicked();

    /**
     * Mètodos pùblicos de la clase AddCountryRelationFrame.
     */
    public:
        /**
         * Constructor de la clase AddCountryRelationFrame.
         */
        AddCountryRelationFrame(const ReferenceCountPtr<Editor>& editor);
        /**
         * Establece el editor usado para tomar los datos.
         */
        void setEditor(const ReferenceCountPtr<Editor>& editor);
        /**
         * Obtiene el editor usado para tomar los  datos.
         */
        ReferenceCountPtr<Editor>& getEditor();
        /**
         * Se actualiza con los cambios del editor.
         */
        void update(Subject* subject);
        /**
         * Destructor virtual de la clase AddCountryRelationFrame.
         */
        virtual ~AddCountryRelationFrame();
};

#endif /** __ADDCOUNTRYRELATIONFRAME_H__ */

