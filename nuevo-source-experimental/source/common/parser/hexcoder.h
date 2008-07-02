#ifndef __HEXCODER__
#define __HEXCODER__

#include<string>
#include<vector>

/**
 * Clae HexCoder que se encarga de encodear a base 64.
 */
class HexCoder {
  private:
    static char encode(unsigned char unsignedCharacter);
    static unsigned char decode(char character);
    static bool isBase64(char character);
  public:
    static std::string encode(const std::vector<unsigned char> & source);
    static std::vector<unsigned char> decode(const std::string & source);
};

#endif

