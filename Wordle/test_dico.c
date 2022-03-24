#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "load_dic.h"

int main(){
    char mot[6] = "BANANE";
    //printf("%s\n", mot);
    //char fichier[8] = "ods4.txt";
    char fichier[10] = "french.txt";
    unsigned int taille;
    char** tableau = load_dic(fichier, &taille);
    printf("%d\n", find_word_dicho(tableau, mot, 0, taille - 1));

}