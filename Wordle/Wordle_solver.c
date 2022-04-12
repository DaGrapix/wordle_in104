#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/*
char* dec_to_ternary(int j, int word_size){
    char remainder_list[word_size];
    //Initialistation a liste nulle
    for (int i = 0; i <= word_size - 1; word_size++){
        remainder_list[i]='X';
    }
    int remainder = 0;
    int quotient = j;
    int step = 0;
    while (quotient != 0){
        quotient = quotient/3;
        remainder = quotient%3;
        if (remainder==0){
            remainder_list[word_size-1-step]='X';
        }
        else if (remainder==1){
            remainder_list[word_size-1-step]='Z';
        }
        else{
            remainder_list[word_size-1-step]='O';
        }
        step++;
    }

    return(remainder_list);

}

char* best_word(int word_size, char** list, int list_size, char** actual_list, int actual_list_size){
    double probbability;
    double information;
    double* entropy_list[list_size + 1];
    char word[word_size + 1];
    char word_state[word_size + 1];

    for (int i = 0; i<= list_size - 1; i++){
        word = list[i];
        entropy_list[i] = entropy(word, word_state, actual_list_size, actual_list, word_size);
    }

    int entropy=entropy_list[0];
    char best_guess[word_size + 1] = list[0];
    for (int i = 0; i<= list_size - 1; i++){
        if (entropy_list[i] > entropy){
            entropy = entropy_list;
            best_guess = list[i];
        }
    }
    return(best_guess);
}


char* entropy(char* word, char* word_state, int actual_list_size, char** actual_list, int word_size){
    int occurence = 0;
    double probability = 0;
    double entropy = 0;
    char temp_word[word_size + 1];
    for (int j = 0; j <= pow(3, word_size)-1; j++){
        word_state = dec_to_ternary(j, word_size);
        for (int i = 0; i <= actual_list_size - 1; i++){
            temp_word=actual_list[i];
            if (is_similar(word, word_state, temp_word, word_size)==true){
                occurence++;
            }
            probability=occurence/actual_list_size;
            entropy = entropy + probability*log(1/probability)/log(2);
        }
    }
}
*/
bool is_similar(char* word, char* word_state, char* list_word, int word_size){
    int count;
    bool seen[word_size];
    for (int i = 0; i <= word_size - 1; i++){
        seen[i] = 0;
    }
    int r=0;
    for (int j = 0; j <= word_size - 1;j++){
        if(word_state[j]=='O'){
            if(word[j]==list_word[j]){
                seen[j]=1;
            }
            else{
                return false;
            }
        }
        else if(word_state[j]=='Z'){
            count=0;
            for(int i= 0;i <= word_size - 1; i++){
                
                if(word[j]==list_word[i] && i!=j){
                    seen[i]=1;
                }
                else{
                    count++;
                
                    if(count==word_size){
                        return false;
                    }
                }
        
            }
            
        }
        else if(word_state[j]=='X'){
            for(int i= 0;i <= word_size - 1; i++){
                if(word[j]==list_word[i] && seen[i]==0 && seen[j]==0){
                    return(false);
                }

    }
    
    return true;
}