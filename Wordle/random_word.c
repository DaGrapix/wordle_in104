#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* random_word(char** list, int size){
    int r = rand()%size;
    return(list[r]);
}