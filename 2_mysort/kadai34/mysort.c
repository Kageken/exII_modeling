#include "func.h"
#include <stdlib.h>

int mysort(char *[], int);
void mergeSort(char *[], char *[], int, int);

int mysort(char *string_array[], int size) {
  int ret;
  //input your code here...
  int left, right;
  char **tmp = (char**)malloc(sizeof(char*)*size);

  left = 0;
  right = size - 1;
  mergeSort(string_array, tmp, left, right);
  free(tmp);

  ret = definecheck(653660);
  return ret;
}

void mergeSort(char *string_array[], char *tmp[], int left, int right){
  int mid, i, j, k;

  if(left >= right){
    return;
  }

  mid = (left + right)/2;
  mergeSort(string_array, tmp, left, mid);
  mergeSort(string_array, tmp, mid + 1, right);

  for(i = left; i <= mid; i++){
    tmp[i] = string_array[i];
  }
  for(i = mid + 1, j = right; i <= right; i++, j--){
    tmp[i] = string_array[j];
  }

  i = left;
  j = right;

  for(k = left; k <= right; k++){
    if(strcmp(tmp[i], tmp[j]) < 0){
      string_array[k] = tmp[i];
      i++;
    }
    else{
      string_array[k] = tmp[j];
      j--;
    }
  }

  return;
}
