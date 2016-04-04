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

#ifndef MAIN_H
#define MAIN_H

#include <curses.h>
#include <stdlib.h>

#define WORLD_WIDTH 50
#define WORLD_HEIGHT 20
#define START_SNAKE_LENGHT 3

void iniciar_aleatorio(void);
int aleatorio(int a,int b);

bool U, D, R, L;
bool COLLISION;
typedef struct {
    unsigned short int x;
    unsigned short int y;
} s_coord;

#endif // MAIN_H
