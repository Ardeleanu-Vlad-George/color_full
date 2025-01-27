#ifndef _REDGRNBLU_HPP_
#define _REDGRNBLU_HPP_

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class redgrnblu;

std::ostream& operator<<(std::ostream&, redgrnblu&);

class redgrnblu{ 
private:
  int r, g, b;
public:
  redgrnblu(char *code);
  operator sf::Color();
  friend std::ostream& operator<<(std::ostream&, redgrnblu&);

  class diff{
  private:
    int dr, dg, db;
  public:
    diff(redgrnblu& c1, redgrnblu& c2);
    std::string to_string();
  };

  diff operator-(redgrnblu&);
};

#endif//_REDGRNBLU_HPP_
