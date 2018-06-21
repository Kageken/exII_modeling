#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "func.h"

int main(int argc, char *argv[]){

  char *string = (char*)malloc(sizeof(char)*MAXSTR);
  char *tmp_string = (char*)malloc(sizeof(char)*MAXLEN);

  char outname[100] = {};
  int index=0; //配列の添え字
  int size;    //配列のサイズ(文字の長さ)を保存
  int i, j;
  // 引数のチェックと入出力ファイルのオープン
  FILE *file_in, *file_out;
  clock_t start,end;

  if(definecheck(643310)){
    printf("Detect incorrect file change\n");
	exit(1);
  }
 
  if (argc != 2){
    printf("different number of arguments\n");
    exit(1);
  }

  if ((file_in=fopen (argv[1],"r")) == NULL ){
    printf("input file not opened\n");
    exit(1);
  }
  j = 0;
  while((argv[1][j] != '.') && (argv[1][j] != '\0')){
    //printf("argv[1][%d] = %c\n", j, argv[1][j]);
    outname[j] = argv[1][j];
    j++;
  }
  outname[j] = '\0';
  strcat(outname, ".bwt");

  if ((file_out=fopen (outname,"w")) == NULL){
    printf("output file not opened\n");
    exit(1);
  }
  // fgetsで入力ファイルの文字列を一行ずつ読み込み配列stringに格納
  while (fgets(tmp_string, MAXLEN, file_in)) {  
    strcat(string,tmp_string);
  }
  size = strlen(string);
  start = clock();
  
  // input your code here...
/*
  char *tmp = (char*)malloc(sizeof(char)*size*2);
  char **string_array = (char**)malloc(sizeof(char*)*size*size);
  strcpy(tmp, string);
  strcat(tmp, string);
  printf("1\n");
  for(i = 0; i < size; i++){
    strncpy(string_array[i], tmp+i, size);
    string_array[i][size] = '\0';
  }
  printf("2\n");
  bsort(string_array, size);
  printf("3\n");
  for(i = 0; i < size; i++){
    string[i] = string_array[i][size-1];
  }
  string[size] = '\0';
*/

  bsort(string, size);
  // mysort()

  end = clock();

  printf("%fsec\n",(double)(end -start)/CLOCKS_PER_SEC);

  fputs(string, file_out);

  free(string);
//  free(string_array);
//  free(tmp_string);
  fclose(file_in);
  fclose(file_out);
  
  return 0;
}
