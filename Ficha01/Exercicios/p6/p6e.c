#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define  BUF_LENGTH 256
#define  MAX 1000

int main(void){
  FILE *src;
  FILE *dst;
  char buf[BUF_LENGTH];

  if ( ( src = fopen("infile.txt", "r" ) ) == NULL ) {
    printf("Error %d\n",errno); //errno mostra o tipo de erro
    exit(1);
  }

  if ( ( src = fopen("outfile.txt", "w" ) ) == NULL ) {
    printf("Error %d\n",errno);
    exit(2);
  }

  while( ( fgets (buf, MAX, src ) ) != NULL ) {
    fputs( buf, dst );
  }

  fclose(src);
  fclose(dst);

  exit(0);
}
