#include <ncurses.h>
#include "snake.h"

struct s_body
{
  s_coord position;
};

struct s_snake
{
  int lenght;
  s_coord position;
  int direction;
  struct s_body body[START_SNAKE_LENGHT];
};

struct s_snake *snake_init(void)
{
  struct s_snake *return_snake = malloc (sizeof(struct s_snake));
  return_snake->direction = RIGHT;
  return_snake->lenght = START_SNAKE_LENGHT;
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

void move_snake( struct s_snake *snake)
{
  
  int i;
  wclear(snake_world);
  
  for (i = 0; i < (snake->lenght - 1); i++) 
    {
      snake->body[i] = snake->body[i + 1];
      mvwaddch(snake_world, snake->body[i].position.y, snake->body[i].position.x, '@');
    }
  
  int x = snake->body[snake->lenght - 1].position.x;
  int y = snake->body[snake->lenght - 1].position.y;
  
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
  
  snake->body[snake->lenght - 1].position.x = x;
  snake->body[snake ->lenght - 1].position.y = y;
  
  mvwaddch(snake_world, y, x, '#');
  
  box(snake_world, 0 , 0);
  
  wrefresh(snake_world);
}

inline void game_loop(struct s_snake *snake){
  int ch, i;
  for (i = 0; i < snake->lenght; i++)
    {
      snake->body[i].position.x = snake->position.x + i;
      snake->body[i].position.y = snake->position.y;
    }

  while ((ch = getch()) != 'x')
    {
      move_snake(snake);
      if(ch != ERR)
        {
          switch(ch)
            {
            case KEY_UP:
              snake->direction = UP;
              break;
            case KEY_DOWN:
              snake->direction = DOWN;
              break;
            case KEY_RIGHT:
              snake->direction = RIGHT;
              break;
            case KEY_LEFT:
              snake->direction = LEFT;
              break;
            default:
              break;
            }
        }
    }

}
