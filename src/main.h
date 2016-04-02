#ifndef MAIN_H
#define MAIN_H
#include <ncurses.h>

#define WORLD_WIDTH 50
#define WORLD_HEIGHT 20
#define TICKRATE 100
#define START_SNAKE_LENGHT 10

WINDOW *snake_world;

enum direction { UP, DOWN, RIGHT, LEFT };

typedef struct {
  unsigned short int x;
  unsigned short int y;
} s_coord;

#endif // MAIN_H
