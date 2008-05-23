#ifndef __MESSAGEFACTORY__
#define __MESSAGEFACTORY__

#include "CommandFactory.h"
#include "../../common/smartpointer/referencecountptr.h"


#include <map>
#include <string>


class CommandFactoryFactory {
	public:
	CommandFactoryFactory();
	ReferenceCountPtr<CommandFactory> CommandFactoryFactory::build(const std::String& type, const std::String& xml);


	private:
	std::map<std::string,ReferenceCountPtr<CommandFactory> > * list;

};
#endif /*__MESSAGEFACTORY__*/
