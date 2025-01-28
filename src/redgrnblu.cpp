#include "redgrnblu.hpp"
#include <cstdio>

redgrnblu::redgrnblu(char *code){
  sscanf(code, "%02x%02x%02x", &r, &g, &b);
}

redgrnblu::operator sf::Color(){
  return sf::Color(r, g, b);
}

std::ostream& operator<<(std::ostream& os, redgrnblu& rgb){
  char rslt[311];
  sprintf(rslt, "(%03d, %03d, %03d)", rgb.r, rgb.g, rgb.b);
  return os<<rslt;
}

redgrnblu::diff redgrnblu::operator-(redgrnblu& c){
  return redgrnblu::diff(*this, c);
}

