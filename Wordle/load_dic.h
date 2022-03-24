#ifndef LOAD_DIC_H
#define LOAD_DIC_H

char **load_dic(char *fname, unsigned int *size);
void free_list(struct word_list* list);
bool find_word_dicho(char **words, char *word, int left, int right);


#endif