#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include<string>
#include<SDL.h>
#include<SDL/SDL_image.h>
#include<GL/gl.h>
#include<GL/glu.h>

class Texture {
    /**
     * Atributos privados de la clase Texture.
     */
    private:
        int width;
        int height;
        GLuint textureName;
        bool loaded;

    /**
     * Metodos publicos de la clase Texture.
     */
    public:
        /**
         * Constructor of the Texture class.
         */
        Texture();
    
        /**
         * Virtual destructor of the Texture class.
         */
        virtual ~Texture();
    
        int getWidth() const;
        void setWidth(int theWidth);
    
        int getHeight() const;
        void setHeight(int theHeight);
    
        GLuint getTextureName() const;
    
        // Functions for loading a texture from a file
        void load(const std::string& filename);
        bool isLoaded() const;
};

#endif /** __TEXTURE_H__ */

