#include <stdlib.h>

void bsort(char [], int);
void mergeSort(char [], int [], int [], int, int);


void bsort(char string[], int size) {
	//input your code here...
  int i;
  char *ss = (char*)malloc(sizeof(char)*size*2);
  int *start = (int*)malloc(sizeof(int)*size);
  int *tmp = (int*)malloc(sizeof(int)*size);

  strcpy(ss, string);
  strcat(ss, string);
  for(i = 0; i < size; i++){
    start[i] = i;
  }

  mergeSort(ss, start, tmp, 0, size-1);

  for(i = 0; i < size; i++){
    string[i] = ss[start[i]+size-1];
  }
  string[size] = '\0';

  free(ss);
  free(start);
  free(tmp);

  return;
}

void mergeSort(char ss[], int start[], int tmp[], int left, int right){
  int mid, i, j, k;
  int size = right + 1;

  if(left >= right){
    return;
  }

  mid = (left + right)/2;
  mergeSort(ss, start, tmp, left, mid);
  mergeSort(ss, start, tmp, mid + 1, right);

  for(i = left; i <= mid; i++){
    tmp[i] = start[i];
  }
  for(i = mid + 1, j = right; i <= right; i++, j--){
    tmp[i] = start[j];
  }

  i = left;
  j = right;

  for(k = left; k <= right; k++){
    if(strncmp(ss+tmp[i], ss+tmp[j], size) < 0){
      start[k] = tmp[i];
      i++;
    }
    else{
      start[k] = tmp[j];
      j--;
    }
  }

  return;
}

