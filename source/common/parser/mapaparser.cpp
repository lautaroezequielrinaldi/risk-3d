#include "mapaparser.h"

MapaParser::MapaParser():
    document(NULL) {
    // No realiza ninguna acciòn.
}

void MapaParser::persistirImagen(xmlNodePtr& mapNode,
	const std::string& imageFileName) {
	// Creo el archivo de imagen a leer.
	std::ifstream imageFile(imageFileName.c_str(),
		std::ios_base::in | std::ios_base::binary);
	std::vector<unsigned char> bytes;
	char character;
	while (imageFile.read (&character, 1)) {
		bytes.push_back(character);
	}

	std::string base64 = HexCoder::encode(bytes);
	// Creo un nodo para la imagen encodeada.
	xmlNewChild(mapNode, NULL,
		BAD_CAST (const xmlChar*) "imagen",
		BAD_CAST (const xmlChar*) base64.c_str());
}

void MapaParser::persistirPaises(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {
    // Define el nodo de lista de paises a persistir.
    xmlNodePtr countryListNode;
    // Define el nodo del pais a persistir.
    xmlNodePtr countryNode;
    // Define el nodo del pais adyacente a persistir.
    xmlNodePtr adjacentNode;
    // Defino el contador de pais.
    Mapa::IteradorPais countryIter;
    // Defino el contador de adyacente.
    Pais::Iterador adjacentIter;

    // Creo el nodo de lista de paises a persistir.
    countryListNode = xmlNewChild(mapNode, NULL, BAD_CAST "lista-paises",
        NULL);
    // Itero por cada pais.
    for (countryIter = map->primerPais(); countryIter != map->ultimoPais();
        ++countryIter) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> actual = *countryIter;
        // Creo el nodo del pais a persistir.
        countryNode = xmlNewChild(countryListNode, NULL, BAD_CAST "pais", NULL);
        // Agrego el atributo nombre del pais a persistir.
        xmlNewProp(countryNode, BAD_CAST "nombre",
            BAD_CAST (const xmlChar*) actual->getNombre().c_str());

        // Creo un string stream para convertir numeros a string
        std::ostringstream xPositionStr;
        xPositionStr << actual->getPosition().getX();

        // Creo un string stream para convertir numeros a string
        std::ostringstream yPositionStr;
        yPositionStr << actual->getPosition().getY();

        // Agrego el atributo x del pais a persistir.
        xmlNewProp(countryNode, BAD_CAST "x",
            BAD_CAST (const xmlChar*) xPositionStr.str().c_str());

        // Agrego el atributo y del pais a persistir.
        xmlNewProp(countryNode, BAD_CAST "y",
            BAD_CAST (const xmlChar*) yPositionStr.str().c_str());
            
        // Itero por cada pais adyacente.
        for (adjacentIter = actual->primerAdyacente(); 
            adjacentIter != actual->ultimoAdyacente(); ++adjacentIter) {
            // Obtengo pais adyacente actual.
            ReferenceCountPtr<Pais> adyacenteActual = *adjacentIter;
            // Creo el nodo del pais adyacente a persistir.
            adjacentNode = xmlNewChild(countryNode, NULL, BAD_CAST "adyacente",
                BAD_CAST (const xmlChar*) adyacenteActual->getNombre().c_str());
        }
    }
}

void MapaParser::persistirContinentes(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {
    // Define el nodo de lista de continentes a persistir.
    xmlNodePtr continentListNode;
    // Define el nodo del continente a persistir.
    xmlNodePtr continentNode;
    // Define el nodo del pais a persistir.
    xmlNodePtr countryNode;
    // Defino el contador de continente.
    Mapa::IteradorContinente continentIter;
    // Defino el contador de adyacente.
    Pais::Iterador countryIter;

    // Creo en nodo de lista de continentes a persistir.
    continentListNode = xmlNewChild(mapNode, NULL,
        BAD_CAST "lista-continentes", NULL);
    // Itero por cada continente.
    for (continentIter = map->primerContinente();
        continentIter != map->ultimoContinente(); ++continentIter) {
        // Obtengo continente actual.
        ReferenceCountPtr<Continente> actual = *continentIter;
        // Creo el nodo del continente a persistir.
        continentNode = xmlNewChild(continentListNode, NULL,
            BAD_CAST "continente", NULL);
        // Agrego el atributo nombre del continente a persistir.
        xmlNewProp(continentNode, BAD_CAST "nombre",
            BAD_CAST (const xmlChar*) actual->getNombre().c_str());

		// Creo un stream de salida de string para convertir numero a string
		std::ostringstream strBonus;
		strBonus << actual->getArmyBonus();

		// Agrego el atributo bonus del continente a persistir.
		xmlNewProp(continentNode, BAD_CAST "bonus",
			BAD_CAST (const xmlChar*) strBonus.str().c_str());
			
        // Itero por cada pais.
        for (countryIter = actual->primerPais(); 
            countryIter != actual->ultimoPais(); ++countryIter) {
            // Obtengo pais pais actual.
            ReferenceCountPtr<Pais> paisActual = *countryIter;
            // Creo el nodo del pais a persistir.
            countryNode = xmlNewChild(continentNode, NULL, BAD_CAST "pais",
                BAD_CAST (const xmlChar*) paisActual->getNombre().c_str());
        }
    }
}

void MapaParser::persistirReglas(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {
    // Define el nodo de lista de cartas de juego a persistir.
    xmlNodePtr gameCardListNode;
    // Define el nodo de la carta de juego a persistir.
    xmlNodePtr gameCardNode;
    // Defino el iterador de cartas de juego.
    Mapa::IteradorGameCard gameCardIter;

    // Creo el nodo de lista de cartas de juego a persistir.
    gameCardListNode = xmlNewChild(mapNode, NULL,
        BAD_CAST "lista-cartas-de-juego", NULL);
    // Itero por cada carta de juego.
    for (gameCardIter = map->primerGameCard(); gameCardIter != map->ultimoGameCard();
        ++gameCardIter) {
        // Obtengo la carta de juego actual.
        ReferenceCountPtr<GameCard> gameCard = *gameCardIter;
        // Crea el nodo para la carta de juego
        gameCardNode = xmlNewChild(gameCardListNode, NULL, BAD_CAST "carta-de-juego",
            NULL);
        // Serializa la carta de juego
        std::map<std::string, std::string> result  = gameCard->toString();
        std::map<std::string, std::string>::iterator attributeIter;
        for (attributeIter = result.begin(); attributeIter != result.end();
            ++attributeIter) {
            std::string key = attributeIter->first;
            std::string value = attributeIter->second;
            xmlNewProp(gameCardNode, BAD_CAST (const xmlChar*) key.c_str(),
                BAD_CAST (const xmlChar*) value.c_str());
        }
    }
}

void MapaParser::cargarPaises(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {
    // Defino un contexto de XPath.
    xmlXPathContextPtr xpathContext;
    // Defino un objeto de XPath.
    xmlXPathObjectPtr xpathObject;
    // Defino el set de nodos devueltos por la expresiòn XPath.
    xmlNodeSetPtr countryNodeSet;
    // Defino el set de nodos devueltos por la expresion XPath.
    xmlNodeSetPtr adjacentNodeSet;

    // Creo el contexto de XPath.
    xpathContext = xmlXPathNewContext(this->document);

    // Evaluo la expresiòn XPath.
    xpathObject = xmlXPathEvalExpression(BAD_CAST "//mapa/lista-paises/pais",
        xpathContext);

    // Obtengo el set de nodos de paises.
    countryNodeSet = xpathObject->nodesetval;

    // Itero por cada nodo de paises.
    for ( int contador = 0; contador < countryNodeSet->nodeNr; ++contador) {
        // Obtengo el nodo del pais actual.
        xmlNodePtr countryNode = countryNodeSet->nodeTab[contador];

        // Obtengo el nombre del pais actual.
        std::string nombre = (const char*) xmlGetProp(countryNode,
            BAD_CAST "nombre");
        // Obtengo la posicion x del pais actual,
        std::string xPositionStr = (const char*) xmlGetProp(countryNode,
            BAD_CAST "x");
        // Obtengo la posicion y del pais actual.
        std::string yPositionStr = (const char*) xmlGetProp(countryNode,
            BAD_CAST "y");
        // Creo posicion del pais
        MapPosition position(atoi(xPositionStr.c_str()),
            atoi(yPositionStr.c_str()));
        // Creo objeto pais.
        ReferenceCountPtr<Pais> country(new Pais(nombre, position));

        // Agrego pais al mapa de paises cargados.
        this->paisesCargados[nombre] = country;

        // Agrego el pais al mapa.
        map->agregarPais(country);
    }

    // Creo iterador para recorrer paises del mapa.
    Mapa::IteradorPais countryIter;
    // Itero por los paises del mapa.
    for (countryIter = map->primerPais(); countryIter != map->ultimoPais();
        ++countryIter) {
        // Obtengo pais actual.
        ReferenceCountPtr<Pais> country = *countryIter;

        // Creo expresion XPath
        std::string expresion = "//mapa/lista-paises/pais[@nombre='"
            + country->getNombre()
            + "']/adyacente";

        // Evaluo la expresiòn XPath.
        xpathObject = xmlXPathEvalExpression(BAD_CAST expresion.c_str(), xpathContext);

        // Obtengo  el set de nodos de adyacentes.
        adjacentNodeSet = xpathObject->nodesetval;

        // Itero por cada nodo de adyacentes.
        for (int contador = 0; contador < adjacentNodeSet->nodeNr; ++contador) {
            // Obtengo el nodo del adyacente actual.
            xmlNodePtr adjacentNode = adjacentNodeSet->nodeTab[contador];

            // Obtengo el nombre del adyacente actual.
            std::string nombreAdyacente = (const char*) xmlNodeGetContent(adjacentNode);

            // Obtengo el paise cargado.
            ReferenceCountPtr<Pais> adjacent = this->paisesCargados[nombreAdyacente];

            // Agrego el adyacente al pais.
            country->agregarAdyacente(adjacent);
        }
    }
}

void MapaParser::cargarContinentes(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {
    // Defino un contexto de XPath.
    xmlXPathContextPtr xpathContext;
    // Defino un objeto de XPath.
    xmlXPathObjectPtr xpathObject;
    // Defino el set de nodos devueltos por la expresiòn XPath.
    xmlNodeSetPtr continentNodeSet;
    // Defino el set de nodos devueltos por la expresion XPath.
    xmlNodeSetPtr countryNodeSet;

    // Creo el contexto de XPath.
    xpathContext = xmlXPathNewContext(this->document);

    // Evaluo la expresiòn XPath.
    xpathObject = xmlXPathEvalExpression(BAD_CAST "//mapa/lista-continentes/continente",
        xpathContext);

     // Obtengo el set de nodos de continentes.
    continentNodeSet = xpathObject->nodesetval;

    // Itero por cada nodo de paises.
    for ( int contador = 0; contador < continentNodeSet->nodeNr; ++contador) {
        // Obtengo el nodo del continente actual.
        xmlNodePtr continentNode = continentNodeSet->nodeTab[contador];

        // Obtengo el nombre del continente actual.
        std::string nombre = (const char*) xmlGetProp(continentNode,
            BAD_CAST "nombre");
        // Obtengo el bonus del continente actual,
        std::string armyBonusStr = (const char*) xmlGetProp(continentNode,
            BAD_CAST "bonus");
        // Obtengo el army bonus del continente actual como int.
        int armyBonus = atoi(armyBonusStr.c_str());
        // Creo objeto continente.
        ReferenceCountPtr<Continente> continent(new Continente(nombre, armyBonus));
        // Agrego el continente al mapa.
        map->agregarContinente(continent);
    }

     // Creo iterador para recorrer continentes del mapa.
     Mapa::IteradorContinente continentIter;
     // Itero por los continentes del mapa.
     for (continentIter = map->primerContinente(); continentIter != map->ultimoContinente();
        ++continentIter) {
        // Obtengo continente actual.
        ReferenceCountPtr<Continente> continent = *continentIter;

        // Creo expresion XPath
        std::string expresion = "//mapa/lista-continentes/continente[@nombre='"
            + continent->getNombre()
            + "']/pais";

        // Evaluo la expresiòn XPath.
        xpathObject = xmlXPathEvalExpression(BAD_CAST expresion.c_str(), xpathContext);

        // Obtengo  el set de nodos de paises.
        countryNodeSet = xpathObject->nodesetval;

        // Itero por cada nodo de paises.
        for (int contador = 0; contador < countryNodeSet->nodeNr; ++contador) {
            // Obtengo el nodo del pais actual.
            xmlNodePtr countryNode = countryNodeSet->nodeTab[contador];
            // Obtengo el nombre del pais actual.
            std::string nombrePais = (const char*) xmlNodeGetContent(countryNode);
            // Obtengo el pais cargado.
            ReferenceCountPtr<Pais> country = this->paisesCargados[nombrePais];
            // Agrego el pais al continente.
            continent->agregarPais(country);
        }
    }
}

void MapaParser::cargarReglas(xmlNodePtr& mapNode,
    ReferenceCountPtr<Mapa>& map) {
    // Defino un contexto de XPath.
    xmlXPathContextPtr xpathContext;
    // Defino un objeto de XPath.
    xmlXPathObjectPtr xpathObject;
    // Defino el set de nodos devueltos por la expresion XPath.
    xmlNodeSetPtr gameCardNodeSet;

    // Creo el contexto de XPath.
    xpathContext = xmlXPathNewContext(this->document);

	// Evaluo la expresiòn XPath.
	xpathObject = xmlXPathEvalExpression(
		BAD_CAST "//mapa/lista-cartas-de-juego/carta-de-juego[@tipo='CONQUERCONTINENTGAMECARD']",
		xpathContext);
	// Obtengo  el set de nodos de cartas de juego.
	gameCardNodeSet = xpathObject->nodesetval;

	// Itero por las reglas de conquistar continentes.
	for (int contador = 0; contador < gameCardNodeSet->nodeNr; ++contador) {
		// Obtengo el nodo de carta de juego actual.
		xmlNodePtr gameCardNode = gameCardNodeSet->nodeTab[contador];
		// Obtengo el nombre de la carta de juego.
		std::string nombre = (const char*) xmlGetProp(gameCardNode, BAD_CAST (const xmlChar*) "nombre");
		// Obtengo el nombre del continente.
		std::string continente = (const char*) xmlGetProp(gameCardNode, BAD_CAST (const xmlChar*) "continente");
		// Creo la carta de juego.
		ReferenceCountPtr<GameCard> gameCard(new ConquerContinentGameCard(nombre, continente));
		// Agrego la carta de juego al mapa.
		map->agregarGameCard(gameCard);
	}

	// Evaluo la expresiòn XPath.
	xpathObject = xmlXPathEvalExpression(
		BAD_CAST "//mapa/lista-cartas-de-juego/carta-de-juego[@tipo='CONQUERPLAYERGAMECARD']",
		xpathContext);
    // Obtengo  el set de nodos de cartas de juego.
    gameCardNodeSet = xpathObject->nodesetval;

	// Itero por las cartas de juego.
	for (int contador = 0; contador < gameCardNodeSet->nodeNr; ++contador) {
		// Obtengo el nodo actual.
		xmlNodePtr gameCardNode = gameCardNodeSet->nodeTab[contador];
		// Obtengo nombre de carta de juego.
		std::string nombre = (const char*) xmlGetProp(gameCardNode, BAD_CAST (const xmlChar*) "nombre");
		// Obtengo jugador como string.
		std::string jugadorStr = (const char*) xmlGetProp(gameCardNode, BAD_CAST (const xmlChar*) "jugador");
		// Obtengo jugador.
		int jugador = atoi(jugadorStr.c_str());
		// Creo carta de juego.
		ReferenceCountPtr<GameCard> gameCard(new ConquerPlayerGameCard(nombre, jugador));
		// Agrego carta de juego al mapa.
		map->agregarGameCard(gameCard);
	}	

    // Evaluo la expresiòn XPath.
    xpathObject = xmlXPathEvalExpression(
		BAD_CAST "//mapa/lista-cartas-de-juego/carta-de-juego[@tipo='CONQUERCOUNTRIESGAMECARD']",
		xpathContext);
    // Obtengo  el set de nodos de cartas de juego.
    gameCardNodeSet = xpathObject->nodesetval;
    // Itero por las cartas de juego.
    for (int contador = 0; contador < gameCardNodeSet->nodeNr; ++contador) {
		//Obtengo el nodo actual.
        xmlNodePtr gameCardNode = gameCardNodeSet->nodeTab[contador];
        // Obtengo nombre de carta de juego.
        std::string nombre = (const char*) xmlGetProp(gameCardNode, BAD_CAST (const xmlChar*) "nombre");
        // Obtengo cantidad de paises como string.
        std::string cantidadStr = (const char*) xmlGetProp(gameCardNode, BAD_CAST (const xmlChar*) "cantidad");
        // Obtengo paises.
        int cantidad = atoi(cantidadStr.c_str());
        // Creo carta de juego.
        ReferenceCountPtr<GameCard> gameCard(new ConquerCountriesGameCard(nombre, cantidad));
        // Agrego carta de juego al mapa.
        map->agregarGameCard(gameCard);
    }
}

void MapaParser::saveMap(const std::string& fileName,
	const std::string& imageFileName, ReferenceCountPtr<Mapa>& map) {
    // Define el nodo raiz del documento XML sobre el cual se va a trabajar.
    xmlNodePtr mapNode;

    // Crea el documento XML sobre el cual se va a trabajar.
    this->document = xmlNewDoc(BAD_CAST "1.0");
    // Crea el nodo raiz del documento XML sobre el cual se va a trabajar.
    mapNode = xmlNewNode(NULL, BAD_CAST "mapa");
    // Establece el nodo raìz del documento XML sobre el cual se va a trabajar.
    xmlDocSetRootElement(this->document, mapNode);

	// Persiste la imagen del mapa.
	persistirImagen(mapNode, imageFileName);
    // Persiste los paises del mapa.
    persistirPaises(mapNode, map);
    // Persiste los continentes del map.
    persistirContinentes(mapNode, map);
    // Persiste las reglas del map.
    persistirReglas(mapNode, map);

    // Escribe el documento XML a disco.
    xmlSaveFormatFileEnc(fileName.c_str(), this->document, "UTF-8", 1);

    // Libera el documento XML sobre el cual se va a trabajar.
    xmlFreeDoc(this->document);

    // Libera las variables globales que el parser XML haya inicializado.
    xmlCleanupParser();
}

ReferenceCountPtr<Mapa> MapaParser::loadMap(
    const std::string& fileName) {
    // Defino el mapa que voy a devolver.
    ReferenceCountPtr<Mapa> map = new Mapa();
    // Defino el elemento raiz del documento XML sobre el cual voy a trabajar.
    xmlNodePtr mapNode;

    // Leo el documento XML de disco
    this->document = xmlReadFile(fileName.c_str(), NULL, 0);

    // Obtengo el elemento root del documento XML sobre el cual se va a
    // trabajar.
    mapNode = xmlDocGetRootElement(this->document);

    // Vacio la lista de paises cargados.
    this->paisesCargados.clear();

    // Leo los paises del mapa.
    cargarPaises(mapNode, map);

    // Leo los contientes del mapa.
    cargarContinentes(mapNode, map);

    // Leo las reglas del mapa.
    cargarReglas(mapNode, map);

    // Libera el documento XML sobre el cual se va a trabajar.
    xmlFreeDoc(this->document);

    // Libera las variables globales que el parser XML haya inicializado.
    xmlCleanupParser();

    // Devuelve el mapa cargado.
    return map;
}

MapaParser::~MapaParser() {
    // No realiza ninguna acciòn.
}

