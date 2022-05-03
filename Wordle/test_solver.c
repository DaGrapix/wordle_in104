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
    //Test configuration
    /*
    for (int i = 0; i <= (int)pow(3,5) - 1; i++){
        char* configuration = dec_to_ternary(i, 5);
        printf("%s\n", configuration);
    }
    */


    srand(time(NULL));
    //char dico_name[32]="petit_dico.txt";
    //char dico_name[32]="french.txt";
    //char dico_name[32]="ods4.txt";
    //char dico_name[32]="micro_dico.txt";
    char dico_name[32]="dictionnaire_frequence.txt";
    int word_length = 5;
    int size;
    char** list = read_dico(dico_name, &size, word_length);
    char* bestWord = best_word(word_length, list, size, list, size);

    printf("%s\n", bestWord);
}
