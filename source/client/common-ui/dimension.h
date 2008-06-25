#ifndef __DIMENSION_H__
#define __DIMENSION_H__

class Dimension {
	/**
	 * Atributos privados de la clase Dimension.
	 */
	private:
		/**
		 * Almacena la coordenada x de la dimension.
		 */
		int x;
		/**
		 * Almacena la coordenada y de la dimension.
		 */
		int y;
		/**
		 * Almacena el ancho de la dimension.
		 */
		int width;
		/**
		 * Almacena el alto de la dimension.
		 */
		int height;

	/**
	 * Metodos publicos de la clase Dimension.
	 */
	public:
		/**
		 * Constructor de la clase Dimension.
		 */
		Dimension(const int& x = 0, const int& y = 0, const int& width = 0, const int& height = 0);
		/**
		 * Obtiene la coordenada x.
		 */
		int getX();
		/**
		 * Establece la coordenada x.
		 */
		void setX(const int& x);
		/**
		 * Obtiene la coordenada y.
		 */
		int getY();
		/**
		 * Establece la coordenada y.
		 */
		void setY(const int& y);
		/**
		 * Obtiene el ancho.
		 */
		int getWidth();
		/**
		 * Establece el ancho.
		 */
		void setWidth(const int& width);
		/**
		 * Obtiene el alto.
		 */
		int getHeight();
		/**
		 * Establece el alto.
		 */
		void setHeight(const int& height);
		/**
		 * Verifica si contiene un punto x,y.
		 */
		bool contains(const int& x, const int& y); 
};

#endif /** __DIMENSION_H__ */

