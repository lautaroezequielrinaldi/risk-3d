#ifndef __TEXTURED_H__
#define __TEXTURED_H__

#include "texture.h"

class Textured {
    /**
     * Atributos privados de la clase Textured.
     */
    private:
        /**
         * Almacena la textura.
         */
        Texture texture;
    /**
     * Metodos protegidos de la clase Textured.
     */
    protected:
        /**
         * Habilita la textura,
         */
        void enableTexture();
        /**
         * Deshabilita la textura.
         */
        void disableTexture();
    /**
     * Metodos publicos de la clase Textured.
     */
    public:
        /**
         * Constructor de la clase Textured.
         */
        Textured();
        /**
         * Constructor de la clase Textured.
         */
        Textured(const Texture& texture);
        /**
         * Destructor virtual de la clsae Textured.
         */
        virtual ~Textured();
        /**
         * Obtiene la textura.
         */
        Texture& getTexture();
        /**
         * Obtiene la textura.
         */
        const Texture& getTexture() const;
        /**
         * Establece la textura.
         */
        void setTexture(const Texture& theTexture);
};

#endif /** __TEXTURED_H__ */

