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
    char list_word[6]="PARIS";
    char word[6]="RREEP";
    char arrangement[6]="ZXXXZ";
    bool OK = is_similar(word,arrangement,list_word,5);
    printf("%d\n", OK);
}
