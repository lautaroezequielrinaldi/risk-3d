#ifndef __UIQuantitySelect_H__
#define __UIQuantitySelect_H__

/**
 * client => server => client
 */

#include "uicommand.h"
class UIQuantitySelect: virtual public UICommand {
	public:

		UIQuantitySelect(std::vector<std::string> &parameterList);
		UIQuantitySelect();
		virtual ~UIQuantitySelect();

		/**
		 * Metodo cuyo proposito es serializar un objeto y persistirlo a un archivo XML.
		 */
		std::string serialize();

		virtual std::string getName();
};

#endif /* __UIQuantitySelect_H__*/
