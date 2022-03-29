#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "word_compare.h"


int main(){
    char word[5]="TRAIN";
    char user_word[5]="TENRI";

    letter_check(word, user_word);
}