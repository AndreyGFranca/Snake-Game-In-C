#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"

struct s_snake
{
  int lenght;
  s_coord position;
  int direction;
};

struct s_snake_body
{
  s_coord position;
};

struct s_snake *snake_init(void);
/*struct s_snake_body *snake_body_init(struct s_snake *snake);*/
void move_snake(WINDOW *win, struct s_snake_body body[], struct s_snake *snake);

#endif // SNAKE_H
