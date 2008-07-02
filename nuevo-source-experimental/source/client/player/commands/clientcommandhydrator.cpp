#include "clientcommandhydrator.h"

ClientCommandHydrator::ClientCommandHydrator(const ReferenceCountPtr<Game>& game): game(game) {
    clientCommandList.insert(std::make_pair("battleResult", new BattleResultClientCommand(this->game)));
    clientCommandList.insert(std::make_pair("move", new MoveClientCommand(this->game)));
    clientCommandList.insert(std::make_pair("pupulate", new PopulateClientCommand(this->game)));
    clientCommandList.insert(std::make_pair("surrender", new SurrenderClientCommand(this->game)));
    clientCommandList.insert(std::make_pair("quit", new QuitClientCommand(this->game)));
}

bool ClientCommandHydrator::isClientCommand(const std::string& commandName) {
    std::map<std::string, ReferenceCountPtr<ClientCommand> >::iterator iter;

    iter = clientCommandList.find(commandName);
    if (iter == clientCommandList.end()) {
        return false;
    } else {
        return true;
    }
}

ReferenceCountPtr<ClientCommand> ClientCommandHydrator::createCommand(const std::string& commandName, const std::string& xml) {
    ReferenceCountPtr<ClientCommand> prototype = clientCommandList[commandName];

    ReferenceCountPtr<Serializable> command =  prototype->clone();
    command->hydrate(xml);
    return static_cast<ReferenceCountPtr<ClientCommand> >(command);
}

ClientCommandHydrator::~ClientCommandHydrator() {
    // No realiza ninguna accion.
}

