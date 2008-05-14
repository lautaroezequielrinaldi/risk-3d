#ifndef __UISUPPORT_H__
#define __UISUPPORT_H__

/**
 * Clase cuyo propòsito es brindar soporte y facilidades a còdigo de interfaz
 * grafica de usuario. Proveyendo metodos para saber si el mouse se encuentra
 * posicionado sobre un àrea determinada de la pantalla y demàs funcionalidad
 * relacionada. Es una clase estàtica.
 */
class UISupport {
    /**
     * Mètodos pùblicos de la clase UISupport.
     */
    public:
        /**
         * Mètodo para verificar si el mouse se encuentra sobre una posiciòn
         * determinada de la pantalla, delimitada por x, y, width, height.
         */
        static bool isMouseOver(const UIMouseInformation& mouseInformation, int x,
            int y, int width, int height);
};

#endif /** __UISUPPORT_H__ */

