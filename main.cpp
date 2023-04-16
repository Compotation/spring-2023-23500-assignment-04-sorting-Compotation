#include "sort.h"
#include<iostream>
#include <random>

int main() {
  std::vector<int> vec = {};
  std::random_device rd; // create a random device to seed the generator
  std::mt19937 gen(rd()); // create a Mersenne Twister engine and seed it with rd

  std::uniform_int_distribution<> dis(-100000000, 1000000000); // create a uniform distribution between 1 and 100

  for (int i = 0; i < 50000; i++) {
    int random_integer = dis(gen);
    vec.push_back(random_integer);
  }
  // {37, 21, 14, 6, 50, 9, 28, 42, 16, 33, 47, 19, 3, 38, 12, 45, 31, 55, 77, 2, 91, 63, 10, 24, 98, 13, 40, 27, 83, 57, 18, 75, 22, 94, 41, 67, 7}
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
  std::cout << vec[i] << ", ";
}
std::cout << "\norderd: " << is_vector_ordered(vec) << "\n";
  return 0;
}
