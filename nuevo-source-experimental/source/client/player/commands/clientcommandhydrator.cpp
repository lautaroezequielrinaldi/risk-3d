#include "clientcommandhydrator.h"
#include<iostream>

ClientCommandHydrator::ClientCommandHydrator(const ReferenceCountPtr<Game>& game): game(game) {
    std::cerr << "Inicializando a ClientCommandHydrator..." << std::endl;
    clientCommandList.insert(std::make_pair("battleResult",
        new BattleResultClientCommand(this->game)));
    clientCommandList.insert(std::make_pair("move",
        new MoveClientCommand(this->game)));
    clientCommandList.insert(std::make_pair("pupulate",
        new PopulateClientCommand(this->game)));
    clientCommandList.insert(std::make_pair("surrender",
        new SurrenderClientCommand(this->game)));
    clientCommandList.insert(std::make_pair("quit",
        new QuitClientCommand(this->game)));
    std::cerr << "Lista de comandos inicializada..." << std::endl;
}

bool ClientCommandHydrator::isClientCommand(const std::string& commandName) {
    std::cerr << "Definiendo iterador para iterar mapa de comandos..." << std::endl;
    std::map<std::string, ReferenceCountPtr<ClientCommand> >::iterator iter;

    std::cerr << "Buscando tipo de comando " << commandName << " en mapas de comandos..." << std::endl;
    iter = clientCommandList.find(commandName);
    std::cerr << "Comando buscado..." << std::endl;
    if (iter == clientCommandList.end()) {
        std::cerr << "Comando no encontrado..." << std::endl;
        return false;
    } else {
        std::cerr << "Comando encontrado..." << std::endl;
        return true;
    }
}

ReferenceCountPtr<ClientCommand> ClientCommandHydrator::createCommand(const std::string& commandName, const std::string& xml) {
    std::cerr << "Buscando comando " << commandName << " en lista de comandos..." << std::endl;
    ReferenceCountPtr<ClientCommand> prototype = clientCommandList[commandName];

    std::cerr << "Verificando que se encontro comando..." << std::endl;
    if (prototype != NULL) {
        std::cerr << "Se encontro comando..." << std::endl;
        std::cerr << "Clonando comando..." << std::endl;
        ReferenceCountPtr<ClientCommand> command =  prototype->clone();
        std::cerr << "Comando clonado..." << std::endl;
        std::cerr << "Hidratando comando con el XML: " << xml << std::endl;
        command->hydrate(xml);
        std::cerr << "Comando hidratado..." << std::endl;
        std::cerr << "Realizando static cast de ReferenceCountPtr<Serializable> a ReferenceCountPtr<ClientCommand>..." << std::endl;
        return command;
    } else {
        std::cerr << "No se encontro comando, devuelvo null..." << std::endl;
        return NULL;
    }
}

ClientCommandHydrator::~ClientCommandHydrator() {
    // No realiza ninguna accion.
}

