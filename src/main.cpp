#include "io.hpp"
#include "redgrnblu.hpp"
#include <cstring>

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
