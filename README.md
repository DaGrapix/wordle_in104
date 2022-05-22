# IN104_WORDLE
Projet de Anthony Kalaydjian et Lucas Duhem
Ce projet consiste à implémenter une version du jeu Wordle en C, ainsi qu'un solveur de ce jeu.



## Commandes de complilation
Pour compiler les différents programmes, placez vous dans le dossier "Wordle" et executez les commades suivates:

*   **Jeu Wordle:**\n
    gcc jeu.c word_compare.c load_dic.c random_word.c

*   **Calcul du meilleur premier coup:**\n
    gcc meilleur_mot.c Wordle_solver.c random_word.c load_dic.c word_compare.c -lm

*   **Solveur du jeu:**\n
    gcc crack_wordle.c word_compare.c load_dic.c random_word.c Wordle_solver.c -lm
