#include <stdlib.h>
#include <stdio.h>

static void exithandler1(void) {
  printf("Executing exit handler 1\n");
}

static void exithandler2(void) {
  printf("Executing exit handler 2\n");
}

int main(void) {
  atexit(exithandler1);
  atexit(exithandler2);
  printf("Main done!\n");
  return 0;
}
