#ifndef __ADDCOUNTRYRELATION_H__
#define __ADDCOUNTRYRELATION_H__

/**
 * Clase cuyo propòsito es mostrar un frame con controles para que el usuario
 * seleccione dos paises y agregue una relacion de adyacencia entre ambos.
 */
class AddCountryRelation: public Observer, public Gtk::Frame {
    /**
     * Atributos privados de la clase AddCountryRelation.
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
     * Mètodos privados de la clase AddCountryRelation.
     */
    private:
        /**
         * Constructor copia de la clase AddCountryRelation.
         */
        AddCountryRelation(const AddCountryRelation& otherInstance);
        /**
         * Operador de asignaciòn de la clase AddCountryRelation.
         */
        AddCountryRelation& operator=(const AddCountryRelation& otherInstance);
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
     * Mètodos pùblicos de la clase AddCountryRelation.
     */
    public:
        /**
         * Constructor de la clase AddCountryRelation.
         */
        AddCountryRelation(const ReferenceCountPtr<Editor>& editor) {
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
         * Destructor virtual de la clase AddCountryRelation.
         */
        virtual ~AddCountryRelation();
};

#endif /** __ADDCOUNTRYRELATION_H__ */

