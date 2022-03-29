#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "load_dic.h"

int main(){
    char dico_name[8]="ods4.txt";
    //char dico_name[10]="french.txt";
    int size;
    char** list = read_dico(dico_name, &size, 6);
    //char** list = load_file(dico_name, &size);
    for (int i = 0; i<= size-1; i++){
        list[i][size]='\0';
        //printf("%c\n", list[i][size-1]);
        printf("%s\n", list[i]);
    }
    
    char word[7]="ZYTHUM";
    //bool OK = find_word_dicho(list, word, 0, size - 1);
    bool OK = find_word_dicho(list, word, 0, size - 1);
    printf("%d\n", OK);
    //printf("%d\n", strcmp(word, list[1310]));
    //printf("%d\n", strcmp(word, list[16535]));
    //printf("%s\n", list[16535]);
    //printf("%c\n", list[16535][5]);
}