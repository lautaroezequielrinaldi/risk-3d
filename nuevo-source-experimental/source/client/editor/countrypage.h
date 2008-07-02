#ifndef __COUNTRYPAGE_H__
#define __COUNTRYPAGE_H__

#include<gtkmm/frame.h> // Para definiciòn de Gtk::Frame.
#include<gtkmm/box.h> // Para definiciòn de Gtk::VBox.

#include "addcountrytocontinentframe.h" // Para definiciòn de AddCountryFrame.
#include "addcountryrelationframe.h" // Para definiciòn de AddCountryRelation.
#include "editor.h" // Para definiciòn de Editor.

#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPTr.

/**
 * Clase cuyo propòsito es mostrar un frame con todos los controles que va
 * mostrar una pagina de un notebook pane.
 */
class CountryPage: public Gtk::Frame {
    /**
     * Atributos privados de la clase CountryPage.
     */
    private:
        /**
         * Almacena el layout vertical sobre el cual colocar lo controles.
         */
        Gtk::VBox verticalBox;
        /**
         * Almacena el frame para agregar paises continentes.
         */
        AddCountryToContinentFrame addCountryToContinentFrame;
        /**
         * Almacena el frame para agregar relaciones entre paises.
         */
        AddCountryRelationFrame addCountryRelationFrame;

    /**
     * Mètodos privados de la clase CountryPage.
     */
    private:
        /**
         * Constructor copia de la clase CountryPage.
         */
        CountryPage(const CountryPage& otherInstance);
        /**
         * Operador de asignacion de la clase CountryPage.
         */
        CountryPage& operator=(const CountryPage& continentPage);

    /**
     * Mètodos pùblicos de la clase ContientPage.
     */
    public:
        /**
         * Constructor de la clase CountryPage.
         */
        CountryPage(const ReferenceCountPtr<Editor>& editor = NULL);

        /**
         * Establece el editor del cual tomara los datos a mostrar.
         */
        void setEditor(const ReferenceCountPtr<Editor>& editor);

        /**
         * Destructor virtual de la clase CountryPage.
         */
        virtual ~CountryPage();
};

#endif /** __COUNTRYPAGE_H__ */

