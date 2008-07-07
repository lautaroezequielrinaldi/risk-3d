
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
    
    std::cerr << "Proxy::notify() from: " << command.getFrom() << " to: " << command.getTo() << std::endl;
    std::string cmd = command.serialize();
   // std::cerr << "Proxy::notify(" << command.getName() << ") "<<cmd.size() <<" serializado: " << cmd << std::endl;

    std::stringstream header;
    header << cmd.size() << " " << command.getName() << " ";

    std::string msg = header.str();

    // deshardcodear este 30
    while (msg.size() < 30) {
        msg.append(".");
    }

    msg.append("\r\n");
    msg.append(cmd);
    //
    std::cerr << "Proxy::notify socket->write("<< std::endl << msg << std::endl << ")" << std::endl << std::endl;
    //
    socket->write(msg);
    //
   //  std::cerr << "VOLVIO DE ESCRIBIR EN SOCKET: "<<  msg << std::endl;
    
    
}
    
Proxy::~Proxy(){
}

