#ifndef __CROSSHAIRSTATE_H__
#define __CROSSHAIRSTATE_H__

class CrossHairState {
    /**
     * Atributos privados de la class CrossHairState.
     */
    private:
        /**
         * Almacena la latitud en la esfera.
         */
        double latitude;
        /**
         * Almacena la longitud en la esfera.
         */
        double longitude;
        /**
         * Almacena si el crosshari se encuentra en la esfera o no.
         */
        bool inSphere;

    /**
     * Metodos publicos de la clase CrossHairState.
     */
    public:
        /**
         * Constructor de la clase CrossHairState.
         */
        CrossHairState(const double& latitude = 500.0,
            const double& longitude = 500.0, const bool& inSphere = false);
        /**
         * Destructor virtual de la clase CrossHairState.
         */
        virtual ~CrossHairState();
        /**
         * Establece la latitud.
         */
        void setLatitude(const double& latitude);
        /**
         * Obtiene la latitud,
         */
        double getLatitude() const;
        /**
         * Establece la longitud,
         */
        void setLongitude(const double& longitude);
        /**
         * Obtiene la longitud.
         */
        double getLongitude() const;
        /**
          * Almacena si el cross hair esta en la esfera.
          */
        void setInSphere(const bool& inSphere);
        /**
         * Obtiene si el cross hair esta en la esfera.
         */
        bool getInSphere() const;
};

#endif /** __CROSSHAIRSTATE_H__ */

