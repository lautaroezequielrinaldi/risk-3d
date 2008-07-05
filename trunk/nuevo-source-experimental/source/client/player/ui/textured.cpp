#include "textured.h"

Textured::Textured():
    texture() {
    // No realiza ninguna accion.
}

Textured::Textured(const Texture& theTexture):
    texture(theTexture) {
    // No realiza ninguna accion.
}

Textured::~Textured() {
    // No realiza ninguna accion.
}

void Textured::enableTexture() {
    if ( texture.isLoaded() ) {
        glEnable( GL_TEXTURE_2D );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
        glEnable(GL_TEXTURE_GEN_S);
        glEnable(GL_TEXTURE_GEN_T);
        glBindTexture( GL_TEXTURE_2D, texture.getTextureName() );
    }
}


void Textured::disableTexture() {
    if ( texture.isLoaded() ) {
        glDisable(GL_TEXTURE_GEN_S);
        glDisable(GL_TEXTURE_GEN_T);
        glDisable( GL_TEXTURE_2D );
    }
}

void Textured::setTexture(const Texture& theTexture) {
    texture = theTexture;
}

Texture& Textured::getTexture(){
    return texture;
}

const Texture& Textured::getTexture() const {
    return texture;
}

