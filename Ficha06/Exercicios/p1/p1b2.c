#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define STDERR 2
#define NUMITER 10000

// parametro das threads variavel do tipo char
void * thrfunc(void * arg){
  int i;
  char s[10];

  sprintf(s,"%d",*(int *)arg);
  fprintf(stderr,"Starting thread%s\n", s);

  for (i = 1; i <= NUMITER; i++) {
    write(STDERR,s,strlen(s));
  }

  return NULL;
}

int main(){
  pthread_t ta;
  pthread_t tb;
  int a=1;
  int b=2;

  pthread_create(&ta,NULL,thrfunc,&a);
  pthread_create(&tb,NULL,thrfunc,&b);

  pthread_join(ta,NULL);
  pthread_join(tb,NULL);

  return 0;
}

/*
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#define STDERR 2
#define NUMITER 10000
void * thrfunc(void * arg)
{
    int i;
    char s[10];
    sprintf(s,"%d",*(int *)arg);
    fprintf(stderr, "Starting thread %s\n",s);
    for (i = 1; i <= NUMITER; i++) write(STDERR,s,strlen(s));
    return NULL;
}
int main()
{
    int a = 1, b=2;
    pthread_t ta, tb;
    pthread_create(&ta, NULL, thrfunc, &a);
    pthread_create(&tb, NULL, thrfunc, &b);
    pthread_join(ta, NULL);
    pthread_join(tb, NULL);
    return 0; }
*/
