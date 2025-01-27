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

redgrnblu::diff::diff(redgrnblu& c1, redgrnblu& c2)
  :dr(c1.r - c2.r),dg(c1.g - c2.g),db(c1.b - c2.b)
    {}

std::string redgrnblu::diff::to_string(){
  char rslt[211];
  sprintf(rslt, "[%+04d]:[%+04d]:[%+04d]", dr, dg, db);
  return std::string(rslt);
}

redgrnblu::diff redgrnblu::operator-(redgrnblu& c){
  return redgrnblu::diff(*this, c);
}

