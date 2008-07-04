#ifndef __UICOUNTRYSELECT_H__
#define __UICOUNTRYSELECT_H__

/**
 * client => server => client
 */

#include "uicommand.h"
class UICountrySelect: virtual public UICommand {
	public:

		UICountrySelect(std::vector<std::string> &parameterList);
		UICountrySelect();
		virtual ~UICountrySelect();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		virtual std::string getName();
};

#endif /* __UICOUNTRYSELECT_H__*/
