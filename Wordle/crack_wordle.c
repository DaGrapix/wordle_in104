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

//Troncage de la liste courante en gardant tous les mots compatibles, passage par adresse
void dico_resizer(char* word, int word_size,char* word_state, char** current_list, int* p_current_list_size){
    char** similar_list = malloc(((*p_current_list_size) + 1)*sizeof(char*));
    int j = 0;
    for (int i = 0; i <= *p_current_list_size - 1; i++){
        if (is_similar(word, word_state, current_list[i], word_size) && (strcmp(word, current_list[i])!=0)){
            char* buffer = malloc((word_size+1)*sizeof(char));
            strcpy(buffer, current_list[i]);
            similar_list[j] = buffer;
            j++;
        }
    }
    j--;
    for (int i =0; i <= j; i++){
        strcpy(current_list[i], similar_list[i]);
    }
    for (int i = *p_current_list_size - 1; i >= j + 2; i--){
        free(current_list[i]);
    }
    if (j < *p_current_list_size - 1){
        current_list[j+1]=NULL;
    }

    *p_current_list_size = j + 1;

    if (current_list[0]==NULL){
        *p_current_list_size=1;
    }    
}

//Verifie si une configuration est valide
bool valid_word_state(int word_size, char* word_state){
    for (int i = 0; i <= word_size - 1; i++){
        if ((word_state[i]!='O') && (word_state[i]!='Z') && (word_state[i]!='X')){
            return(false);
        }
    }
    return(true);
}

int main(){
    printf("\n###############  Wordle Solver  ###############\n\n");
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
    //char dico_name[32]="petit_dico.txt";
    //char dico_name[32] = "dictionnaire_frequence.txt";


    int size;
    int current_list_size;
    char** list = read_dico(dico_name, &size, word_size);
    char** current_list = read_dico(dico_name, &current_list_size, word_size);

    int tour_counter = 1;
    bool gagne = false;
    char user_word[2*word_size+1];
    char word_state[2*word_size+1];
    char* old_word = malloc((size+1)*sizeof(char));
    char win_comb[word_size+1];
    for (int i = 0; i <= word_size-1; i++){
        win_comb[i]='O';
    }
    win_comb[word_size]='\0';
    //printf("%s\n", win_comb);

    while (tour_counter<(nb_tour) && !gagne){
        printf("#####  TOUR %d  #####\n", tour_counter);

        //Lecture du mot
        printf("Quel mot as tu utilisé?\n");
        scanf("%s", user_word);
        while ((strlen(user_word)!=word_size) || (find_word_dicho(list, user_word, 0, size-1)==false)){
            if (strlen(user_word)!=word_size){
                printf("Pas le bon nombre de lettres, Reessaie!\n\n");
            }
            else{
                printf("Ce n'est pas un mot du dico, Reessaie!\n\n");
            }
            scanf("%s", user_word);
        }

        printf("\n");

        //Lecture de la configuration
        printf("Quel est la configuration associée à ce mot?\n");
        scanf("%s", word_state);
        while ((strlen(word_state)!=word_size) || (valid_word_state(word_size, word_state)==false)){
            if (strlen(word_state)!=word_size){
                printf("Pas le bon nombre de lettres, Reessaie!\n\n");
            }
            else{
                printf("Ce n'est pas une configuration valide, Reessaie!\n\n");
            }
            scanf("%s", word_state);
        }
        if (strcmp(word_state,win_comb)==0){
            printf("Victoire en %d tour(s)!\n", tour_counter);
            printf("\\(ᵔᵕᵔ)/\n");
            return(0);
        }
        printf("\n");
        dico_resizer(user_word, word_size,word_state, current_list, &current_list_size);
        //char* very_best_word = best_word(word_size, list, size, current_list, current_list_size);
        //char* very_best_word = naive_solver(word_size, current_list, current_list_size);
        char* very_best_word = best_word(word_size, current_list, current_list_size, current_list, current_list_size);

        printf("Le meilleur mot est %s\n", very_best_word);

        printf("\n\n\n");

        if (current_list_size==1){
            gagne=true;
            printf("Victoire en %d tour(s)!\n", tour_counter+1);
            printf("\\(ᵔᵕᵔ)/\n");
        }
        tour_counter++;
    }

    if (!gagne){
        printf("C'est perdu!\n");
        printf("¯\\_(⊙︿⊙)_/¯\n\n");
    }

    return(0);
}