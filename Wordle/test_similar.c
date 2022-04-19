#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "Wordle_solver.h"

int main(){
    /*
    char list_word[6]="PARIS";
    char word[6]="RREEP";
    char arrangement[6]="ZXXXZ";
    bool OK = is_similar(word,arrangement,list_word,5);
    printf("%d\n", OK);
    
    */
    for (int i = 0; i <= (int)pow(3,5) - 1; i++){
        char* configuration = dec_to_ternary(i, 5);
        printf("%s\n", configuration);
    }

    /*
    char* config = dec_to_ternary(5,5);
    printf("%s", config);
    */
}
