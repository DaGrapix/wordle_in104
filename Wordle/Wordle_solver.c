#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "random_word.h"

//Convertit un nombre decimal en ternaire
char* dec_to_ternary(int number, int word_size){
    char* configuration = malloc((word_size+1)*sizeof(char));
    //Initialistation a liste nulle
    for (int i = 0; i <= word_size - 1; i++){
        configuration[i]='X';
    }

    int remainder = number;
    int power = 0;
    while (remainder != 0){
        power = 0;
        while (pow(3,power) <= remainder){
            power++;
        }
        power--;
        if (2*pow(3, power) <= remainder){
            configuration[word_size-power-1] = 'O';
            remainder = remainder - 2*pow(3, power);
        }
        else{
            configuration[word_size-power-1] = 'Z';
            remainder = remainder - pow(3, power);
        }
    }
    return(configuration);
}

//Verifie si deux mots sont compatibles avec une configuration donnee
bool is_similar(char* word, char* word_state, char* list_word, int word_size){
    int count;
    bool seen[word_size+1];
    for (int i = 0; i <= word_size - 1; i++){
        seen[i] = false;
    }

    for (int i = 0; i <= word_size - 1;i++){
        if(word_state[i]=='O'){
            if(word[i]==list_word[i]){
                seen[i]=1;
            }
            else{
                return false;
            }
        }
    }

    for (int i = 0; i <= word_size - 1;i++){
        if(word_state[i]=='Z'){
            count=0;
            for(int j= 0;j <= word_size - 1; j++){
                
                if(word[i]==list_word[j] && i!=j){
                    seen[j]=1;
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

    for (int i = 0; i <= word_size - 1;i++){
        if(word_state[i]=='X'){
                for(int j= 0;j <= word_size - 1; j++){
                    //if(word[i]==list_word[j] && seen[i]==0 && seen[j]==0)
                    if(word[j]==list_word[j] && seen[i]==0 && seen[j]==0){
                        return(false);
                    }

                }
            }
        return true;
    }
}

//Problemes....
//Calcul de l'entropie d'un mot
double entropy(char* word, int current_list_size, char** current_list, int word_size){
    //  Liste qui verifie si la comparaison entre 2 mots a deja ete effectuee avec une configuration precedente.
    //  Ceci permet de forcer la sommation a 1 de la probabilite.
    bool partition[current_list_size];
    for (int i = 0; i <= current_list_size - 1; i++){
            partition[i] = false;
        }
    int occurence;
    double probability;
    double word_entropy = 0;
    char *temp_word;
    double somme = - current_list_size;
    for (int j = 0; j <= pow(3, word_size)-1; j++){
        occurence = 0;
        probability = 0;
        //Configuration d'indice j
        char* word_state = dec_to_ternary(j, word_size);
        //On boucle sur tous les mots de la liste des mots possibles
        for (int i = 0; i <= current_list_size - 1; i++){
            temp_word=current_list[i];
            if ((partition[i]==false) && (is_similar(word, word_state, temp_word, word_size)==true)){
                occurence++;
                somme++;
                partition[i]=true;
                //printf("%s est compatible avec %s suivant la config %s\n",word,temp_word,word_state);
            }
            else{
                //printf("%s n'est pas compatible avec %s suivant la config %s\n",word,temp_word,word_state);
            }
        }
        probability=((double)occurence)/current_list_size;
        if (probability != 0.0){
            word_entropy = word_entropy - probability*(log2(probability));
        }
    }
    //free(partition);
    return(word_entropy);
}

//Trouve le mot qui maximise l'entropie
char* best_word(int word_size, char** list, int list_size, char** current_list, int current_list_size){
    double probability;
    double information;
    double* entropy_list = malloc(list_size*sizeof(double));
    char *word;
    char *word_state;

    //Creation de la liste des entropies de chaque mot
    for (int i = 0; i<= list_size - 1; i++){
        word = list[i];
        entropy_list[i] = entropy(word, current_list_size, current_list, word_size);
        printf("%f\n", 100*(float)(i)/list_size);
    }

    //On trouve le mot avec la plus grande entropie
    double max_entropy = entropy_list[0];
    char *best_guess = malloc((word_size+1)*sizeof(char));
    strcpy(best_guess, list[0]);
    for (int i = 0; i<= list_size - 1; i++){
        //printf("%s  :  %f\n", list[i], entropy_list[i]);
        if (entropy_list[i] > max_entropy){
            max_entropy = entropy_list[i];
            strcpy(best_guess, list[i]);
        }
    }
    free(entropy_list);
    //free(best_guess);
    return(best_guess);
}

char* naive_solver(int word_size, char** current_list, int current_list_size){
    char* best_guess = malloc((word_size+1)*sizeof(char));
    best_guess = random_word(current_list, current_list_size);
    return(best_guess);
}










//////////            POUBELLE            //////////

/*
double entropy(char* word, int current_list_size, char** current_list, int word_size){
    int occurence;
    double probability;
    double word_entropy = 0;
    char *temp_word;
    //double test;
    for (int j = 0; j <= pow(3, word_size)-1; j++){
        occurence = 0;
        probability = 0;
        char* word_state = dec_to_ternary(j, word_size);
        for (int i = 0; i <= current_list_size - 1; i++){
            temp_word=current_list[i];
            if (is_similar(word, word_state, temp_word, word_size)==true){
                occurence++;
            }
        }
        probability=((double)occurence)/current_list_size;
        //test = log(1/probability)/log(2);
        if (probability != 0.0){
            word_entropy = word_entropy + probability*(log(1/probability)/log(2));
        }
    }
    return(word_entropy);
}
*/
