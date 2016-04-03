#ifndef WINDOW_H
#define WINDOW_H

#include <curses.h>

#define MENUMAX 3

WINDOW *snake_world;

void draw_menu(int item);

void init_menu_window();

inline void init_game_window();

#endif // WINDOW_H
