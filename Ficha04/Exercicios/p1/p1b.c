//
//  p1b.c
//  exercicios
//
//  Created by Beatriz de Henriques Martins on 15/03/17.
//  Copyright © 2017 Beatriz de Henriques Martins. All rights reserved.
//


#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signo){
    printf("In SIGNINT handler ...\n");
}

void sigusr1_handler(int signo){
    printf("In SIGUSR1 handler ...\n");
}

int main(void){
    if (signal(SIGINT, sigint_handler) < 0) {
        fprintf(stderr,"Unable to install SIGNINT handler\n");
        exit(1);
    }
    
    if (signal(SIGUSR1, sigusr1_handler) < 0) {
        fprintf(stderr,"Unable to install SIGUSR1 handler\n");
        exit(1);
    }
    
    printf("Sleeping for 30 seconds ...\n");
    int n=30;
    while ((n=sleep(n))!=0) {
        //...
    }
    printf("Waking up ...\n");
    
    exit(0);
}
