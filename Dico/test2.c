#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(){
    char** liste = malloc(2*sizeof(char*));
    liste[0]="OK";
    liste[1]="Lelite";
    printf("%s", liste[0]);
    printf("%s", liste[1]);
}