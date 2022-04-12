#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Wordle_solver.h"

int main(){
    char list_word[6]="PARIS";
    char word[6]="RRREP";
    char arrangement[6]="XXOXZ";
    bool OK = is_similar(word,arrangement,list_word,5);
    printf("%d\n", OK);
}
