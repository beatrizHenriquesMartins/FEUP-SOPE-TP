#include <stdio.h>
#include <unistd.h>

int main(void){

      if(fork() > 0){
        printf("Hello");
      }else{
        printf("World !");
      }
      printf("\n");
      return 0;
}
