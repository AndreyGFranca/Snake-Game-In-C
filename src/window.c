#include <stdlib.h>
#include "window.h"
#include "main.h"
#include "snake.h"
#include "scores.h"
#include "food.h"

/*
 * Função que desenha, e manipula o menu da primeira janela.
 */
void draw_menu(int item)
{
    int i;
    char main_menu[] = "Snake Game!";
    char menu[MENUMAX][21] = {
        "INICIAR JOGO",
        " ",
        "SAIR",
    };
    curs_set(0);
    clear();
    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);
    mvaddstr(1, WORLD_WIDTH / 2 + 5, main_menu);
    for (i = 0; i < MENUMAX; i++)
    {
        if (i == item)
            attron(A_REVERSE);
        mvaddstr(WORLD_HEIGHT / 3 +(i * 2),WORLD_WIDTH / 2 + 5, menu[i]);
        attroff(A_REVERSE);
        refresh();
    }
}

/*
 * Função que inicializa a janela do jogo.
 */
void init_game_window()
{   
    int offsetx, offsety;
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    refresh();
    curs_set(0);

    offsetx = (COLS - WORLD_WIDTH) / 2;
    offsety = (LINES - WORLD_HEIGHT) / 2;

    snake_world = newwin(WORLD_HEIGHT,
                         WORLD_WIDTH,
                         offsety,
                         offsetx);

    /*Entra no loop do jogo*/
    game_loop();

    delwin(snake_world);

    endwin();
}

/*
 * Funçao que inicializa a primeira janela.
 */
void init_main_window()
{
    int key, menu_item = 0;
    curs_set(0);
    initscr();
    draw_menu(menu_item);
    keypad(stdscr,TRUE);
    noecho();
    do
    {
        key = getch();
        switch(key)
        {
        case KEY_DOWN:
            menu_item+=2;
            if(menu_item > MENUMAX-1) menu_item = 0;
            break;
        case KEY_UP:
            menu_item-=2;
            if(menu_item < 0) menu_item = MENUMAX -1;
            break;
        case '\n':
            if (menu_item == MENUMAX - 1){
                delwin(stdscr);
                endwin();
                exit(0);
            }
            else if (menu_item == 0){
                endwin();
                clear();
                init_game_window();
            }
            else if(menu_item == MENUMAX - 2){
            }
            break;
        default:
            break;
        }
        draw_menu(menu_item);
    } while(key != 'x');

    echo();
    endwin();
}

/*
 * Funçao que inicializa a janela dos recordes PS> Incompleto daqui pra baixo.
 */
/*void show_scores_window(){
    int ch;
    initscr();
    noecho();
    cbreak();
    wclear(scores_win);
    scores_win = newwin(0,0,0,0);
    while(true){
        get_scores(scores_win);
        wrefresh(scores_win);
    }


}*/

void show_game_over_window()
{
    int ch;
    initscr();
    noecho();
    cbreak();
    game_over_win = newwin(0,0,0,0);
    while(true){
        mvwaddstr(game_over_win, 10, 25,"Game Over!\n \t\tSeus pontos foram salvos!\n\t");
        wrefresh(game_over_win);
        getch();
        set_new_score(snake_scores);
        exit(0);
    }
    wrefresh(game_over_win);

}
