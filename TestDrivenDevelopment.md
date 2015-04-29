# Test Driven Development #

Como veran el proposito de esta wiki page es explicarle un poco como pienso que deberiamos aplicar Text Driven Development en el proyecto.

La mejor herramienta hasta el momento que encontre para hacer unit testing en C++ es CppUnit y aqui les expongo algunas pautas con las que me tope cuando hice una prueba de concepto sobre usar CppUnit...

Para instalar la libreria en Ubuntu / Devian derivados, simplemente hay que descargar el siguiente paquete: cpppunit.
```
sudo apt-get install cppunit

o bien

sudo aptitude install cppunit

o bien desde synaptic package manager buscar el paquete cppunit y bajarlo
```

Para instalar en Fedora hay que descargar el mismo paquete segun tengo entendido con yum o con pirut.

```
su
yum install cppunit

o bine descargarlo con pirut package manager.
```

CppUnit necesita tener alguna funcion main que corra o ejecute los test unitarios, es por eso que vamos a toparnos con tener 2 funciones main. La primera va a ser la puerta de entrada de la ejecucion de nuestro programa, ya sea el cliente, el server o el editor de mapas, y ademas de dichas funcioens main tiene que haber otra funcion, en otro .cpp digamos mainTest.cpp que hace correr a los tests unitarios.

Es por eso que debemos compilar por un lado a nuestro proyecto junto con el main que lo hace ejecutar, y por otro lado tendremos que compilar a neustro proyecto sin el main y compilar tambien el mainTest.cpp que corre a nustros tests unitarios.

Todo eso va a estar encapsulado en el Makefile, va a haber reglas de compilacion de target, para que al ejecutar:

```
make
```

Nos compile todo nuestro proyecto generandonos el ejecutable del cliente, el ejecutable del editor y el ejecutable del servidor

Y que al ejecutar
```
make test
```

Nos compile un ejecutable que nos permita correr los test unitarios.

Para poder usarlo con el servidor de integracion continua deberemos crear 2 scripts de bash, uno de ellos va a compilar a nuestro proyecto invocando a make y corriendo valgrind sobre el ejecutable o ejecutables generados.... Y otro script de bash que correra make test y correra los unit tests y correra valgrind sobre los test unitarios.

Este es un simple ejemplo de un unit test escrito en CppUnit:

Clase Calculadora:
Archivo: calculadora.h
```
#ifndef __CALCULADORA_H__
#define __CALCULADORA_H__

class Calculadora {
      public:
            static int sumar(int primero, int segundo);
            static int restar(int primero, int segundo);
            static int multiplicar(int primero, int segundo);
};

#endif
```

Archivo: calculadora.cpp
```
#include "calculadora.h"

int Calculadora::sumar(int primero, int segundo() {
    return primero + segundo;
}

int Calculadora::restar(int primero, int segundo) {
    return primero - segundo:
}

int Calculadora::multiplicar(int primero, int segundo) {
    return primero * segundo:
}
```
# Details #

Archivo calculadoratest.h
```
#include<string>
#include<CppUnit/TestCase.h>
#include<CppUnit/TestSuite.h>
#include<CppUnit/TestCaller.h>
#include<CppUnit/TestAssert.h>

#include "../source/calculadora.h" // Suponemos que tenemos dos directorios source y test
// que estan al mismo nivel, source para los fuentes y test para los test de los fuentes

class CalculadoraTest : public CppUnit::TestCase {
      public:
             CalculadoraTest(std::string name);
             void testSumar();
             void testRestar();
             void testMultiplicar();
             static CppUnit::TestSuite* suite();
};
#endif
```

Archivo calculadoratest.cpp
```
#include "calculadoratest.h"

CalculadoraTest::CalculadoraTest(std::string name) : CppUnit::TestCase(name) {
 //No hace nada
}

void CalculadoraTest::testSumar() {
     int resultado = Calculadora::sumar(5,2);
     CPPUNIT_ASSERT( 7 == resultado);
}

void CalculadoraTest::testRestar() {
     int resultado = Calculadora::restar(5,2);
     CPPUNIT_ASSERT(3 == resultado);
}

void CalculadoraTest::testMultiplicar() {
     int resultado = Calculadora::multiplicar(5,2);
     CPPUNIT_ASSERT(10 == resultado);
}

CppUnit::TestSuite* CalculadoraTest::suite() {
           CppUnit::TestSuite* suite = new CppUnit::TestSuite("CalculadoraTest");
           suite->addTest(new CppUnit::TestCaller<CalculadoraTest>("testSumar", &CalculadoraTest::testSumar);
           suite->addTest(new CppUnit::TestCaller<CalculadoraTest>("testRestar", &CalculadoraTest::testRestar);
           suite->addTest(new CppUnit::TestCaller<CalculadoraTest>("testMultiplicar", &CalculadoraTest::testMultiplicar);

           return suite;
}
```

Este es el main que corre el unit test:
Archivo: mainTest.cpp
```
#include<CppUnit/ui/text/TestRunner.h>

#include "CalculadoraTest.h"

int main(int argc, char** argv) {
    CppUnit::TextUi::TestRunner runner;

    runner.addTest(CalculadoraTest::suite());

    if ( runner.run() ) {
        return 0;
    } else {
        return 1:
    }
}
```

Para correr los test unitarios simplemente tendràn que ejecutar esto desde la base del proyecto...
```
make test
test/risk3d-unit-test
```

Suponiendo que hay una funcion main que corre los unit tests y que hay unit test para ser ejecutados y corridos.