#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

int main(int argc, char const *argv[]) {
  clock_t start_t;
  clock_t end_t;
  clock_t total_t;

  start_t = clock();
  if (argc != 3) {
    printf("poucos argumentos\n");
    exit(1);
  }

  int n1 = atoi(argv[1]);
  int n2 = atoi(argv[2]);

  if(n2 >= n1){
    printf("n2 maior do que n1\n");
    exit(2);
  }

  int aleatorio = -1;
  int i = 1;
  srand(time(NULL));

  while (aleatorio != n2) {
    aleatorio = rand() % n1;
    printf("%d: %d\n", i, aleatorio);
    i++;
  }

  end_t = clock();
  total_t = end_t - start_t;
  printf("time: %lu\n", total_t);

  return 0;
}
