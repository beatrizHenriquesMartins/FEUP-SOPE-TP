#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH_NAME 100

//4a
/*
int main(void) {

    char name[MAX_LENGTH_NAME];

    printf("Name: ");
    fgets(name, sizeof(name),stdin);

    printf("Hello %s", name);

    return 0;
}
*/

//4b
int main(void) {

      char name[MAX_LENGTH_NAME];

      printf("Name: ");
      fgets(name, sizeof(name),stdin);

      int num;
      printf("Número: ");
      scanf("%i",&num);

      int i;
      for(i=0;i<num;i++){
          printf("Hello %s", name);
      }

      return 0;
}
