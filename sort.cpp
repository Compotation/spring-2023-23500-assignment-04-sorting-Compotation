#include "sort.h"
#include<iostream>

std::vector<int> qsort2(std::vector<int> &vec, int low, int high) {
  std::cout << "params: " << low << " | " << (int) ((low + high) / 2) << " | " << high << "\n";
  // base case
  // changed to < to sort subarray of 2
  if (high - low < 1) {
    return vec;
  }

  // select pivot value
  // for now we'll just pick list[0]
  int pivotIndex = medianIndex(vec, low, (int) ((low + high) / 2), high);
  int pivot = vec[pivotIndex];
  std::cout << "pivot index: " << pivotIndex << " pivot: " << pivot << "\n";


  // copy all the values < pivot to lower
  // copy all the values >= pivot to higher;
  // should check last index
  //make separate loops for each pivot type
  std::cout << "pivot: ";
  if (pivotIndex == low) {
    std::cout << "low\n";
    for (int i = low + 1; i <= high; i++) {
      if (vec[i] < pivot) {
        int value = vec[i];
        vec.erase(vec.begin() + i);
        vec.insert(vec.begin() + pivotIndex, value);
        pivotIndex++;
      }
    }
  } else if (pivotIndex == high) {
    std::cout << "high\n";
    for (int i = low; i < pivotIndex; i++) {
      if (vec[i] > pivot) {
        int value = vec[i];
        vec.erase(vec.begin() + i);
        vec.insert(vec.begin() + pivotIndex, value);
        pivotIndex--;
      }
    }
  } else {
    std::cout << "mid\n";
    for (int i = low; i <= high; i++) {
      if (i == pivotIndex) {
        std::cout << "skipped pivot";
      } else if (vec[i] < pivot && i > pivotIndex) {
        int value = vec[i];
        vec.erase(vec.begin() + i);
        vec.insert(vec.begin() + pivotIndex, value);
        pivotIndex++;
      } else if (vec[i] >= pivot && i < pivotIndex) {
        int value = vec[i];
        vec.erase(vec.begin() + i);
        vec.insert(vec.begin() + pivotIndex, value);
        pivotIndex--;
        // so it looks at the item after removed item (index after i)
        i--;
      }
    }
  }
  std::cout << "current run: \n";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " , ";
  }
  std::cout << "\n";

  // make our recursive calls
  // lower
  //std::cout << "lower: " << low << "|" << pivotIndex-1 << "\n";
  qsort2(vec, low, pivotIndex - 1);
  //higher
  //std::cout << "higher: " << pivotIndex+1 << " | " << high << "\n ";
  qsort2(vec, pivotIndex + 1, high);

  // return the sorted list
  return vec;
}

int medianIndex(std::vector<int> &vec, int firstIndex, int middleIndex, int lastIndex) {
  if ((vec[middleIndex] <= vec[firstIndex] && vec[firstIndex] <= vec[lastIndex]) ||
      (vec[lastIndex] <= vec[firstIndex] && vec[firstIndex] <= vec[middleIndex])) {
    return firstIndex;
  } else if ((vec[firstIndex] <= vec[middleIndex] && vec[middleIndex] <= vec[lastIndex]) ||
             (vec[lastIndex] <= vec[middleIndex] && vec[middleIndex] <= vec[firstIndex])) {
    return middleIndex;
  } else {
    return lastIndex;
  }
}
