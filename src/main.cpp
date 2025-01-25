#include <iostream>
#include <SFML/Graphics.hpp>

int main(){
  sf::Image img;
  int temp;
  img.loadFromFile("data/green_gecko.jpg");
  sf::Uint8 *data = (sf::Uint8*) img.getPixelsPtr();
  sf::Vector2u size = img.getSize();
  int x = size.x, y = size.y;
  for(int itr=0; itr < x*y; itr++){
    temp = data[4*itr];
    data[4*itr] = data[4*itr+1];
    data[4*itr+1] = temp;
    /*data[4*itr]+=(sf::Uint8)200;*/
    /*data[4*itr+1]+=(sf::Uint8)200;*/
    /*data[4*itr+2]+=(sf::Uint8)200;*/
  }
  img.saveToFile("data/shifted_gecko.jpg");
  return 0;
}
