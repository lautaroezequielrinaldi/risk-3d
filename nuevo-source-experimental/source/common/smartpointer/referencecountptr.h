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
	// Defino a la clase Friend
	template<class Y> friend class ReferenceCountPtr;
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
		template<class Y> void attach( Y* pointer );

        /**
         * Liga el objeto de tipo ReferenceCountPtr recibido como pàrametro.
         */
        void attach( const ReferenceCountPtr<T>& otherInstance );
		template<class Y> void attach( const ReferenceCountPtr<Y>& otherInstance);
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
		template<class Y> void assign( Y* pointer );

		/**
         * Asigna el objeto de tipo ReferenceCountPtr recibido como paràmetro.
         * Basicamente desliga el puntero encapsulado y luego liga el objeto
         * de tipo ReferenceCountPtr recibido como paràmetro.
         */
        void assign( const ReferenceCountPtr<T>& otherInstance );
		template<class Y> void assign( const ReferenceCountPtr<Y>& otherInstance );

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
        template<class Y> ReferenceCountPtr( Y* pointer );

        /**
         * Constructor de la clase ReferenceCountPtr.
         * Construye una nueva instancia de la clase ReferenceCountPtr a
         * partir de un objeto de tipo ReferenceCountPtr.
         */
        ReferenceCountPtr( const ReferenceCountPtr<T>& otherInstance );
        template<class Y> ReferenceCountPtr(const ReferenceCountPtr<Y>& otherInstance);
        /**
         * Operador de asignaciòn de la clase ReferenceCountPtr.
         * Asigna el puntero existente a la clase ReferenceCountPtr.
         */
        ReferenceCountPtr& operator=( T* pointer );
        template<class Y> ReferenceCountPtr& operator=( Y* pointer );

        /**
         * Operador de asignaciòn de la clase ReferenceCountPtr.
         * Asigna el objeto de tipo ReferenceCountPtr existente a la clase
         * ReferenceCountPtr.
         */
        ReferenceCountPtr& operator=( const ReferenceCountPtr<T>& otherInstance );
        template<class Y> ReferenceCountPtr& operator=( const ReferenceCountPtr<Y>& otherInstance);

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
         * Operador de comparaciòn de la clase ReferenceCounPtr.
         * Compara el smart pointer contra un puntero regular de C / C++
         */
        bool operator==( T* pointer );
		template<class Y> bool operator==( Y* pointer );

		/**
         * Operador de comparaciòn de la clase ReferenceCountPtr.
         * Compara el smart pointer contra otro smart pointer.
         */
        bool operator==( const ReferenceCountPtr<T>& otherInstance);
		template<class Y> bool operator==( const ReferenceCountPtr<Y>& otherInstance);

        /**
         * Operador de comparaciòn de la clase ReferenceCountPtr.
         * Compara el smart pointer contra un puntero recular de C / C++
         */
        bool operator!=( T* pointer );
		template<class Y> bool operator!=( Y* pointer );

        /**
         * Operador de comparaciòn de la clase ReferenceCountPtr.
         * Compara el smart pointer contra otro smart pointer.
         */
        bool operator!=( const ReferenceCountPtr<T>& otherInstance);
		template<class Y> bool operator!=( const ReferenceCountPtr<Y>& otherInstance);

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
template<class Y> ReferenceCountPtr<T>::ReferenceCountPtr( Y* pointer):
        referenceCount( NULL ),
        pointer( NULL ) {
    // Liga el puntero recibido como argumento.
    this->attach ( pointer );
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
template<class Y>
ReferenceCountPtr<T>::ReferenceCountPtr(
        const ReferenceCountPtr<Y>& otherInstance):
    referenceCount(NULL),
    pointer( NULL ) {
    // Liga el objeto de tipo ReferenceCountPtr< como argumento.
    this->attach (otherInstance);
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
template<class Y>
void ReferenceCountPtr<T>::attach( Y* pointer) {
	if ( pointer != NULL ) {
		this->referenceCount = new ReferenceCount();
		this->referenceCount->increment();
	} else {
		this->referenceCount = NULL;
	}
	this->pointer = (T*) pointer;
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
template<class Y>
void ReferenceCountPtr<T>::attach( const ReferenceCountPtr<Y>& otherInstance) {
	this->referenceCount = otherInstance.referenceCount;
	this->pointer = (T*) otherInstance.pointer;
	if ( this->referenceCount != NULL) {
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
template<class Y>
void ReferenceCountPtr<T>::assign( Y* pointer ) {
    this->detach();
    this->attach( pointer );
}

template<class T>
void ReferenceCountPtr<T>::assign( const ReferenceCountPtr<T>& otherInstance ) {
    this->detach();
    this->attach( otherInstance );
}

template<class T>
template<class Y>
void ReferenceCountPtr<T>::assign( const ReferenceCountPtr<Y>& otherInstance ) {
    this->detach();
    this->attach( otherInstance );
}

template<class T>
ReferenceCountPtr<T>& ReferenceCountPtr<T>::operator=( T* pointer ) {
    this->assign( pointer );
    return ( *this );
}

template<class T>
template<class Y>
ReferenceCountPtr<T>& ReferenceCountPtr<T>::operator=( Y* pointer ) {
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
template<class Y>
ReferenceCountPtr<T>& ReferenceCountPtr<T>::operator=(
        const ReferenceCountPtr<Y>& otherInstance ) {
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
bool ReferenceCountPtr<T>::operator==( T* pointer ) {
    return this->pointer == pointer;
}

template<class T>
template<class Y>
bool ReferenceCountPtr<T>::operator==( Y* pointer ) {
    return this->pointer == (T*) pointer;
}

template<class T>
bool ReferenceCountPtr<T>::operator==(
    const ReferenceCountPtr<T>& otherInstance) {
    return this->pointer == otherInstance.pointer;
}

template<class T>
template<class Y>
bool ReferenceCountPtr<T>::operator==(
    const ReferenceCountPtr<Y>& otherInstance) {
    return this->pointer == (T*) otherInstance.pointer;
}

template<class T>
bool ReferenceCountPtr<T>::operator!=( T* pointer )  {
    return this->pointer != pointer;
}

template<class T>
template<class Y>
bool ReferenceCountPtr<T>::operator!=( Y* pointer )  {
    return this->pointer != (T*) pointer;
}

template<class T>
bool ReferenceCountPtr<T>::operator!=(
    const ReferenceCountPtr<T>& otherInstance) {
    return this->pointer != otherInstance.pointer;
}

template<class T>
template<class Y>
bool ReferenceCountPtr<T>::operator!=(
    const ReferenceCountPtr<Y>& otherInstance) {
    return this->pointer != (T*) otherInstance.pointer;
}

template<class T>
ReferenceCountPtr<T>::~ReferenceCountPtr() {
    // Desliga el puntero encapsulado.
    this->detach();
}

#endif /** __REFERENCECOUNTPTR_H__ */

