#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct word_list{
  char *word;
  struct word_list *next;
};
//Ne connaissant pas la longueur du dictionnaire, on va utiliser une liste chainee pour enregistrer tous les mots.

void free_list(struct word_list *list){
    struct word_list *tmp;
    while (list != NULL){
        tmp = list->next;
        free(list);
        list = tmp;
    }
}

char **load_dic(char* fname, unsigned int* size){
    char **words_array;
    unsigned int word_count = 0;
    struct word_list *old_list = NULL;
    char buffer[256];

    FILE *in = fopen(fname, "rb");
    if (in==NULL){
        printf("Erreur dans l'ouverture du dictionnaire");
        return(NULL);
    }

    fscanf(in, "%s", buffer);
    while (!feof(in)){
        struct word_list *new_list = malloc(sizeof(struct word_list*));
        if (new_list==NULL){
            printf("Probleme lors de la creation de la liste chainee");
            fclose(in);
            return(NULL);
        }

        char* word_cpy = malloc(( 1 + strlen(buffer)) * sizeof(char));
        if (word_cpy==NULL){
            printf("Probleme de creation de word_cpy");
            fclose(in);
            return(NULL);
        }

        strcpy(word_cpy, buffer);
        new_list->word = word_cpy;
        new_list->next = old_list;
        old_list = new_list;
        word_count++;

        fscanf(in, "%s", buffer);
    }
    fclose(in);

    words_array = malloc(word_count * sizeof(char**));
    if (words_array==NULL){
        printf("Probleme d'allocation de memoire pour words_array");
        //free_list(old_list);
        return(NULL);
    }

    *size = word_count;

    while (word_count!=1){
        words_array[word_count] = old_list->word;
        struct word_list *tmp = old_list->next;
        old_list = tmp;
        word_count--;
    }

    return(words_array);
}


bool find_word_dicho(char **words, char *word, int left, int right){
    int longueur = right-left;
    int milieu = (right+left)/2;
    if (longueur==0){
        if (strcmp(word, words[right])==0){
            return true;
        }
        else{
            return false;
        }
    }
    if (strcmp(word, words[milieu]) > 0){
        return find_word_dicho(words, word, milieu + 1, right);
    }
    else{
        return find_word_dicho(words, word, left, milieu);
    }
}