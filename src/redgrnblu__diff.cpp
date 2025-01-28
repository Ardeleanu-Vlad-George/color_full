#include "redgrnblu.hpp"
#include <cstdio>
#include <cmath>

redgrnblu::diff::diff(redgrnblu& c1, redgrnblu& c2)
  :dr(c1.r - c2.r),dg(c1.g - c2.g),db(c1.b - c2.b)
    {}

std::string redgrnblu::diff::to_string(){
  char rslt[211];
  sprintf(rslt, "[%+04d]:[%+04d]:[%+04d]", dr, dg, db);
  return std::string(rslt);
}

double redgrnblu::diff::mod(){
  return sqrt(dr*dr+dg*dg+db*db);
}
