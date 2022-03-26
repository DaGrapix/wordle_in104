#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "load_dic.h"

int main(){
    char dico_name[8]="ods4.txt";
    int size;
    char** list = read_dico(dico_name, &size, 6);
    for (int i = 0; i<= size-1; i++){
        printf("%s\n", list[i]);
    }
    
    char word[6]="BANANE";
    bool OK = find_word_dicho(list, word, 0, size-1);
    printf("%d\n", OK);
}