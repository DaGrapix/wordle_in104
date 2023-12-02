# IN104_WORDLE
Project by Anthony Kalaydjian and Lucas Duhem.<br />
This project aims to implement a version of the Wordle game in C, as well as a solver for this game.

## Compilation Commands
To compile the different programs, navigate to the "Wordle" folder and execute the following commands:

*   **Wordle Game:**<br />
    gcc jeu.c word_compare.c load_dic.c random_word.c

*   **Best First Move Calculation:**<br />
    gcc meilleur_mot.c Wordle_solver.c random_word.c load_dic.c word_compare.c -lm

*   **Game Solver:**<br />
    gcc crack_wordle.c word_compare.c load_dic.c random_word.c Wordle_solver.c -lm
