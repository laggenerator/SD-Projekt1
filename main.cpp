#include <stdio.h>
#include <fstream>
#include "list.hh"
#include "dynamic_array.hh"
#include "generator.hh"
#include "testy.hh"
#include <chrono>

uint16_t nasiona[30] = {
  5721, 9099, 9297, 4926, 1932, 8005, 5359, 6302, 3996, 7585,
  2166, 9239, 9836, 7005, 4716, 9899, 1660, 9596, 2629, 7284,
  3074, 4435, 420, 2137, 3869, 8677, 1894, 6278, 2892, 1083
};


int main(int argc, char* argv[]){
  if(argc != 2){
    std::cout << "Wszystkie testy [0] |\nPush_front() [1]| Push_back() [2] | Push_at() [3] |\nRemove_front() [4] | Remove_back() [5] | Remove_at() [6] |\nat_position() [7] | find() [8]\n";
    return 1;
  }
  int test = std::stoi(argv[1]);
  if(test < 0 || test > 8){
    std::cout << "Niewłaściwa wartość argumentu\n";
    return 1;
  }
  int (*funkcje[])(uint16_t, uint8_t) = {
    push_front, push_back, push_at, 
    remove_front, remove_back, remove_at, 
    at_position, find
  };

  
  if(test == 0){
    for(int i=0;i<8;i++){
      funkcje[i](nasiona[0], 0);
      std::cout << i+1 << "/" << 8 << std::endl;
    }
    std::cout << "Sukces!\n";
  } else {
    funkcje[test-1](nasiona[0], 0);
    std::cout << "Sukces!\n";
  }
  return 0;
}
