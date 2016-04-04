#ifndef WINDOW_H
#define WINDOW_H

#include <curses.h>

#define MENUMAX 3

WINDOW *snake_world;
WINDOW *scores_win;
WINDOW *game_over_win;

void draw_menu(int item);

void init_game_window();

void init_main_window();

void init_highscores_window();

void show_game_over_window();

#endif // WINDOW_H
