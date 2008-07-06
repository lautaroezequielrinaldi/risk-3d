#ifndef __MAPPOSITION_H__
#define __MAPPOSITION_H__

class MapPosition {
    /**
     * Atributos privados de la clase MapPosition.
     */
    private:
        /**
         * Almacena la posicion x dentro del mapa.
         */
        int x;
        /**
         * Almacena la posicion y dentro del mapa.
         */
        int y;

    /**
     * Mètodos pùblicos de la clase MapPosition.
     */
    public:
        /**
         * Constructor de la clase MapPosition.
         */
        MapPosition(const int& x, const int& y);
        /**
         * Establece la posicion x dentro del mapa.
         */
        void setX(const int& x);
        /**
         * Obtiene la posicion x dentro del mapa.
         */
        int& getX();
        /**
         * Establece la posicion y dentro del mapa.
         */
        void setY(const int& y);
        /**
         * Obtiene la posicion y dentro del mapa.
         */
        int& getY();
        /**
         * Operador de igualdad.
         */
        bool operator==(const MapPosition& position);
        /**
         * Destructor virtual de la clase MapPosition.
         */
        virtual ~MapPosition();
};

#endif /** __MAPPOSITION_H__ */

