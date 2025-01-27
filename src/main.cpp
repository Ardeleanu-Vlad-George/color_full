#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>

class redgrnblu;

std::ostream& operator<<(std::ostream&, redgrnblu&);

class redgrnblu{ 
private:
  int r, g, b;
public:
  redgrnblu(char *code){
    sscanf(code, "%02x%02x%02x", &r, &g, &b);
  }
  operator sf::Color(){
    return sf::Color(r, g, b);
  }
  friend std::ostream& operator<<(std::ostream&, redgrnblu&);
  class diff{
  private:
    int dr, dg, db;
  public:
    diff(redgrnblu& c1, redgrnblu& c2)
      :dr(c1.r - c2.r),dg(c1.g - c2.g),db(c1.b - c2.b)
        {}
    std::string to_string(){
      char rslt[211];
      sprintf(rslt, "[%+04d]:[%+04d]:[%+04d]", dr, dg, db);
      return std::string(rslt);
    }
  };

  diff operator-(redgrnblu& c){
    return diff(*this, c);
  }
};

std::ostream& operator<<(std::ostream& os, redgrnblu& rgb){
  char rslt[311];
  sprintf(rslt, "(%03d, %03d, %03d)", rgb.r, rgb.g, rgb.b);
  return os<<rslt;
}

void log_help(std::ostream& os){
  os<<"Give two RGB hex codes, '#' must NOT be included\n";
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
  redgrnblu source(argv[1]), target(argv[2]);
  std::cout<<"1st color :"<<source<<'\n';
  std::cout<<"2nd color :"<<target<<'\n';
  redgrnblu::diff shift = source-target;
  std::cout<<"difference:"<<shift.to_string()<<'\n';
  return 0;
}
