#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define WRITE 1
#define READ 0
#define MAX_LENGHT 2

int main(void) {

    int p[2];
    int n[2];
    int nn;
    pid_t pid;
    int n1[2];
    int soma = 0;
    int diferenca = 0;
    float quociente = 0;
    int produto = 0;

    scanf("%d %d",&n[0],&n[1]);

    if(pipe(p) < 0){
        fprintf(stderr, "Pipe error");
        exit(1);
    }

    if((pid = fork()) < 0){
        fprintf(stderr, "Fork error");
        exit(2);
    }else{
        if(pid > 0){
            close(p[READ]);
            write(p[WRITE], n, 2*sizeof(int));
        }else{
            close(p[WRITE]);
            nn = read(p[READ],n1,2*sizeof(int));
            printf("n1[0]=%d n1[1]=%d\n",n1[0],n1[1]);
            soma = n[0]+n[1];
            printf("Soma: %d + %d = %d\n",n1[0],n1[1],soma);
            diferenca = n[0]-n[1];
            printf("Diferenca: %d - %d = %d\n",n1[0],n1[1],diferenca);
            quociente = (float)n[0]/n[1];
            printf("Quociente: %d / %d = %.3f\n",n1[0],n1[1],quociente);
            produto = n[0]*n[1];
            printf("Produto: %d * %d = %d\n",n1[0],n1[1],produto);
        }
    }

    return 0;

}
