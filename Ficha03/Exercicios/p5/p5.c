#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
      int status;

      if(fork() > 0){ /* PAI */
        wait(&status);
          printf("friends !");
      }else{ /* FILHO */
          if(fork() == 0){ /* NETO */
            printf("Hello");
          }else{
            wait(&status);
            printf("my");
          }
      }
      printf("\n");
      return 0;
}
