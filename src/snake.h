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

#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"
#include "food.h"

#define TAM_MAX WORLD_HEIGHT*WORLD_WIDTH

struct s_body;
struct s_snake;
unsigned short int snake_lenght, snake_scores;

void set_snake_speed(struct s_snake *snake, int new_speed);

int get_snake_speed(struct s_snake *snake);

void set_snake_lenght(struct s_snake *snake, int new_lenght);

int get_snake_lenght(struct s_snake *snake);

struct s_snake *snake_init(void);

int move_snake(struct s_snake *snake, struct s_food *food);

void game_loop();

#endif // SNAKE_H
