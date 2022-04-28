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
    /*
    char list_word[6]="PARIS";
    char word[6]="RREEP";
    char arrangement[6]="ZXXXZ";
    bool OK = is_similar(word,arrangement,list_word,5);
    printf("%d\n", OK);
    
    
    for (int i = 0; i <= (int)pow(3,5) - 1; i++){
        char* configuration = dec_to_ternary(i, 5);
        printf("%s\n", configuration);
    }
    */


    /*
    char* config = dec_to_ternary(5,5);
    printf("%s", config);
    */


    srand(time(NULL));
    char dico_name[14]="petit_dico.txt";
    int word_length = 5;
    int size;
    char** list = read_dico(dico_name, &size, word_length);
    char* bestWord = best_word(5, list, size, list, size);

    printf("%s\n", bestWord);
}
