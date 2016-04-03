#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"

struct s_body;
struct s_snake;

unsigned short int snake_lenght;

void set_snake_speed(struct s_snake *snake, int new_speed);

int get_snake_speed(struct s_snake *snake);

struct s_snake *snake_init(void);

int move_snake(struct s_snake *snake);

inline void game_loop(struct s_snake *snake);

#endif // SNAKE_H
