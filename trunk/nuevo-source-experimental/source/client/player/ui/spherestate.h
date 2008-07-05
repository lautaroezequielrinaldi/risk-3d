#ifndef __SPHERESTATE_H__
#define __SPHERESTATE_H__

#include "mathconstants.h"

class SphereState {
    /**
     * Atributos privados de la clase SphereState.
     */
    private:
        /**
         * Almacena el ultimo timepo en que se giro la esfera.
         */
        double lastTime;
        /**
         * Almacena el angulo de rotacion alpha.
         */
        float alpha;
        /**
         * Almacena el angulo de rotacion beta.
         */
        float beta;
        /**
         * Almacena la distancia.
         */
        float distance;

    /**
     * Metodos publicos de la clase  SphereState.
     */
    public:
        /**
         * Constructor de la clase SphereState.
         */
        SphereState(const double& lastTime = 0.0, const float& alpha = 0.0,
            const float& beta = 0.0, const float& distance = 4.0);
        /**
         * Destructor virtual de la clase SphereState.
         */
        virtual ~SphereState();
        /**
         * Obtiene la ultima vez que se giro la esfera,
         */
        double getLastTime() const;
        /**
         * Establece la ultima vez que se giro la esfera.
         */
        void setLastTime(double lastTime);
        /**
         * Obtiene el angulo alpha.
         */
        float getAlpha() const;
        /**
         * Obtiene el angulo beta.
         */
        float getBeta() const;
        /**
         * Obtiene la distancia.
         */
        float getDistance() const;
        /**
         * Incrementa el angulo alfa en el tiempo.
         */
        void incrementAlphaInTime(double deltaTime);
        /**
         * Decrementa el angulo alfa en el tiempo.
         */
        void decrementAlphaInTime(double deltaTime);
        /**
         * Incrementa el angulo beta en el tiempo.
         */
        void incrementBetaInTime(double deltaTime);
        /**
         * Decrementa el angulo beta en el tiempo.
         */
        void decrementBetaInTime(double deltaTime);
         /**
          * Incrementa la distancia en el tiempo.
          */
        void incrementDistanceInTime(double deltaTime);
        /**
         * Decrementa la distancia en el tiempo.
         */
        void decrementDistanceInTime(double deltaTime);
        /**
          * Ajusta alpha.
          */
        void adjustAlpha();
        /**
         * Ajusta beta.
         */
        void adjustBeta();
        /**
         * Ajusta distancia.
         */
        void adjustDistance();
};

#endif /** __SPHERESTATE_H__ */

