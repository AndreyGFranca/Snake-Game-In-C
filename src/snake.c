#include <ncurses.h>
#include "snake.h"

struct s_snake *snake_init(void)
{
  struct s_snake *return_snake = malloc (sizeof(struct s_snake));
  return_snake->direction = RIGHT;
  return_snake->lenght = 10;
  return_snake->position.x = (WORLD_WIDTH - return_snake->lenght) / 2;
  return_snake->position.y = (WORLD_HEIGHT - 1) / 2;
  return return_snake;
}

/*struct s_snake_body *snake_body_init(struct s_snake *snake)
{
  int i;
  struct s_snake_body return_body[START_SNAKE_LENGHT];
  for (i = 0; i < snake->lenght; i++)
    {
      return_body[i].position.x = snake->position.x + i;
      return_body[i].position.y = snake->position.y;
    }
  return return_body;
}*/

void move_snake(WINDOW *win, 
                struct s_snake_body body[],
                struct s_snake *snake)
{
  
  int i;
  wclear(win);
  
  for (i = 0; i < (snake->lenght - 1); i++) 
    {
      body[i] = body[i + 1];
      mvwaddch(win, body[i].position.y, body[i].position.x, '@');
    }
  
  int x = body[snake->lenght - 1].position.x;
  int y = body[snake->lenght - 1].position.y;
  
  switch (snake->direction)
    {
    case UP:
      y - 1 == 0 ? y = WORLD_HEIGHT - 2 : y--;
      break;
    case DOWN:
      y + 1 == WORLD_HEIGHT - 1 ? y = 1 : y++;
      break;
    case RIGHT:
      x + 1 == WORLD_WIDTH - 1 ? x = 1 : x++;
      break;
    case LEFT:
      x - 1 == 0 ? x = WORLD_WIDTH - 2 : x--;
      break;
      
    default:
      break;
    }
  
  body[snake->lenght - 1].position.x = x;
  body[snake ->lenght - 1].position.y = y;
  
  mvwaddch(win, y, x, '#');
  
  box(win, 0 , 0);
  
  wrefresh(win);
}
