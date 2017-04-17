#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


#define MAX_BUFFER 512

int main(int argc, char const *argv[]) {
  if(argc != 3){
    printf("Erro \n");
    exit(1);
  }

  FILE *src;
  FILE *dst;
  char buff[MAX_BUFFER + 1];

  src =fopen(argv[1], "r");
  if(src == NULL){
    perror(argv[1]);
    fclose(src);
    exit(2);
  }

  dst =fopen(argv[2], "r");
  if(dst == NULL){
    perror(argv[1]);
    fclose(dst);
    exit(2);
  }

  size_t numL;
  size_t numE;

  while (( numL = fread(buff, 1, MAX_BUFFER, src)) > 0) {
    if((numE = fwrite(buff, 1, MAX_BUFFER, dst)) <=0 || numL != numE){
      perror(argv[2]);
      fclose(src);
      fclose(dst);
      exit(3);
    }
  }

  fclose(src);
  fclose(dst);

  return 0;
}
