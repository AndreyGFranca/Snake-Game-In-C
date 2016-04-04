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

#ifndef FOOD_H
#define FOOD_H

#include "window.h"
#include "snake.h"


struct s_food;

struct s_food *food_init(void);

void set_food_position(struct s_food *food, int x, int y);

int get_food_pos_x(struct s_food *food);

int get_food_pos_y(struct s_food *food);

void make_food(struct s_food *food,
               struct s_snake *snake,
               int snake_head_x,
               int snake_head_y);

bool check_food_collision(struct s_food *food,
                          int snake_head_x,
                          int snake_head_y);

#endif // FOOD_H
