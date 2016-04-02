#include <ncurses.h>
#include "main.h"
#include "snake.h"

int main (void){
  int offsetx, offsety, ch, i;
  WINDOW *snake_world;
  struct s_snake *snake = snake_init();
  struct s_snake_body body[START_SNAKE_LENGHT];


  
  initscr();
  noecho();
  cbreak();
  timeout(TICKRATE);
  keypad(stdscr, TRUE);
  refresh();
  
  offsetx = (COLS - WORLD_WIDTH) / 2;
  offsety = (LINES - WORLD_HEIGHT) / 2;

  snake_world = newwin(WORLD_HEIGHT,
                       WORLD_WIDTH,
                       offsety,
                       offsetx);

  for (i = 0; i < snake->lenght; i++)
    {
      body[i].position.x = snake->position.x + i;
      body[i].position.y = snake->position.y;
    }
  
  while ((ch = getch()) != 'x') {
      move_snake(snake_world, body, snake);
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

  delwin(snake_world);

  endwin();
}
