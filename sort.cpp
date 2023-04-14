#include "sort.h"
#include<iostream>
std::vector<int> qsort2(std::vector<int> &vec, int low, int high){
  std::cout << "params: " << low << " | " << high << "\n";
  // base case
  // changed to < to sort subarray of 2
  if (high - low < 1){
    return vec;
  }

  // select pivot value
  // for now we'll just pick list[0]
  int pivot = vec[low];
  std::cout << "pivot: " << pivot << "\n";
  int pivotIndex = low;

  
  // copy all the values < pivot to lower
  // copy all the values >= pivot to higher;
  // should check last index
  for (int i=low+1;i<=high;i++){
    if (vec[i] < pivot){
      vec.insert(vec.begin()+pivotIndex, vec[i]);
      vec.erase(vec.begin()+i+1);
      pivotIndex++;
    } else {
      // index of pivot doesn't change
      //vec.insert(vec.begin()+pivotIndex+1, vec[i]);
    }
  }
  /*
  std::cout << "current run: \n";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " , ";
  }
  std::cout << "\n";
  */

  // make our recursive calls
  // lower
  //std::cout << "lower: " << low << "|" << pivotIndex-1 << "\n";
  qsort2(vec, low, pivotIndex-1);
  //higher
  //std::cout << "higher: " << pivotIndex+1 << " | " << high << "\n ";
  qsort2(vec, pivotIndex+1, high);

  // return the sorted list
  return vec;
}

