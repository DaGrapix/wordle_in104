#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct wordle_letter_list{
    char character;
    bool seen;
    struct wordle_letter_list* next;
};


/*

void letter_check(char* word, char* user_word){
    int len = strlen(word);
    int user_len = strlen(word);
    if (len != user_len){
        printf("Pas le bon nombre de lettres! Reessaye!");
    }

    //Construction de la liste chainee cyclique
    struct wordle_letter_list* old_list = malloc(sizeof(struct wordle_letter_list));
    struct wordle_letter_list* p = old_list;

    old_list->next = NULL;
    old_list->character = word[0];
    old_list->seen = false;
    for (int i = 1; len-1; i++){
        struct wordle_letter_list* new_list = malloc(sizeof(struct wordle_letter_list));
        new_list->next = old_list;
        new_list->character = word[i];
        new_list->seen = false;
        old_list = new_list;
    }
    p->next = old_list;

    char affichage[len];
    for (int i = 0; i <= len - 1; i++){
        for (int j = 0; j <= len - 1; j++){
            if ((user_word[i]==p->character) && (p->character==false)){
                if (i==j){
                    affichage[i] = 'O';
                }
                else{
                    affichage[i] = 'Z';
                }
                p->seen = true;
            }
            else if (j==(len - 1)){
                affichage[i] = 'X';
            }
            else{
                p = p->next;
            }
        }
    }
    printf("%s\n", affichage);
}

*/

int letter_check(char* word, char* user_word){
    int len = strlen(word);
    int user_len = strlen(word);
    if (len != user_len){
        printf("Pas le bon nombre de lettres! Reessaye!");
        return(1);
    }

    bool seen[len];
    for (int i = 0; i <= len - 1; i++){
        seen[i]=false;
    }

    char affichage[len];

    for (int i = 0; i <= len - 1; i++){
        if (user_word[i]==word[i]){
            seen[i] = true;
            affichage[i] = 'O';
        }
    }

    for (int i = 0; i <= len - 1; i++){
        for (int j = 0; j <= len - 1; j++){
            if (i != j){
                if ((user_word[i]==word[j]) && (seen[j]==false)){
                    affichage[i] = 'Z';
                    seen[j] = true;
                }
                else{
                    affichage[i] = 'X';
                }
            }
        }
    }
    printf("%s\n", affichage);
    return(0);

}