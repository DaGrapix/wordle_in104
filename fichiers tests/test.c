#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "read_dico.h"

int main(){
    char dico_name[8]="ods4.txt";
    int size;
    printf("%s", dico_name);
    char** liste = read_dico(dico_name, &size, 5);
    while (size!=0){
        printf("%s", liste[size]);
        size--;
    }
}