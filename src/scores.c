#include "window.h"
#include "snake.h"
#include "scores.h"

void set_new_score(int usr_score)
{
    FILE *scores;

    scores = fopen ("scores.txt", "a");

    if(!scores)
     {
        printf( "Erro na abertura do arquivo");
        exit(0);
     }
     fprintf(scores,"%d\n", usr_score);
     fclose(scores);
}

