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
