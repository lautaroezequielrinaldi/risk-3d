#ifndef __UIQuantitySelect_H__
#define __UIQuantitySelect_H__

/**
 * client => server => client
 */

#include "uicommand.h"
class UIQuantitySelect: public UICommand {
	public:

		UIQuantitySelect(std::vector<std::string> &parameterList);
		UIQuantitySelect();
		virtual ~UIQuantitySelect();

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

#endif /* __UIQuantitySelect_H__*/
