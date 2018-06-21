#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "func.h"

int runlength(unsigned char *string, int size) {
  unsigned char *ret;
  unsigned char tmp;
  int i, j = 0, k, count = 1, p;
  if (definecheck(444550)) {
    return 1;
  }
  // input your code here...
  ret = (char *)malloc(sizeof(char) * size);
  tmp = string[0];
  for(i = 1; i <= size; i++){
    if(string[i] != tmp || i == size || count == 255){
      ret[j] = tmp;
      ret[j+1] = count;
      j += 2;
      tmp = string[i];
      count = 1;
    }
    else{
      count++;
    }
  }
  strcpy(string, ret);
  free(ret);
  
  return 0;
}

