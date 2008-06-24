#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

class Rectangle {
	/**
	 * Atributos privados de la clase Rectangle.
	 */
	private:
		int x;
		int y;
		int width;
		int height;
	public:
		/**
		 * Constructor de la clase Rectangle.
		 */
		Rectangle();
		/**
		 * Constructor de la clase Rectangle.
		 */
		Rectangle(const int& x, const int& y, const int& width,
			const int& height);
		/**
		 * Obtiene la posicion X del rectangulo.
		 */
		int getX();
		/**
		 * Establece la posicion X del rectangulo.
		 */
		void setX(const int& x);
        /**
         * Obtiene la posicion Y del rectangulo.
         */
        int getY();
        /**
		 * Establece la posicion Y del rectangulo.
		 */
        void setY(const int& y);
		/**
		 * Obtiene el ancho del rectangulo.
		 */
		int getWidth();
		/**
		 * Establece el ancho del rectangulo.
		 */
		void setWidth(const int& width);
		/**
		 * Obtiene el alto del rectangulo.
		 */
		int getHeight();
		/**
		 * Establece el alto del rectangulo.
		 */
		void setHeight(const int& height);
		/**
		 * Verifica si contiene a un punto.
		 */
		bool contains(const int& x, const int& y);
		/**
		 * Destructor virtual de la clase Rectangle.
		 */
		virtual ~Rectangle();
};

#endif /** __RECTANGLE_H__ */

