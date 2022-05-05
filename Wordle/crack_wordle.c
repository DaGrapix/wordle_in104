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

void dico_resizer(int word_size, char** list, int list_size, char** current_list, int current_list_size){
    
}



int main(){
    int nb_tour;
    int word_size;

    printf("En combien de tours est la partie?\n");
    scanf("%d", &nb_tour);
    while((nb_tour>50) || (nb_tour<=0)){
        printf("Il faut un nombre entre 1 et 50! Réeessaie!\n");
        scanf("%d", &nb_tour);
    }
    printf("\n\n");

    printf("Avec combien de lettres joues-tu?\n");
    scanf("%d", &word_size);
    while((word_size>10) || (word_size<=0)){
        printf("Il faut un nombre entre 1 et 10! Réeessaie!\n");
        scanf("%d", &word_size);
    }
    printf("\n\n");

    srand(time(NULL));
    char dico_name[8]="ods4.txt";


    int size;
    int current_list_size;
    char** list = read_dico(dico_name, &size, word_size);
    char** current_list = read_dico(dico_name, &current_list_size, word_size);

    int tour_counter = 0;
    bool gagne = false;
    char user_word[2*size+1];
    char very_best_word[word_size]


    while (tour_counter<(nb_tour) && !gagne){
        printf("#####  TOUR %d  #####\n", tour_counter);
        scanf("%s", user_word);
        scanf("%s", word_state);
        dico_resizer(user_word, word_state, current_list, current_list_size);
        very_best_word = best_word(word_size, list, list_size, current_list, current_list_size);
        printf("Le meilleur mot est %s", very_best_word);

        if (current_list_size==1){
            gagne=1;
            printf("Victoire en %d tours", tour_counter);
        }
        
}