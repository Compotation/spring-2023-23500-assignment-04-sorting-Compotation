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
  int pivotIndex = medianIndex(vec, low, (int)((low + high)/2), high);
  // TODO something wrong with sorting
  int pivot = vec[pivotIndex];
  std::cout << "pivot: " << pivot << "\n";

  
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
  std::cout << "current run: \n";
  for (int i = 0; i < vec.size(); i++) {
    std::cout << vec[i] << " , ";
  }
  std::cout << "\n";

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

int medianIndex(std::vector<int> &vec, int firstIndex, int middleIndex, int lastIndex) {
  if ((vec[middleIndex] <= vec[firstIndex] && vec[firstIndex] <= vec[lastIndex]) || (vec[lastIndex] <= vec[firstIndex] && vec[firstIndex] <= vec[middleIndex])) {
    return firstIndex;
  } else if ((vec[firstIndex] <= vec[middleIndex] && vec[middleIndex] <= vec[lastIndex]) || (vec[lastIndex] <= vec[middleIndex] && vec[middleIndex] <= vec[firstIndex])) {
    return middleIndex;
  } else {
    return lastIndex;
  }
}
