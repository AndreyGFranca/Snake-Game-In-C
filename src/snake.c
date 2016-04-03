#include <ncurses.h>
#include "snake.h"
#include "window.h"

/*
 * Struct que armazena a posição de cada '@' da snake
 */
struct s_body
{
    s_coord position;
};

/*
 * A classe snake
 */
struct s_snake
{
    unsigned short int lenght;
    s_coord position;
    int direction;
    unsigned short int speed;
    struct s_body body[START_SNAKE_LENGHT];
};

void set_snake_speed(struct s_snake *snake, int new_speed){
    snake->speed = new_speed;
}

int get_snake_speed(struct s_snake *snake){
    return snake->speed;
}

/*
 *Função que inicializa a snake, tornando
 */
struct s_snake *snake_init(void)
{
    struct s_snake *return_snake = malloc (sizeof(struct s_snake));
    return_snake->direction = RIGHT;
    return_snake->lenght = START_SNAKE_LENGHT;
    return_snake->position.x = (WORLD_WIDTH - return_snake->lenght) / 2;
    return_snake->position.y = (WORLD_HEIGHT - 1) / 2;
    return return_snake;
}

int move_snake( struct s_snake *snake)
{

    int i;
    wclear(snake_world);

    int x = snake->body[snake->lenght - 1].position.x;
    int y = snake->body[snake->lenght - 1].position.y;
  /*
   *Laço que faz cada elemento do vetor body, receber o valor do proximo
   * elemento, o que faz com que a snake se movimente.
   */
    for (i = 0; i < (snake->lenght - 1); i++)
    {
        snake->body[i] = snake->body[i + 1];
        mvwaddch(snake_world, snake->body[i].position.y, snake->body[i].position.x, 'o');

        if(snake->body[snake->lenght - 1].position.x == snake->body[i - 1].position.x &&
           snake->body[snake->lenght - 1].position.y == snake->body[i - 1].position.y)
            init_main_window(snake);
    }

   /*
    * Verifica se a snake colidiu com a borda
    */
    if (U == 1)
        y - 1 == 0 ? y = WORLD_HEIGHT - 2 : y--;
    if(D == 1)
        y + 1 == WORLD_HEIGHT - 1 ? y = 1 : y++;
    if(R == 1)
        x + 1 == WORLD_WIDTH - 1 ? x = 1 : x++;
    if(L == 1)
        x - 1 == 0 ? x = WORLD_WIDTH - 2 : x--;

    snake->body[snake->lenght - 1].position.x = x;
    snake->body[snake ->lenght - 1].position.y = y;

    mvwaddch(snake_world, y, x, '/xDB');

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
                if (D == 0)
                {
                    L = 0, D = 0, R = 0,
                    U = 1;
                }
                break;
            case KEY_DOWN:
                if (U == 0)
                {
                    L = 0, D = 1, R = 0,
                    U = 0;
                }
                break;
            case KEY_RIGHT:
                if (L == 0)
                {
                    L = 0, D = 0, R = 1,
                    U = 0;
                }
                break;
            case KEY_LEFT:
                if (R == 0)
                {
                    L = 1, D = 0, R = 0,
                    U = 0;
                }
                break;
            default:
                break;
            }
        }
    }

}
