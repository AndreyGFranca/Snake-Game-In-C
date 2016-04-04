/*This file is part of Snake Game.
 *
 *    Snake Game is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Snake Game is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.*
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Snake Game.  If not, see <http://www.gnu.org/licenses/>.
 */

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

