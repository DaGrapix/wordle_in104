#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "word_compare.h"
#include "load_dic.h"
#include "random_word.h"

#include "Wordle_solver.h"

int main(){    
    srand(time(NULL));
    //      CHOIX DU DICTIONNAIRE       //
    //char dico_name[32]="petit_dico.txt";
    //char dico_name[32]="french.txt";
    //char dico_name[32]="micro_dico.txt";
    //char dico_name[32]="dictionnaire_frequence.txt";
    char dico_name[32]="ods4.txt";

    //longueur d'un mot
    int word_size = 5;
    
    //taille de la liste de mots de word_size lettres
    int size;

    //Liste de tous les mots de word_size lettres
    char** list = read_dico(dico_name, &size, word_size);

    char* bestWord = best_word(word_size, list, size, list, size);

    printf("%s", bestWord);
}