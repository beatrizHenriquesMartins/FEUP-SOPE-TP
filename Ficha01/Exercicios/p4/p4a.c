#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH_NAME 100

int main(void) {

      char name[MAX_LENGTH_NAME];

      printf("Name: ");
      fgets(name, sizeof(name),stdin);

      printf("Hello %s", name);

      return 0;
}
