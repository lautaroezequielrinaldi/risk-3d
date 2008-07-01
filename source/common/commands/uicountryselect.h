#ifndef __UICOUNTRYSELECT_H__
#define __UICOUNTRYSELECT_H__

/**
 * client => server => client
 */

#include "uicommand.h"
class UICountrySelect: public UICommand {
	public:

		UICountrySelect(std::vector<std::string> &parameterList);
		UICountrySelect();
		virtual ~UICountrySelect();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		/**
		 * Metodo cuyo proposito es validar la accion que realice el comando.
		 */
		bool validate(ReferenceCountPtr<GameManager>& gameManager);
		virtual void execute(ReferenceCountPtr<State>& state);
		

		virtual std::string getName();


};

#endif /* __UICOUNTRYSELECT_H__*/
