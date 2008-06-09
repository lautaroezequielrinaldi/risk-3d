#ifndef __CONTINENTPAGE_H__
#define __CONTINENTPAGE_H__

#include<gtkmm/frame.h> // Para definiciòn de Gtk::Frame.
#include<gtkmm/box.h> // Para definiciòn de Gtk::VBox.

#include "addcontinentframe.h" // Para definiciòn de AddContinentFrame.
#include "viewcontinentsframe.h" // Para definiciòn de viewContinentsFrame.
#include "viewcontinentcountriesframe.h" // Para definiciòn de
// ViewContinentCountriesFrame.
#include "editor.h" // Para definiciòn de Editor.

#include "../../common/smartpointer/referencecountptr.h" // Para definiciòn de
// ReferenceCountPTr.

/**
 * Clase cuyo propòsito es mostrar un frame con todos los controles que va
 * mostrar una pagina de un notebook pane.
 */
class ContinentPage: public Gtk::Frame {
    /**
     * Atributos privados de la clase ContinentPage.
     */
    private:
        /**
         * Almacena el layout vertical sobre el cual colocar lo controles.
         */
        Gtk::VBox verticalBox;
        /**
         * Almacena el frame para agregar continentes.
         */
        AddContinentFrame addContinentFrame;
        /**
         * Almacena el frame para ver los continentes.
         */
        ViewContinentsFrame viewContinentsFrame;
        /**
         * Almacena el frame para ver los paises de un continente.
         */
        ViewContinentCountriesFrame viewContinentCountriesFrame;

    /**
     * Mètodos privados de la clase ContinentPage.
     */
    private:
        /**
         * Constructor copia de la clase ContinentPage.
         */
        ContinentPage(const ContinentPage& otherInstance);
        /**
         * Operador de asignacion de la clase ContinentPage.
         */
        ContinentPage& operator=(const ContinentPage& continentPage);

    /**
     * Mètodos pùblicos de la clase ContientPage.
     */
    public:
        /**
         * Constructor de la clase ContinentPage.
         */
        ContinentPage(const ReferenceCountPtr<Editor>& editor);

        /**
         * Establece el editor del cual tomara los datos a mostrar.
         */
        void setEditor(const ReferenceCountPtr<Editor>& editor);

        /**
         * Destructor virtual de la clase ContinentPage.
         */
        virtual ~ContinentPage();
};

#endif /** __CONTINENTPAGE_H__ */

