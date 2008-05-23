#ifndef __MESSAGEFACTORY__
#define __MESSAGEFACTORY__

#include "attackfactory.h"
#include "chatcommandfactory.h"
#include "defendfactory.h"
#include "initfactory.h"
#include "joinfactory.h"
#include "keepalivefactory.h"
#include "losefactory.h"
#include "mapreceivefactory.h"
#include "mapsendfactory.h"
#include "commandfactoryfactory.h"
#include "commandfactory.h"
#include "populatefactory.h"
#include "surrenderfactory.h"
#include "turntoattackfactory.h"
#include "turntodefendfactory.h"
#include "turntopopulatefactory.h"
#include "winfactory.h"

#include "commandfactory.h"
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
