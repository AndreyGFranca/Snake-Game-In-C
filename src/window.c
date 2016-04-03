#include "window.h"
#include "main.h"

/*
 * Função que desenha, e manipula o menu da primeira janela.
 */
void draw_menu(int item)
{
    int i;
    char main_menu[] = "Snake Game!";
    char menu[MENUMAX][21] = {
        "INICIAR JOGO",
        "HIGHSCORES",
        "SAIR",
    };

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
 * Funçao que inicializa a primeira janela.
 */
void init_menu_window()
{

    int key, menu_item = 0;

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
            menu_item++;
            if(menu_item > MENUMAX-1) menu_item = 0;
            break;
        case KEY_UP:
            menu_item--;
            if(menu_item < 0) menu_item = MENUMAX-1;
            break;
        case '\n':
            if (menu_item = 0)
                menu_item = MENUMAX-1;
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
 * Função que inicializa a janela do jogo.
 */
inline void init_game_window()
{
    int offsetx, offsety;
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
}

