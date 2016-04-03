#ifndef MAIN_H
#define MAIN_H

#include <curses.h>

#define WORLD_WIDTH 50
#define WORLD_HEIGHT 20
#define START_SNAKE_LENGHT 10

enum direction { UP, DOWN, RIGHT, LEFT };

bool U, D, R, L;

typedef struct {
    unsigned short int x;
    unsigned short int y;
} s_coord;

#endif // MAIN_H
