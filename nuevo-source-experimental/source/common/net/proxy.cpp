
#include "proxy.h"
#include "../../common/commands/command.h"
#include <sstream>
#include <iostream>

Proxy::Proxy(const ReferenceCountPtr<Socket>&  socket): socket(socket) {
}

ReferenceCountPtr<Socket> Proxy::getSocket() {
    return socket;
}

void Proxy::notify(Command& command) {
    std::string header;
    std::string message;

    message = command.serialize();
    
    header = message.size() + " " + command.getName();

    getSocket()->write(header.c_str(), header.size());
    getSocket()->write(message.c_str(), message.size());
}
    
Proxy::~Proxy(){
}

