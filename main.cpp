#include "sort.h"
#include<iostream>
#include <random>
#include <chrono>
#include "zsort.h"
#include <algorithm>

int main() {
  std::vector<int> vec = {};
  std::random_device rd; // create a random device to seed the generator
  std::mt19937 gen(rd()); // create a Mersenne Twister engine and seed it with rd

  std::uniform_int_distribution<> dis(-100000, 100000); // create a uniform distribution between 1 and 100

  for (int i = 0; i < 10000; i++) {
    int random_integer = dis(gen);
    vec.push_back(random_integer);
  }
  std::cout << "done generating numbers\n";

  // copy vec for c++ sort
  auto vecCopy = vec;
//  for (int i: vec) {
//    std::cout << i << ", ";
//  }
//  std::cout << "\n";


  auto start = std::chrono::high_resolution_clock::now();
  msort(vec);
  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "took " << duration.count() << " microseconds to msort\n";

  start = std::chrono::high_resolution_clock::now();
  qsort(vec);
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "took " << duration.count() << " microseconds to qsort\n";

  start = std::chrono::high_resolution_clock::now();
  qsort2(vec, 0, vec.size() - 1);
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "took " << duration.count() << " microseconds to qsort2\n";

  start = std::chrono::high_resolution_clock::now();
  std::sort(vecCopy.begin(), vecCopy.end());
  end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "took " << duration.count() << " microseconds to c++ sort\n";

//  for (int i: vec) {
//    std::cout << i << ", ";
//  }
//  std::cout << "\norderd: " << is_vector_ordered(vec) << "\n";
  return 0;
}
