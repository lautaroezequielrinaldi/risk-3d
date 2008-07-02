#ifndef __PROXY_H__
#define __PROXY_H__

#include "../../common/thread/threaded.h"
#include "../../common/thread/cancelable.h"
#include "../../common/smartpointer/referencecountptr.h"
#include "sockets/socket.h"


class Proxy:public Threaded, public Cancelable {
    /**
     * Atributos privados de la clase Proxy.
     */
	private:
        /**
         * Almacena la referencia al socket activo.
         */
    	ReferenceCountPtr<Socket> socket;
    /**
     * Mètodos protegidos de la clase Proxy.
     */
	protected:
        /**
         * Ejecuta el thread.
         */
    	virtual void * run()=0;
        /**
         * Obtiene el socket asociado con el proxy.
         */
        ReferenceCountPtr<Socket> getSocket();
    /**
     * Metodos publicos de la clse Proxy.
     */
	public:
        /**
         * Constructor de la clase Proxy
         */
    	Proxy(const ReferenceCountPtr<Socket>& socket);
        /**
         * Destructor virtual de la clase Proxy.
         */ 
    	virtual ~Proxy();
};


#endif /** __PROXY_H__ */

