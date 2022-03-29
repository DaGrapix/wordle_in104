#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "word_compare.h"


int main(){
    char word[6]="TRAIN";
    char user_word[6]="TENRI";

    int a = letter_check(word, user_word);
    
    //char character = 'a';
    //printf("%d", 'a'==character);
}