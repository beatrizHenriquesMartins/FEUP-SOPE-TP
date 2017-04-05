#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define WRITE 1
#define READ 0
#define MAX_LENGHT 2

typedef struct{
  int dir;
  int esq;
}Par;

int main(void) {

    Par parOrdenado;
    int p[2];
    int nn;
    pid_t pid;
    int soma = 0;
    int diferenca = 0;
    float quociente = 0;
    int produto = 0;

    scanf("%d %d",&parOrdenado.dir,&parOrdenado.esq);

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
            //write(p[WRITE], parOrdenado, sizeof(parOrdenado));
            write(p[READ], &parOrdenado, sizeof(parOrdenado));
        }else{
            close(p[WRITE]);
            nn = read(p[READ], &parOrdenado,sizeof(parOrdenado));
            printf("n1[0]=%d n1[1]=%d\n", parOrdenado.dir, parOrdenado.esq);
            soma = parOrdenado.dir+parOrdenado.esq;
            printf("Soma: %d + %d = %d\n",parOrdenado.dir, parOrdenado.esq,soma);
            diferenca = parOrdenado.dir-parOrdenado.esq;
            printf("Diferenca: %d - %d = %d\n",parOrdenado.dir, parOrdenado.esq,diferenca);
            quociente = (float)parOrdenado.dir/parOrdenado.esq;
            printf("Quociente: %d / %d = %.3f\n",parOrdenado.dir, parOrdenado.esq,quociente);
            produto = parOrdenado.dir*parOrdenado.esq;
            printf("Produto: %d * %d = %d\n",parOrdenado.dir, parOrdenado.esq,produto);
        }
    }

    return 0;

}
