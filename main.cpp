#include "sort.h"
#include<iostream>

int main() {
  std::vector<int> vec = {8, 2, 10, 1};
  auto sorted = qsort(vec);
  for (int i = 0; i < sorted.size(); i++) {
    std::cout << sorted[i] << ",";
  }
  std::cout << std::endl;
  return 0;
}
