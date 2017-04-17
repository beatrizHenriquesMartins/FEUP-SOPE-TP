#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <fcntl.h>

#define  BUF_LENGTH 256
#define  MAX 1000

//número de ficheiros,ficheiro inicial, ficheiro final
int main(int argc, char *argv[]){
  FILE *src;
  FILE *dst;
  char buf[BUF_LENGTH];

  if(argc > 3){
    printf("Error %d\n", errno);
    exit(3);
  }

  if(argc == 0){
    printf("Error %d\n", errno);
    exit(4);
  }

  if ( ( src = fopen(argv[1], "r" ) ) == NULL ) {
    printf("Error %d\n",errno); //errno mostra o tipo de erro
    exit(1);
  }

  if ( ( src = fopen(argv[2], "w" ) ) == NULL ) {
    printf("Error %d\n",errno);
    exit(2);
  }

  while( ( fread( buf, 1, MAX, src) ) != NULL ) {
    fwrite( buf, 1, MAX, dst);
  }

  fclose(src);
  fclose(dst);

  exit(0);
}
