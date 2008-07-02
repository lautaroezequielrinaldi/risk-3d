
#include "proxy.h"
#include <sstream>
#include <iostream>

Proxy::Proxy(const ReferenceCountPtr<Socket>&  socket): socket(socket) {
}

ReferenceCountPtr<Socket> Proxy::getSocket() {
    return socket;
}

Proxy::~Proxy(){
}

