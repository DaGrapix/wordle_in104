
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct word_list{
    char* word;
    struct word_list* next;
};

void free_list(struct word_list* list){
    struct word_list* tmp;
    while (list != NULL){
        tmp = list->next;
        free(list);
        list = tmp;
    }
}

char** read_dico(char* fname, int* size, int word_length){
    char buffer[256]="";
    struct word_list* old_list;
    int word_count = 0;

    FILE* in = fopen(fname, "rb");
    fscanf(in, "%s", buffer);
    while (!feof(in)){
        struct word_list* new_list = malloc(sizeof(struct word_list));
        if (new_list==NULL){
                free_list(old_list);
                return(NULL);
            }

        if (strlen(buffer)==word_length){
            char* word = malloc(sizeof(word_length));
            if (word==NULL){
                free_list(old_list);
                return(NULL);
            }

            strcpy(word, buffer);
            new_list->word = word;
            new_list->next = old_list;
            old_list = new_list;
            word_count++;
        }
        
        fscanf(in, "%s", buffer);
    }

    *size = word_count;
    char** list = malloc(word_count*sizeof(char*));
    if (list==NULL){
        free_list(old_list);
        return(NULL);
    }

    word_count--;

    while (word_count != 0){
        list[word_count] = old_list->word;
        struct word_list* tmp = old_list->next;
        old_list = tmp;
        word_count--;
    }
    
    free_list(old_list);
    return(list);
}

int main(){
    char dico_name[8]="ods4.txt";
    int size;
    char** list = read_dico(dico_name, &size, 4);
    size--;
    while (size!=0){
        printf("%s\n", list[size]);
        size--;
    }
}