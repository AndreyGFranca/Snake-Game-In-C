/*This file is part of Snake Game.
 *
 *    Snake Game is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    Snake Game is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.*
 *
 *    You should have received a copy of the GNU General Public License
 *    along with Snake Game.  If not, see <http://www.gnu.org/licenses/>.
 */

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
