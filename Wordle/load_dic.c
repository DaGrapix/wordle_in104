#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct word_list{
    char* word;
    struct word_list* next;
};

char** read_dico(char* fname, int* size, int word_length){
    char buffer[256];
    struct word_list* old_list = NULL;
    int word_count = 0;

    FILE* in = fopen(fname, "r");
    fscanf(in, "%s", buffer);
    while (!feof(in)){
        struct word_list* new_list = malloc(sizeof(struct word_list));
        if (new_list==NULL){
                fclose(in);
                return(NULL);
            }

        if (strlen(buffer)==word_length){
            char* word = malloc((word_length+1)*sizeof(char));
            if (word==NULL){
                fclose(in);
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
    fclose(in);

    *size = word_count;
    char **list = malloc(word_count*sizeof(char*));
    if (list==NULL){
        return(NULL);
    }

    while (word_count != 0){
        list[word_count-1] = old_list->word;
        struct word_list* tmp = old_list->next;
        old_list = tmp;
        word_count--;
    }
    
    return(list);
}

bool naive_dico(char **list, char *word, int size){
    for (int i = 0; i <= size - 1; i++){
        if (strcmp(word,list[i])==0){
            return(true);
        }
    }
    return(false);
}


bool find_word_dicho(char **list, char *word, int left, int right){
    int length = right-left;
    int middle = (right+left)/2;
    if (length==0){
        if (strcmp(word, list[right])==0){
            return true;
        }
        else{
            return false;
        }
    }
    if (strcmp(word, list[middle]) > 0){
        return find_word_dicho(list, word, middle + 1, right);
    }
    else{
        return find_word_dicho(list, word, left, middle);
    }
}