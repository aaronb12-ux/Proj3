#include <stdio.h>

typedef struct vertexpoints_struct{
    int x;
    int y;
}vertexpoints;

vertexpoints coordinates;


void print_bin_int_file(char* file_name){
/*
  Print the contents of a binary file that contains a shape
  @file_name: The path to the binary file
*/
  FILE* file = fopen(file_name, "rb");

  if(file == NULL){
    printf("Couldn't open file %s\n", file_name);
    return;
  }

  int nums[2];

  fread(nums, sizeof(int), 1, file);
  printf("Num Points: %d\n", nums[0]);
  fread(nums, sizeof(int), 2, file);
  while( !feof(file)){
    printf("%d, %d\n", nums[0], nums[1]);
    fread(nums, sizeof(int), 2, file);
  }
  fclose(file);
}


int main(int argc, char** argv) {
  print_bin_int_file(argv[1]);
  return 0;
}
