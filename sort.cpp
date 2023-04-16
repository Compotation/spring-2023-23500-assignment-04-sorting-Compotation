#include "sort.h"
#include<iostream>
#include <algorithm>

void qsort2(std::vector<int> &vec, int low, int high) {
  if (low >= high) {
    return;
  }
//    std::cout << "params: " << low << " | " << (int) ((low + high) / 2) << " | " << high << "\n";
  // base case
  // changed to < to sort subarray of 2
  if (high - low < 1) {
    return;
  }

  int pivotIndex = medianIndex(vec, low, (int) ((low + high) / 2), high);
  int pivot = vec[pivotIndex];
//  std::cout << "pivot index: " << pivotIndex << " pivot: " << pivot << "\n";


  std::swap(vec[pivotIndex], vec[high]);
  pivotIndex = low;
  for (int j = low; j < high; j++) {
    if (vec[j] < pivot) {
      std::swap(vec[pivotIndex], vec[j]);
      pivotIndex++;
    }
  }
  std::swap(vec[pivotIndex], vec[high]);
//    std::cout << "current run: \n";
//    for (int i : vec) {
//      std::cout << i << " , ";
//    }
//    std::cout << "\n";

  // lower
  //std::cout << "lower: " << low << "|" << pivotIndex-1 << "\n";
  qsort2(vec, low, pivotIndex - 1);
  //higher
  //std::cout << "higher: " << pivotIndex+1 << " | " << high << "\n ";
  qsort2(vec, pivotIndex + 1, high);
}

int medianIndex(std::vector<int> &vec, int firstIndex, int middleIndex, int lastIndex) {
  if (vec[firstIndex] > vec[middleIndex]) {
    std::swap(vec[firstIndex], vec[middleIndex]);
  }
  if (vec[middleIndex] > vec[lastIndex]) {
    std::swap(vec[middleIndex], vec[lastIndex]);
  }
  if (vec[firstIndex] > vec[middleIndex]) {
    std::swap(vec[firstIndex], vec[middleIndex]);
  }
  return middleIndex;
}

bool is_vector_ordered(const std::vector<int> &v) {
  for (std::vector<int>::size_type i = 1; i < v.size(); i++) {
    if (v[i] < v[i-1]) {
      return false;
    }
  }
  return true;
}
