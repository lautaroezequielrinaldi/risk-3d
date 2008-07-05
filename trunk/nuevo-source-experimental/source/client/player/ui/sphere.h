#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "uistate.h"
#include "texture.h"
#include "textured.h"

class Sphere: public Textured {
    /**
     * Atributos privados de la clase Sphere.
     */
    private:
        /**
         * Almacena el estado de la user interface,
         */
        UIState& uiState;
        /**
         * Almacena el Quad Object representando a la esfera.
         */
        GLUquadric* sphereQuad;

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
     * Mètodos publicos de la clase Sphere.
     */
    public:
        /**
         * Constructor de la clase Sphere.
         */
        Sphere(UIState& uiState);
        /**
         * Constructor de la clse Sphere.
         */
        Sphere(UIState& uiState, const Texture& texture);
        /**
         * Destructor virtual de la clase Sphere.
         */
        virtual ~Sphere();
        /**
         * Hace update.
         */
        void update();
        /**
         * Dibuja.
         */
        void draw();
};

#endif /** __SPHERE_H__ */

