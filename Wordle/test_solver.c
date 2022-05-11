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
    //Test configuration OK
    /*
    for (int i = 0; i <= (int)pow(3,5) - 1; i++){
        char* configuration = dec_to_ternary(i, 5);
        printf("%s\n", configuration);
    }
    */

    
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

    //Affichage des entropies de chaque mot du dico
    for (int i = 0; i <= size - 1; i ++){
       printf("%s   :   %f\n", list[i],entropy(list[i], size, list, word_size));
    }










    //char word[6] = "ABACA";


    /*
    char word_state[6] = "OOOOO";
    //char* bestWord = best_word(word_size, list, size, list, size);
    for (int i = 0; i <= size - 1; i++){
        if (is_similar(word, word_state, list[i], word_size)){
            printf("%s    ===    %s\n", word, list[i]);
        }
        else{
            printf("%s    =/=    %s\n", word, list[i]);
        }
    }
    */
   

    //entropy(word, size, list, word_size);
    

    /*
    char word[6]="PARIS";
    char word_state[6]="ZXXXZ";
    for (int j = 0; size - 1; j++){
        for (int i = 1; size - 1; i++){
            if (is_similar(word, word_state,list[i], word_size)==1){
                printf("%s ", list[i]);
                printf("est compatible pour la combinaison ");
                printf("%s", word_state);
            }
        }
    }
    //char* bestWord = best_word(word_size, list, size, list, size);

    //printf("%s\n", bestWord);
    */
}