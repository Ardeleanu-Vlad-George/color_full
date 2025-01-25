#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>

void log_help(std::ostream& os){
  os<<"Give two RGB hex codes, '#' must be omited\n";
}

int main(int argc, char *argv[]){
  if(2 == argc && 0 == strcmp(argv[1], "help")){
    log_help(std::clog);
    return 1;
  }
  if(3 != argc){
    log_help(std::cerr<<"Not enough arguments were given\n");
    return -1;
  }
  std::cout<<"Normal behaviour\n";
  return 0;
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
