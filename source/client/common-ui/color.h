#ifndef __COLOR_H__
#define __COLOR_H__

class Color {
	/**
	 * Atributos publicos de la clase Color.
	 */
	public:
		/**
		 * Constante que representa el color blanco.
		 */
		static const Color WHITE;
		/**
		 * Constante que representa el color negro.
		 */
		static const Color BLACK;
		/**
		 * Constante que representa el color gris.
		 */
		static const Color GRAY;
		/**
 		 * Constante que representa el color rojo.
 		 */
		static const Color RED;
		/**
 		 * Constante que representa el color verde.
 		 */
		static const Color GREEN;
		/**
		 * Constante que representa el color azul.
		 */
		static const Color BLUE;

	/**
	 * Atributos privados de la clase Color.
	 */
	private:
		/**
		 * Almacena el valor de rojo.
		 */
		float red;
		/**
		 * Almacena el valor de verde.
		 */
		float green;
		/**
		 * Almacena el valor de azul.
		 */
		float blue;

	/**
	 * Metodos publicos de la clase Color.
	 */
	public:
		/**
		 * Constructor de la clase Color.
		 */
		Color(const float& red = 0.0f, const float& green = 0.0f, const float& blue = 0.0f);
		/**
		 *  Obtiene el valor de rojo.
		 */
		float getRed();
		/**
		 * Establece el valor de rojo.
		 */
		void setRed(const float& red);
        /**
		 *  Obtiene el valor de verde.
		 */
        float getGreen();
        /**
		 * Establece el valor de verde.
		 */
        void setGreen(const float& green);
        /**
		 * Obtiene el valor de azul.
		 */
        float getBlue();
        /**
		 * Establece el valor de azul.
		 */
        void setBlue(const float& blue);

};

#endif /** __COLOR_H__ */


