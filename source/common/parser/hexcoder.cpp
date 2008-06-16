#include "hexcoder.h"

char HexCoder::encode(unsigned char unsignedCharacter) {
  if (unsignedCharacter < 26) {
    return 'A'+unsignedCharacter;
  }
  if (unsignedCharacter < 52) {
    return 'a'+(unsignedCharacter-26);
  }
  if (unsignedCharacter < 62) {
    return '0'+(unsignedCharacter-52);
  }
  if (unsignedCharacter == 62) {
    return '+';
  }
  return '/';
}

unsigned char HexCoder::decode(char character) {
  if (character >= 'A' && character <= 'Z') {
    return character - 'A';
  }
  if (character >= 'a' && character <= 'z') {
    return character - 'a' + 26;
  }
  if (character >= '0' && character <= '9') {
    return character - '0' + 52;
  }
  if (character == '+') {
    return 62;
  }
  return 63;
}

bool HexCoder::isBase64(char character) {
  if (character >= 'A' && character <= 'Z') {
    return true;
  }
  if (character >= 'a' && character <= 'z') {
    return true;
  }
  if (character >= '0' && character <= '9') {
    return true;
  }
  if (character == '+') {
    return true;
  }
  if (character == '/') {
    return true;
  }
  if (character == '=') {
    return true;
  }
  return false;
}

std::string HexCoder::encode(const std::vector<unsigned char> & source) {
  std::string retval;
  if (source.size() == 0) {
    return retval;
  }
  for (int i=0; i<source.size(); i+=3) {
    unsigned char by1=0,by2=0,by3=0;
    by1 = source[i];
    if (i+1<source.size()) {
      by2 = source[i+1];
    }
    if (i+2<source.size()) {
      by3 = source[i+2];
    }
    unsigned char by4=0,by5=0,by6=0,by7=0;
    by4 = by1>>2;
    by5 = ((by1&0x3)<<4)|(by2>>4);
    by6 = ((by2&0xf)<<2)|(by3>>6);
    by7 = by3&0x3f;
    retval += encode(by4);
    retval += encode(by5);
    if (i+1<source.size()) {
      retval += encode(by6);
    } else {
      retval += "=";
    }
    if (i+2<source.size()) {
      retval += encode(by7);
    } else {
      retval += "=";
    }
    if (i % (76/4*3) == 0) {
      retval += "\r\n";
    }
  }
  return retval;
}

std::vector<unsigned char> HexCoder::decode(const std::string & _str) {
  std::string str;
  for (int j=0;j<_str.length();j++) {
    if (isBase64(_str[j])) {
      str += _str[j];
    }
  }
  std::vector<unsigned char> retval;
  if (str.length() == 0) {
    return retval;
  }
  for (int i=0;i<str.length();i+=4) {
    char c1='A',c2='A',c3='A',c4='A';
    c1 = str[i];
    if (i+1<str.length()) {
      c2 = str[i+1];
    }
    if (i+2<str.length()) {
      c3 = str[i+2];
    }
    if (i+3<str.length()) {
      c4 = str[i+3];
    }
    unsigned char by1=0,by2=0,by3=0,by4=0;
    by1 = decode(c1);
    by2 = decode(c2);
    by3 = decode(c3);
    by4 = decode(c4);
    retval.push_back( (by1<<2)|(by2>>4) );
    if (c3 != '=') {
      retval.push_back( ((by2&0xf)<<4)|(by3>>2) );
    }
    if (c4 != '=') {
      retval.push_back( ((by3&0x3)<<6)|by4 );
    }
  }
  return retval;
}
