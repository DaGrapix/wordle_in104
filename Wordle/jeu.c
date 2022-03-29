#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "word_compare.h"
#include "load_dic.h"
#include "random_word.h"


int main(){
    char dico_name[8]="ods4.txt";
    //char dico_name[10]="french.txt";

    int word_length = 5;
    int size;
    char** list = read_dico(dico_name, &size, word_length);

    char word[word_length+1] = random_word(list, size);

    int nb_tour = 0;
    bool gagne = false;
    char user_word[size+1];
    //

    while (nb_tour<6 && !gagne){
        fscanf(in, "%s\n", user_word);
        word_compare();
    }
}