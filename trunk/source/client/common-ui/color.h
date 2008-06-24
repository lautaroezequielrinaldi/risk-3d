#ifndef __COLOR_H__
#define __COLOR_H__

/**
 * Defino la estructura color.
 */
struct Color {
	/**
	 * Almacena el color rojo.
	 */
	float red;
	/**
	 * Almacena el color verde.
	 */
	float green;
	/**
	 * Almacena el color azul.
	 */
	float blue;
	/**
	 * Constructor de la clase Color.
	 */
	Color(const float& red = 0, const float& green = 0, const float& blue = 0):
		red(red),
		green(green),
		blue(blue) {
		// No realiza ninguna accion.
	}
};

#endif /** __COLOR_H__ */

