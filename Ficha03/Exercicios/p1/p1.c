#include <stdio.h>
#include <unistd.h>

int global=1;

int main(void){
      int local =2;

      if(fork()>0){
          //sleep(2);  /*o filho termina primeiro do que o pai*/
          printf("PAI\nPID = %d; PPID = %d\n",getpid(),getppid() );
          global++;
          local--;
      }else{
          //sleep(2); /*o pai termina primeiro do que o filho*/
          /* PPID do filho é 1 porque o pai já morreu, caso contrário,
          o é o número do processo do pai*/
          printf("FILHO\nPID = %d; PPID = %d\n",getpid(),getppid() );
          global--;
          local++;
      }

      printf("PID = %d - global = %d ; LOCAL = %d\n",getpid(),global,local );

      return 0;
}
