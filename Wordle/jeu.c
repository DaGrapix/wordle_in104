#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#DEFINE dico "dico.txt"


int main(){
    FILE* in = fopen(dico, 'rb');
    if (in==NULL){
        printf("Problème lors de l'ouverture du dictionnaire");
        return 1;
    }



    int nb_tour = 0;
    bool gagne = false;
    char buffer[5];
    //
    while (nb_tour<6 && !gagne){
        fscanf(in, "%s\n", buffer);
    }
}