#include "texture.h"
#include<iostream>

Texture::Texture():
    width(0),
    height(0),
    loaded(false) {
}

Texture::~Texture() {

}

int Texture::getWidth() const {
    return width;
}

void Texture::setWidth(int theWidth) {
    width = theWidth;
}

int Texture::getHeight() const {
    return height;
}

void Texture::setHeight(int theHeight) {
    height = theHeight;
}

GLuint Texture::getTextureName() const {
    return textureName;
}

void Texture::load(const std::string& fileName) {
    // Load the image
    SDL_Surface* image = IMG_Load(fileName.c_str());
    // Define el formato.
    GLuint format;
    // If the image has been created
    if (image == NULL) {
        loaded = false;
    } else {
        // Calculate the format of the image, RGB or RGBA
        SDL_PixelFormat *imageFormat = image->format;

        if (imageFormat->BytesPerPixel == 3)// RGB 24bit
            format = GL_RGB;
        else if (imageFormat->BytesPerPixel == 4)// RGBA 32bit
            format = GL_RGBA; 

        // Calculate the dimension of the image
        setWidth(image->w);
        setHeight(image->h);

        // Create the texture
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glGenTextures(1, &textureName);
        glBindTexture(GL_TEXTURE_2D, textureName);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, format,
                         GL_UNSIGNED_BYTE, image->pixels);
        // Libera la surface.
        SDL_FreeSurface(image);
        // Cambia a matriz de textura y rota la textura.
        glMatrixMode(GL_TEXTURE);
        glRotatef(180.0f,0.0f,0.0f,1.0f);
        glScalef(-1.0f,1.0f,1.0f);
        // Vuelve a la matriz de model view
        glMatrixMode(GL_MODELVIEW);
        // Mark the image as loaded
        loaded = true;
    }
}


bool Texture::isLoaded() const {
    return loaded;
}

