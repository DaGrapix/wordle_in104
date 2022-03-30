#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "word_compare.h"


int main(){
    char game_word[6]="AANNE";
    char user_word[6]="AFJEA";

    int a = letter_check(game_word, user_word);

    //char character = 'a';
    //printf("%d", 'a'==character);
}