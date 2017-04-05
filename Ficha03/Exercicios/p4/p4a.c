#include <stdio.h>
#include <unistd.h>

int main(void){

      if(fork() > 0){
        printf("World !");
      }else{
        printf("Hello");
      }
      printf("\n");
      return 0;
}
