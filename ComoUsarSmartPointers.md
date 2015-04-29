# Como usar los Smart Pointers para manejo eficiente de memoria.

Como sabran dentro del "paquete" common/smartptr hay una clase template llamada ReferenceCountPtr que basicamente es un Smart Pointer o puntero inteligente que lleva cuenta de las referencias que tiene un puntero y hace delete del puntero cuando dicha cuenta llega a cero.
Ahora como usar esta clase template y empezar a dejar de lado los delete:

## Como crear un Smart Pointer ##
```
ReferenceCountPtr<int> punteroInt;
```
Con esta pequeña linea de codigo estamos definiendo un objeto de tipo ReferenceCountPtr especializado en int, es decir va a guardar un puntero a int y llevar cuenta de sus referencias, lo construimos sin asignarle nada, es decir que actualmente apunta a NULL, y cuando salga del scope, ya sea metodo o funcion va a saber que apunta a NULL y no va a intentar borrar nada.

## Como crear un Smart Pointer inicializado a partir de un puntero comùn ##
```
ReferenceCountPtr<int> punteroInt(new int(5));
```
Con esta pequeña linea de còdigo estamos definiendo un objeto de tipo ReferenceCountPtr especializado en int, va a guardar punteros a int y llevar cuenta de sus referencias, lo construimos asignandole un puntero a int creado con NEW y vive en el heap, con esto va a inicializar el Smart Pointer apuntando al puntero creado con new int(5), y setear la cuenta de referencias en 1. Cuando salga del scope va a decrementar la cuenta de referencias en 1, y su cuenta va a llegar a cero, eso indica que el puntero no es usado en ningun otro lugar y es seguro eliminarlo del heap con DELETE.

## Como crear un Smart Pointer inicializado a partir de otro Smart Pointer ##
```
ReferenceCountPtr<int> primerPuntero(new int(10));
ReferenceCountPtr<int> segundoPuntero(priemrPuntero);
```
La primera linea es igual que las anteriores, inicializa el primer Smart Pointer apuntando al nuevo puntero creado con NEW y establece la cuenta de referencias en 1.
La segunda linea basicamente es construir un Smart Pointer a partir de otro, es decir el segundo Smart Pointer va a apuntar al puntero creado con new int(10) que vive en el HEAP
e incrementar la cuenta de referencias en 1. Ahora va a haber 2 referencias al puntero.
Cuando el primer puntero salga del scope, va a decrementar en 1 la referencia, ahora la cuenta de referencias es 1, todavia hay otra clase o SmartPointer que esta usando ese puntero, cuando salga del scope el segundo Smart Pointer va decrementar en 1 la referencia, ahora la cuenta de referencias es 0 y es seguro eliminar con DELETE el puntero creado con NEW.

## Como asignar punteros a un Smart Pointer ##
```
ReferenceCountPtr<int> primerPuntero(new int(5));
primerPuntero = new int(10);
```
La primera linea crea uns Smart Pointer apuntando a lo que devuelve new int(5) e incrmeenta la cuenta de referencias en 1. Luego la segunda linea, basicamente hace que el SmartPointer se desligue de su puntero asociado, es decir decremente la cuenta de referencias de su puntero asociado en 1, si la cuenta de referencias llega a cero, es seguro borrarlo del HEAP y lo borra con DELETE, y luego asigna al puntero asociado el que recibe como parametro estableciendo su cuenta de referencias en 1. Al salir del scope su cuenta de referencias se disminuirà a cero y se borrara del HEAP con DELETE.

## Como asignar Smart Pointers a Smart Pointers ##
```
ReferenceCountPtr<int> primerPuntero(new int(5));
ReferenceCountPtr<int> segundoPuntero(new int(10));

primerPuntero = segundoPuntero;
```
Basicamente la primera linea crea un Smart Pointer como se explico antes, la segunda linea
hace lo mismo, la tercer linea lo que hace es que el primer Smart Pointer, se desligue de su puntero asociado, decremente su cuenta de referencias en 1, si la cuenta llega a cero, lo borra del heap, y luego, toma el puntero asociado al segundo Smart Pointer y lo usa como puntero asociado propio incrementando su cuenta de referencias en 1. Con lo cual la cuenta de referencias de new int(10) serà 2. Cuando salgan del scope se ira reduciendo la cuenta de referencias hasta llegar a cero que es cuando se harà el DELETE del puntero que vive en el HEAP.

## Como acceder a los miembros del puntero apuntado por el Smart Pointer ##
```
struct A {
   int number;
}

ReferenceCountPtr<A> puntero(new A);

puntero->number = 5;
```
Basicamente lo que hago es definir una estructura A con un miembro publico llamado number, luego creo un Smart Pointer apuntando a un puntero creado con new de tipo A, y luego manejo el Smart Pointer como si fuera un puntero normal para acceder a los miembros del struct A (->)

## Como accedo al elemento apuntado por un Smart Pointer ##
```
#include<iostream>

ReferenceCountPtr<int> puntero(new int(10));

std::cout << "El elemento apuntado es: " << *puntero << std::endl;
```
Como se puede ver si usamos el operador de indireccion
```
(operador *)
```
accederemos al elemento apuntado por el Smart Pointer. De esta forma nos permite intercambiar Smart Pointers y punteros normal en el codigo y no se notarà la diferencia en uso.

## Como usar clases derivadas y Smart Pointers ##
```
struct A {
    int number;
}

struct B: public A {
}

ReferenceCountPtr<A> punteroA(new A);
ReferenceCountPtr<A> punteroB(new B);
```
Como veràn defini al Smart Pointer para que almacene punteros al struct A que es el struct base del cual hereda B, y al mismo Smart Pointer le puedo asignar punteros a struct A o cualqueira de sus derivados como sucede en la segunda instanciacion del Smart Pointer.

## Casos donde es ùtil usar Smart Pointers ##
```
try {
     ReferenceCountPtr<int> puntero(new int(10));

     // Aca va codigo que puede o no lanzar excepciòn
} catch(std::exception& excepcion) {
// No hace nada, no libera el puntero porque lo ahce solo el Smart Pointer
}

```
Este es un caso tipico, uno crea un objeto o variable en el HEAP dentro de un codigo que puede o no lanzar excepcion, en dicho caso, si se lanza excepcion y si no se usa Smart Pointers tanto antes de salir del bloque try debemos hacer un delete del puntero y en el catch tambien, por el hecho de que sino estariamos perdiendo memoria, este approach es muy error prone.

```
ReferenceCountPtr<int> funcionQueDevuelvePunteroEnHeap() {
      // Hace algo que tenga que hacer
      return new int(10);
}

int main(int argc, char** argv) {
    ReferenceCountPtr<int> puntero;

    // Aca ejecuto codigo que necesite


    // Invoco a funcionQueDevuelvePunteroEnHeap
    puntero = funcionQueDevuelvePunteroEnHeap();

    // opero con el puntero, hago lo que necesite

    return 0;
}
```
En este caso es cuando una funcion o metodo de instancia o clase debe devolver un puntero a un objeto alocado en el HEAP, usando Smart Pointers indicamos al que llama la funciòn que nosotros, mejor dicho el Smart Pointer se hace cargo de la liberacion del puntero alojado en el HEAP y el no tiene que hacer delete.

## Cuando NO!!! usar Smart Pointers ##
```
int numero = 5;

ReferenceCountPtr<int> puntero(&numero);
...
...
...
```
Este es un caso tipico donde NO!!!! hay que usar Smart Pointers, porque? porque como el Smart Pointer se inicializa con la direccion de memoria de algo que esta en el Stack, cuando salgamos del scope, el Smart Pointer va a querer borrar memoria dentro del stack, si primero se destuy eel puntero va a poder borrarla pero cuando realmente el compilador quiera borrar la variable que apuntaba el Smart Pointer nos va a lanzar un lindisimo SIGSEGV es decir SEGMENTATION FAULT, por querer borrar memoria invalida o fuera del alcance de nuestro programa. Por eso siempre usar Smart Pointers para cosas alojadas en el HEAP con NEW.

Bueno la moraleja o fin de todo esto es que empecemos a usar Smart Pointers siempre que necesitemos usar punteros a objetos alojados en el HEAP porque nos simplifica muchisimo la tarea de la liberaciòn de la memoria.

Saludos
Pablo