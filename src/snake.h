#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"

struct s_body;
struct s_snake;

unsigned short int snake_lenght;

struct s_snake *snake_init(void);

/*struct s_snake_body *snake_body_init(struct s_snake *snake);*/
void move_snake(struct s_snake *snake);

inline void game_loop(struct s_snake *snake);

#endif // SNAKE_H
