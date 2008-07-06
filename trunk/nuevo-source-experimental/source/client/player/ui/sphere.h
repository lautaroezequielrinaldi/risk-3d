#ifndef __SPHERE_H__
#define __SPHERE_H__

#include<cmath>
#include "math3d.h"
#include "ray_cyl.h"
#include "uistate.h"
#include "texture.h"
#include "textured.h"
#include "spherestate.h"
#include "crosshairstate.h"
#include "../../../common/model/game.h"
#include "../../../common/smartpointer/referencecountptr.h"

class Sphere: public Textured {
    /**
     * Atributos privados de la clase Sphere.
     */
    private:
        /**
         * Almacena una referencia al juego actual.
         */
        ReferenceCountPtr<Game> game;
        /**
         * Almacena el estado de la user interface,
         */
        UIState& uiState;
        /**
         * Almacena el esatdo de la esfera.
         */
        SphereState sphereState;
        /**
         * Almacena el estado del cross hair.
         */
        CrossHairState crossHairState;
        /**
         * Almacena el viewpoint de la esfera.
         */
        Point3 viewpoint;
        /**
         * Almacena el Quad Object representando a la esfera.
         */
        GLUquadric* sphereQuad;
        /**
         * Almacena el Quad Object representando al pais.
         */
        GLUquadric* countryQuad;
        /**
         * Guarda una referencia al pais bajo el mouse.
         */
        ReferenceCountPtr<Pais> hooverCountry; 

    /**
     * Mètodos privados de la clase Sphere,
     */
    private:
        /**
         * Inicializa el Quad Object representando a la esfra,
         */
        void initializeQuad();
        /**
         * Termina el Quad Object representando a la esfera.
         */
        void terminateQuad();

    /**
     * Metodo privado de la clase Sphere.
     */
    private:
        /**
         * Verifica si una posicion de mapa del modelo intersecta con la esfera.
         */
        bool countryRayIntersection(MapPosition& position,
            Point3 rayStart, Vector3 rayDir);
    /**
     * Mètodos publicos de la clase Sphere.
     */
    public:
        /**
         * Constructor de la clase Sphere.
         */
        Sphere(UIState& uiState, const ReferenceCountPtr<Game>& game = NULL);
        /**
         * Constructor de la clse Sphere.
         */
        Sphere(UIState& uiState, const Texture& texture,
            const ReferenceCountPtr<Game>& game = NULL);
        /**
         * Destructor virtual de la clase Sphere.
         */
        virtual ~Sphere();
        /**
         * Establece el game.
         */
        void setGame(const ReferenceCountPtr<Game>& game);
        /**
         * Obtiene el pais bajo el cursor.
         */
        ReferenceCountPtr<Pais> getHooverCountry();
        /**
         * Hace update.
         */
        void update();
        /**
         * Updatea la esfera.
         */
        void updateSphere(const double& deltaTime);
        /**
         * Actualiza el crosshair and countries.
         */
        void updateCrossHairAndCountries();
        /**
         * Dibuja.
         */
        void draw();
        /**
         * Dibuja la esfera.
         */
        void drawSphere(); 
        /**
         * Dibuja el crosshair.
         */
        void drawCrossHair();
        /**
         * Dibuja los paises en la esfera.
         */
        void drawCountries();
};

#endif /** __SPHERE_H__ */

