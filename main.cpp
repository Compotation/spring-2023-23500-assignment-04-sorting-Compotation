#include "sort.h"
#include<iostream>

int main() {
  std::vector<int> vec = {3,6,-1,8, 2, -100, 2, 30, -20, 30, -1000, 100};
  // 2, -100, 2, 30, -20, 30, -1000, 100
  /*
  std::vector<int> vec1 = {7, 0, 9, 6, 5};
  int low = 2;
  int high = vec1.size()-1;
  std::cout << "middle: " << (int)((low + high)/2) << "\n";
  std::cout << medianIndex(vec1, low, (int)((low + high)/2), high);
*/
qsort2(vec, 0, vec.size()-1);
//std::cout << vec.size() << "\n";
for (int i = 0; i < vec.size(); i++) {
  std::cout << vec[i] << ",";
}
std::cout << std::endl;
  return 0;
}
