#ifndef __ADDCONTINENTFRAME_H__
#define __ADDCONTINENTFRAME_H__

#include<gtkmm/frame.h> // Para definiciòn de Gtk::Frame.
#include<gtkmm/box.h> // Para definiciòn de Gtk::HBox y Gtk::VBox.
#include<gtkmm/label.h> // Para definiciòn de Gfk::Label.
#include<gtkmm/entry.h> // Para definiciòn de Gtk::Entry.
#include<gtkmm/spinbutton.h> // Para definiciòn de Gtk::SpinButton.
#include<gtkmm/button.h> // Para definiciòn de Gtk::Button.

#include "editor.h" // Para definiciòn de Editor.
#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPtr.

/**
 * Clase cuyo propòsito es mostrar un frame donde el usuario puede agregar un
 * continente al mapa, indicando nombre y bonus.
 */
class AddContinentFrame: public Gtk::Frame {
    /**
     * Atributos privados de la clase AddContinentFrame.
     */
    private:
        /**
         * Almacena el editor al cual le voy a agregar el continente.
         */
        ReferenceCountPtr<Editor> editor;
        /**
         * Almacena el box vertical donde se agregaràn los demas controles.
         */
        Gtk::VBox verticalBox;
        /**
         * Almacena el box horizontal donde se agregarà el label y el entry
         * para ingresar el nombre del continente.
         */
        Gtk::HBox continentNameBox;
        /**
         * Almacena el box horizontal donde se agregarà el label y el entry
         * para ingresar el boton del continente.
         */
        Gtk::HBox continentBonusBox;
        /**
         * Almacena el box horizontal donde se agregaràn los botones de agregar
         * continente y resetear continente.
         */
        Gtk::HBox continentButtonBox;
        /**
         * Almacena el label para indicar al usuario que ingrese nombre del
         * continente.
         */
        Gtk::Label continentNameLabel;
        /**
         * Almacena el entry donde el usuario ingresarà el nombre del
         * continente.
         */
        Gtk::Entry continentNameEntry;
        /**
         * Almacena el label para indicar al usuario que ingrese el bonus del
         * continente.
         */
        Gtk::Label continentBonusLabel;
        /**
         * Almacena el entry donde el usuario ingresarà el bonus del continente.
         */
        Gtk::SpinButton continentBonusEntry;
        /**
         * Almacenarà el botòn para aceptar el ingreso del continente.
         */
        Gtk::Button addContinentButton;
        /**
         * Almacenarà el botòn para resetear el ingreso del continente.
         */
        Gtk::Button resetContinentButton;

    /**
     * Mètodos privados de la clase AddContinentFrame.
     */
    private:
        /**
         * Constructor copia de la clase AddContinentFrame.
         */
        AddContinentFrame(const AddContinentFrame& otherInstance);
        /**
         * Operador de asignaciòn de la clase AddContinentFrame.
         */
        AddContinentFrame& operator=(const AddContinentFrame& otherInstance);

        /**
         * Manejador de la señal signal_clicked del boton addContinentButton.
         */
        void onAddContinentButtonClicked();
        /**
         * Manejador de la señal signal_clicked del boton resetContinentButton.
         */
        void onResetContinentButtonClicked();

    /**
     * Mètodos pùblicos de la clase AddContinentFrame.
     */
    public:
        /**
         * Constructor de la clase AddContinentFrame.
         */
        AddContinentFrame();
        /**
         * Establece el editor al cual va agregar un continente.
         */
        void setEditor(const ReferenceCountPtr<Editor>& editor);
        /**
         * Obtiene el editor al cual va agregar un continente.
         */
        ReferenceCountPtr<Editor>& getEditor();
        /**
         * Destructor virtual de la clase AddContinentFrame.
         */
        virtual ~AddContinentFrame();
};

#endif /** __ADDCONTINENTFRAME_H__ */

