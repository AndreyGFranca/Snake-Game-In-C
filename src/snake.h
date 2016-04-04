#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"
#include "food.h"

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
