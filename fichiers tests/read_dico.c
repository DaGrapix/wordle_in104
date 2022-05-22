#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct mot_liste{
    char* mot;
    struct mot_liste* next;
};


char** read_dico(char* fname, int* size, int taille_mot){
    char buffer[256];
    struct mot_liste* old_list;
    int word_count = 0;

    FILE* in = fopen(fname, "rb");
    fscanf(in, "%s", buffer);
    while (!feof(in)){
        struct mot_liste* new_list = malloc(sizeof(struct mot_liste));

        if (strlen(buffer)==taille_mot){
            char* mot = malloc(sizeof(taille_mot));
            new_list->mot = mot;
            new_list->next = old_list;
            old_list = new_list;
        }

        fscanf(in, "%s", buffer);
        word_count++;
    }
    *size = word_count;
    struct mot_list* tmp;
    char** liste = malloc(word_count*sizeof(char*));
    while (word_count != 0){
        liste[word_count] = old_list->mot;
        tmp = old_list->next;
        old_list = tmp;
    }

    return(liste);
}