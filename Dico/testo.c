
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct mot_liste{
    char* mot;
    struct mot_liste* next;
};

char** read_dico(char* fname, int* size, int taille_mot){
    char buffer[256]="";
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
            word_count++;
        }

        fscanf(in, "%s", buffer);
    }

    *size = word_count;
    char** liste = malloc(word_count*sizeof(char*));

    while (word_count != 0){
        liste[word_count] = old_list->mot;
        struct mot_liste* tmp = old_list->next;
        old_list = tmp;
        word_count--;
    }

    return(liste);
}

int main(){
    char dico_name[8]="ods4.txt";
    //char dico_name[8]="test.txt";
    int size;
    //printf("%s\n", dico_name);
    char** liste = read_dico(dico_name, &size, 3);
    while (size!=0){
        printf("%s", liste[size]);
        size--;
    }
   //printf("%s", liste[0]);
}