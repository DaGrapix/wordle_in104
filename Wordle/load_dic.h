#ifndef LOAD_DIC_H
#define LOAD_DIC_H

char** read_dico(char* fname, int* size, int word_length);
bool find_word_dicho(char **words, char *word, int left, int right);

#endif