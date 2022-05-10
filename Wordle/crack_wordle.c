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

//Troncage de la liste courante, par adresse
void dico_resizer(char* word, int word_size,char* word_state, char** current_list, int* p_current_list_size){
    char** similar_list = malloc((*p_current_list_size+1)*sizeof(char*));
    int j = 0;
    for (int i = 0; i <= *p_current_list_size - 1; i++){
        if (is_similar(word, word_state, current_list[i], word_size)){
            strcpy(similar_list[j], current_list[i]);
            j++;
        }
    }
    for (int i =0; i <= j; i++){
        strcpy(current_list[i], similar_list[i]);
    }
    for (int i = *p_current_list_size - 1; i >= j + 1; i--){
        free(current_list[i]);
    }
    if (j < *p_current_list_size){
        current_list[j+1]=NULL;
    }
    *p_current_list_size = j + 1;
}

bool valid_word_state(int word_size, char* word_state){
    for (int i = 0; i <= word_size - 1; i++){
        if ((word_state[i]!='O') && (word_state[i]!='Z') && (word_state[i]!='X')){
            return(false);
        }
    }
    return(true);
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
    while((word_size>10) || (word_size<=2)){
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

    while (tour_counter<(nb_tour) && !gagne){
        printf("#####  TOUR %d  #####\n", tour_counter);
        scanf("%s", user_word);
        scanf("%s", word_state);
        dico_resizer(user_word, word_state, current_list, current_list_size);
        char* very_best_word = best_word(word_size, list, list_size, current_list, current_list_size);
        printf("Le meilleur mot est %s", very_best_word);

        if (current_list_size==1){
            gagne=1;
            printf("Victoire en %d tours", tour_counter);
        }

}