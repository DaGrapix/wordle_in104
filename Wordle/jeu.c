#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "word_compare.h"
#include "load_dic.h"
#include "random_word.h"


int main(){
    srand(time(NULL));
    char dico_name[8]="ods4.txt";
    //char dico_name[10]="french.txt";

    int word_length = 5;
    int size;
    char** list = read_dico(dico_name, &size, word_length);

    char* game_word=random_word(list, size);

    int nb_tour = 0;
    bool gagne = false;
    char user_word[2*size+1];
    //

    printf("#####  WORDLE  #####\n\n");
    printf("___________________________\n");
    printf("#####  REGLES DU JEU  #####\n");

    printf("Un mot a ete choisi au hasard.\n Ton role est de retrouver ce mot en %d tours.\n", nb_tour);
    printf("Tu devras donner un mot a chaque tour.\n Pour chacune des lettres de ce mot,\n"
            "si cette lettre est la presente dans le mot cible et a la bonne place, un O s'affichera;\n"
            "Si c'est une lettre qui est dans le mot mais à la mauvaise place, un Z s'affichera;\n"
            "si la lettre n'est pas dans le mot, un X s'affichera.\n");

    printf("___________________________\n\n\n");

    //TEST
    //printf("%s\n", game_word);

    //TEST
    //game_word="NOEME";
    while (nb_tour<6 && !gagne){
        printf("#####  TOUR %d  #####\n", nb_tour);
        scanf("%s", user_word);
        if (strcmp(user_word, game_word)==0){
            printf("C'est gagné!\n\n");
            return(0);
        }
        else if (strlen(user_word)!=word_length){
            printf("Pas le bon nombre de lettres, Reessaye!\n\n");
        }
        else if (find_word_dicho(list, user_word, 0, size-1)==false){
            printf("Ce n'est pas un mot du dico, Reessaye!\n\n");
        }
        else{
            letter_check(game_word, user_word);
            nb_tour++;
            printf("\n\n");
        }
    }

    printf("C'est perdu!, le mot etait\n%s\n\n", game_word);
    return(0);
}