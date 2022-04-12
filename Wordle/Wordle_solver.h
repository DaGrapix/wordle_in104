#ifndef WORDLE_SOLVER_H
#define WORDLE_SOLVER_H

char* dec_to_ternary(int j, int word_size);
char* best_word(int word_size, char** list, int list_size, char** actual_list, int actual_list_size);
char* entropy(char* word, char* word_state, int actual_list_size, char** actual_list, int word_size);
bool is_similar(char* word, char* word_state, char* list_word, int word_size);
#endif