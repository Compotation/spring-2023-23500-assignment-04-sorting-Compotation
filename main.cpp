#include "sort.h"
#include<iostream>

int main() {
  std::vector<int> vec = {8,3,-1,6,2, -100, 2, 30, -20, 30, -1000, 100};
  int low = 0;
  int high = vec.size()-1;
  qsort2(vec, 0, vec.size()-1);
  //std::cout << vec.size() << "\n";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << ",";
  }
  std::cout << std::endl;
  return 0;
}
