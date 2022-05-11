#ifndef WORDLE_SOLVER_H
#define WORDLE_SOLVER_H

char* dec_to_ternary(int number, int word_size);
//  Fonction qui convertit un entier de la base 10 a la base 3.

bool is_similar(char* word, char* word_state, char* list_word, int word_size);
//  Fonction qui verifie si deux mots sont compatibles, suivant une combinaison (ex: Vert Vert Gris Jaune Jaune).

double entropy(char* word, int actual_list_size, char** actual_list, int word_size);
//  fonction qui prend en argument le mot word duquel on veut calculer l'entropie, ainsi que la liste tronquée de tous les mots probables
//  L'entropie se calcule sur cette dernière luste, et non la liste totale de mots de 5 lettres.


char* best_word(int word_size, char** list, int list_size, char** actual_list, int actual_list_size);
//  Renvoit le mot qui possede la plus grande entropie, ie le meilleur choix possible.

char* naive_solver(int word_size, char** actual_list, int actual_list_size);
//  C'est une fonction naive qui renvoit un mot au hasard parmi les mots probables.


#endif