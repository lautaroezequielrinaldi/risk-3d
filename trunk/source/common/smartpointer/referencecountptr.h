#ifndef __REFERENCECOUNTPTR_H__
#define __REFERENCECOUNTPTR_H__

/**
 * C++ Standard Template Library Includes.
 */
#include<cstdlib> // Para definiciòn de NULL

/**
 * Project Includes.
 */
#include "referencecount.h" // Para definiciòn de ReferenceCount

/**
 * Definiciòn de la clase ReferenceCountPtr que es usada para encapsular un
 * puntero junto con la cuenta de referencias del mismo y eliminarlo del heap
 * cuando su cuenta de referencias llega a cero.
 */
template<class T>
class ReferenceCountPtr {
    /**
     * Atributos privados de la clase ReferenceCountPtr.
     */
    private:
        /**
         * Almacena la cuenta de referencias de un puntero a encapsular de la
         * clase ReferenceCountPtr.
         */
        ReferenceCount* referenceCount;

        /**
         * Almacena el puntero a encapsular de la clase ReferenceCountPtr.
         */
        T* pointer;
    /**
     * Mètodos privados de la clase ReferenceCountPtr.
     */
    private:
        /**
         * Liga el puntero recibido como pàrametro.
         */
        void attach( T* pointer );

        /**
         * Liga el objeto de tipo ReferenceCountPtr recibido como pàrametro.
         */
        void attach( const ReferenceCountPtr<T>& otherInstance );

        /**
         * Desliga el puntero encapsulado.
         */
        void detach();

        /**
         * Asigna el puntero recibido como pàrametro.
         * Basicamente desliga el puntero encapsulado y luego liga el puntero
         * recibido como paràmetro.
         */
        void assign( T* pointer );

        /**
         * Asigna el objeto de tipo ReferenceCountPtr recibido como paràmetro.
         * Basicamente desliga el puntero encapsulado y luego liga el objeto
         * de tipo ReferenceCountPtr recibido como paràmetro.
         */
        void assign( const ReferenceCountPtr<T>& otherInstance );

    /**
     * Mètodos pùblicos de la clase ReferenceCountPtr.
     */
    public:
        /**
         * Constructor de la clase ReferenceCountPtr.
         * Construye una nueva instancia de la clase ReferenceCountPtr.
         */
        ReferenceCountPtr();

        /**
         * Constructor de la clase ReferenceCountPtr.
         * Construye una nueva instancia de la clase ReferenceCountPtr a partir
         * de un puntero existente.
         */
        ReferenceCountPtr( T* pointer );

        /**
         * Constructor de la clase ReferenceCountPtr.
         * Construye una nueva instancia de la clase ReferenceCountPtr a partir
         * de un objeto de tipo ReferenceCountPtr.
         */
        ReferenceCountPtr( const ReferenceCountPtr<T>& otherInstance );

        /**
         * Operador de asignaciòn de la clase ReferenceCountPtr.
         * Asigna el puntero existente a la clase ReferenceCountPtr.
         */
        ReferenceCountPtr& operator=( T* pointer );

        /**
         * Operador de asignaciòn de la clase ReferenceCountPtr.
         * Asigna el objeto de tipo ReferenceCountPtr existente a la clase
         * ReferenceCountPtr.
         */
        ReferenceCountPtr& operator=( const ReferenceCountPtr<T>& otherInstance );

        /**
         * Operador de indirecciòn de la clase ReferenceCountPtr.
         * Devuelve al puntero encapsulado.
         */
        T* operator->();

        /**
         * Operador de indirecciòn de la clase ReferenceCountPtr.
         * Devuelve al objeto apuntado por el puntero encapsulado.
         */
        T& operator*();

        /**
         * Obtiene un flag booleano indicando si el puntero encapsulado es
         * NULL o no.
         */
        bool isNull();

        /**
         * Destructor virtual de la clase ReferenceCountPtr.
         * Destruye una instancia existente de la clase ReferenceCountPtr.
         */
        ~ReferenceCountPtr();
};

template<class T>
ReferenceCountPtr<T>::ReferenceCountPtr():
    referenceCount( NULL ),
    pointer( NULL ) {
    // No realiza ninguna acciòn.
}

template<class T>
ReferenceCountPtr<T>::ReferenceCountPtr( T* pointer ):
    referenceCount( NULL ),
    pointer( NULL ) {
    // Liga el puntero recibido como argumento.
    this->attach( pointer );
}

template<class T>
ReferenceCountPtr<T>::ReferenceCountPtr( 
        const ReferenceCountPtr<T>& otherInstance ):
    referenceCount( NULL ),
    pointer( NULL ) {
    // Liga el objeto de tipo ReferenceCountPtr como argumento.
    this->attach( otherInstance );
}

template<class T>
void ReferenceCountPtr<T>::attach( T* pointer ) {
    if ( pointer != NULL ) {
        this->referenceCount = new ReferenceCount();
        this->referenceCount->increment();
    } else {
        this->referenceCount = NULL;
    }
    this->pointer = pointer;
}

template<class T>
void ReferenceCountPtr<T>::attach( const ReferenceCountPtr<T>& otherInstance ) {
    this->referenceCount = otherInstance.referenceCount;
    this->pointer = otherInstance.pointer;
    if ( this->referenceCount != NULL ) {
        this->referenceCount->increment();
    }
}

template<class T>
void ReferenceCountPtr<T>::detach() {
    if ( this->referenceCount != NULL && this->pointer != NULL ) {
        this->referenceCount->decrement();
        if ( this->referenceCount->getReferenceCount() == 0 ) {
            delete this->referenceCount;
            delete this->pointer;
            this->referenceCount = NULL;
            this->pointer = NULL;
        }
    }
}

template<class T>
void ReferenceCountPtr<T>::assign( T* pointer ) {
    this->detach();
    this->attach( pointer );
}

template<class T>
void ReferenceCountPtr<T>::assign( const ReferenceCountPtr<T>& otherInstance ) {
    this->detach();
    this->attach( otherInstance );
}

template<class T>
ReferenceCountPtr<T>& ReferenceCountPtr<T>::operator=( T* pointer ) {
    this->assign( pointer );
    return ( *this );
}

template<class T>
ReferenceCountPtr<T>& ReferenceCountPtr<T>::operator=( 
        const ReferenceCountPtr<T>& otherInstance ) {
    this->assign( otherInstance );
    return ( *this );
}

template<class T>
T* ReferenceCountPtr<T>::operator->() {
    return this->pointer;
}

template<class T>
T& ReferenceCountPtr<T>::operator*() {
    return ( *( this->pointer ) );
}

template<class T>
bool ReferenceCountPtr<T>::isNull() {
    return this->pointer == NULL;
}

template<class T>
ReferenceCountPtr<T>::~ReferenceCountPtr() {
    // Desliga el puntero encapsulado.
    this->detach();
}

#endif /** __REFERENCECOUNTPTR_H__ */

