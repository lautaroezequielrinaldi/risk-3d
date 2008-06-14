#ifndef __HEXCODER__
#define __HEXCODER__

#include<string> // Para definicion de std::string.

/**
 * Clase para encodear y desencodear en base64
 */
class HexCoder {
	/**
	 * Metodos publicos de la clase HexCoder.
	 */
	public:
		/**
		 * Encodea una cadena de bytes a base64 encoding.
		 */
		static std::string encode(unsigned char const* , unsigned int len);
		/**
		 * Desencodea una cadena de bytes de base64 encoding.
		 */
		static std::string decode(std::string const& s);
};

#endif

