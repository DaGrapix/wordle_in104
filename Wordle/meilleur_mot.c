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

int main(){
    clock_t begin = clock();
    srand(time(NULL));

    //dictionnaire
    //char dico_name[32]="dictionnaire_frequence.txt";
    char dico_name[32]="ods4.txt";

    //longueur d'un mot
    printf("Combien de lettres comportent les mots du dictionnaire?\n");
    int word_size;
    scanf("%d", &word_size);
    while ((word_size<=2) || (word_size>10)){
        printf("Choisis un nombre entre 3 et 50!\n");
        scanf("%d", &word_size);
    }
    
    //taille de la liste de mots de word_size lettres
    int list_size;

    //Liste de tous les mots de word_size lettres
    char** list = read_dico(dico_name, &list_size, word_size);

    char* bestWord = best_word(word_size, list, list_size, list, list_size);

    clock_t end = clock();

    float temps = ((float)(end-begin))/CLOCKS_PER_SEC;
    
    printf("\n");
    printf("Nombre de lettres : %d\n", word_size);
    printf("Meilleur mot : %s\n", bestWord);
    printf("entropie de %s : %f\n", bestWord, entropy(bestWord, list_size, list, word_size));
    if (temps>60){
        printf("Temps de calcul: %dmin %ds\n", ((int)temps/60), ((int)temps%60));
    }
    else{
        printf("Temps de calcul: %fs\n", temps);
    }
}