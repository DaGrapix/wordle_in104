#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

char* dec_to_ternary(int number, int word_size){
    char* configuration = malloc((word_size+1)*sizeof(char));
    //Initialistation a liste nulle
    for (int i = 0; i <= word_size - 1; i++){
        configuration[i]='X';
    }
    //return(configuration);
    int remainder = number;
    int power = 0;
    while (remainder != 0){
        power = 0;
        while (pow(3,power) <= remainder){
            power++;
        }
        power--;
        if (2*pow(3, power) <= remainder){
            configuration[power] = 'O';
            remainder = remainder - 2*pow(3, power);
        }
        else{
            configuration[power] = 'Z';
            remainder = remainder - pow(3, power);
        }
    }
    return(configuration);
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
        printf("%f\n", (float)(i)/list_size);
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

bool is_similar(char* word, char* word_state, char* list_word, int word_size){
    int count;
    bool seen[word_size];
    for (int i = 0; i <= word_size - 1; i++){
        seen[i] = 0;
    }

    for (int j = 0; j <= word_size - 1;j++){
        if(word_state[j]=='O'){
            if(word[j]==list_word[j]){
                seen[j]=1;
            }
            else{
                return false;
            }
        }
    }

    for (int j = 0; j <= word_size - 1;j++){
        if(word_state[j]=='Z'){
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
    }

    for (int j = 0; j <= word_size - 1;j++){
        if(word_state[j]=='X'){
                for(int i= 0;i <= word_size - 1; i++){
                    if(word[j]==list_word[i] && seen[i]==0 && seen[j]==0){
                        return(false);
                    }

                }
            }
        return true;
    }
}

*/