#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[]) {

      char* varAmb = envp[0]; //inicializada para passar no ciclo à frente
      int i = 0;

      printf("\n\nVariaveis de Ambiente\n\n" );

      while (varAmb !=  NULL) {
          varAmb=envp[i];
          printf(" > %s: %s\n\n", envp[i], getenv(envp[i]) );
          i++;
      }
      return 0;

}
