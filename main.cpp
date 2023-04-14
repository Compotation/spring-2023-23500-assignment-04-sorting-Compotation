#include "sort.h"
#include<iostream>

int main() {
  std::vector<int> vec = {8};
  qsort2(vec, 0, vec.size()-1);
  //std::cout << vec.size() << "\n";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << ",";
  }
  std::cout << std::endl;
  return 0;
}
