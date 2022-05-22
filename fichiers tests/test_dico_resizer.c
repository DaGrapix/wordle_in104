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


void dico_resizer(char* word, int word_size,char* word_state, char** current_list, int* p_current_list_size){
    char** similar_list = malloc(((*p_current_list_size) + 1)*sizeof(char*));
    int j = 0;
    for (int i = 0; i <= *p_current_list_size - 1; i++){
        if (is_similar(word, word_state, current_list[i], word_size)){
            char* buffer = malloc((word_size+1)*sizeof(char));
            strcpy(buffer, current_list[i]);
            similar_list[j] = buffer;
            j++;
        }
    }
    j--;
    for (int i =0; i <= j; i++){
        strcpy(current_list[i], similar_list[i]);
    }
    for (int i = *p_current_list_size - 1; i >= j + 2; i--){
        free(current_list[i]);
    }
    if (j < *p_current_list_size - 1){
        current_list[j+1]=NULL;
    }
    *p_current_list_size = j + 1;
}



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

    char word[6] = "EPARS";

    char word_state[6] = "XXOZX";

    for (int i = 0; i <= size - 1; i ++){
        printf("%s\n", list[i]);
    }

    printf("\n\n\n\n\n\n\n////////////////////////////////////////////////////////\n\n\n\n\n\n\n");

    for (int i = 0; i <= size - 1; i++){
        if (is_similar(word, word_state, list[i], word_size)){
            printf("%s\n", list[i]);
        }
    }

    printf("\n\n\n\n\n\n\n////////////////////////////////////////////////////////\n\n\n\n\n\n\n");

    dico_resizer(word, word_size, word_state, list, &size);

    for (int i = 0; i <= size - 1; i ++){
        printf("%s\n", list[i]);
    }
}