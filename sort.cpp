#include "sort.h"
std::vector<int> qsort(std::vector<int> list){
  int i,j;

  // base case
  if (list.size() <= 1){
    return list;
  }

  // select pivot value
  // for now we'll just pick list[0]
  int pivot = list[0];

  // make 2 new vectors
  std::vector<int> lower,higher;
  
  // copy all the values < pivot to lower
  // copy all the values >= pivot to higher;
  for (i=1;i<list.size();i++){
    if (list[i] < pivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }

  // make our recursive calls
  lower = qsort(lower);
  higher = qsort(higher);

  // copy everything back
  for (i=0; i < lower.size(); i++){
    list[i] = lower[i];
  }
  list[i] = pivot;
  i++;
  for (j=0;j<higher.size(); j++){
    list[i] = higher[j];
    i++;
  }

  // return the sorted list
  return list;
}

