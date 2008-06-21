#include<gtkmm/main.h>
#include "mainwindow.h" // Para definicion de MainWindow.
#include<iostream>
int main(int argc, char** argv) {
    Gtk::Main main(argc, argv);

	MainWindow mainWindow;
	mainWindow.maximize();    
	Gtk::Main::run(mainWindow);

    return 0;
}

/*int main(int argc, char** argv) {
    MapaParser parser;

    ReferenceCountPtr<Mapa> map = parser.loadMap("./mapa.xml");
    Mapa::IteradorPais countryIter;
    Pais::Iterador adjacentIter;
    Continente::Iterador continentCountryIter;
    for (countryIter = map->primerPais(); countryIter != map->ultimoPais(); ++countryIter) {
        ReferenceCountPtr<Pais> country = *countryIter;
        std::cout << "NOMBRE: ";
        std::cout << country->getNombre();
        std::cout << " POSICION X: ";
        std::cout <<  country->getPosition().getX();
        std::cout << " POSICION Y: ";
        std::cout << country->getPosition().getY();
        std::cout << std::endl;

        std::cout << "Imprimiendo los adyacentes:" << std::endl;
        for (adjacentIter = country->primerAdyacente(); adjacentIter != country->ultimoAdyacente(); ++adjacentIter) {
            ReferenceCountPtr<Pais> adjacent = *adjacentIter;
            std::cout << "----NOMBRE: ";
            std::cout << adjacent->getNombre();
            std::cout << " POSICION X: ";
            std::cout << adjacent->getPosition().getX();
            std::cout << " POSICION Y: ";
            std::cout << adjacent->getPosition().getY();
            std::cout << std::endl;
        }
    }

    Mapa::IteradorContinente continentIter;
    for (continentIter = map->primerContinente(); continentIter != map->ultimoContinente(); ++continentIter) {
        ReferenceCountPtr<Continente> continent = *continentIter;
        std::cout << "NOMBRE: ";
        std::cout << continent->getNombre();
        std::cout << " BONUS: ";
        std::cout <<  continent->getArmyBonus();
        std::cout << std::endl;

        std::cout << "Imprimiendo los paises del continente" << std::endl;
        for (continentCountryIter = continent->primerPais(); continentCountryIter != continent->ultimoPais(); ++ continentCountryIter) {
            ReferenceCountPtr<Pais> country = *continentCountryIter;
            std::cout << "----NOMBRE: ";
            std::cout << country->getNombre();
            std::cout << " POSICION X: ";
            std::cout << country->getPosition().getX();
            std::cout << " POSICION Y: ";
            std::cout << country->getPosition().getY();
            std::cout << std::endl;
        }
    }
	Mapa::IteradorGameCard gameCardIter;
	for (gameCardIter = map->primerGameCard(); gameCardIter != map->ultimoGameCard(); ++gameCardIter) {
		ReferenceCountPtr<GameCard> gameCard = *gameCardIter;
		std::cout << "Nombre: " << gameCard->getName() << std::endl;
	}
    return 0;
}*/
