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

#include <ncurses.h>
#include <stdlib.h>
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
 * A "classe" snake
 */
struct s_snake
{
    unsigned short int speed;
    unsigned short int lenght, scores;
    s_coord position;
    struct s_body body[TAM_MAX];
};

void set_snake_speed(struct s_snake *snake, int new_speed){
    snake->speed = new_speed;
}

int get_snake_speed(struct s_snake *snake){
    return snake->speed;
}

void set_snake_lenght(struct s_snake *snake, int new_lenght){
    snake->lenght = new_lenght;
}

int get_snake_lenght(struct s_snake *snake){
    return snake->lenght;
}

/*
 *Função que inicializa a snake, tornando
 */
struct s_snake *snake_init(void)
{
    struct s_snake *return_snake = malloc (sizeof(struct s_snake));
    return_snake->lenght = START_SNAKE_LENGHT;
    return_snake->position.x = (WORLD_WIDTH - return_snake->lenght) / 2;
    return_snake->position.y = (WORLD_HEIGHT - 1) / 2;
    return return_snake;
}

int move_snake(struct s_snake *snake, struct s_food *food)
{
    int i;
    /*
     * Declaração de váriaveis x e y que recebem as cordenadas da cabeça da snake.
     */
    int x = snake->body[snake->lenght - 1].position.x;
    int y = snake->body[snake->lenght - 1].position.y;

    wclear(snake_world);
    make_food(food,snake, x, y);

    /*
     * Laço que faz cada elemento do vetor body, receber o valor
     * do proximo elemento, o que faz com que a snake se movimente.
     * E também verifica se a cabeça da snake (primeiro elemento) possui
     * as mesmas cordenadas do resto do seu corpo (colisão com ela mesma)
     * caso sim, acabar o jogo.
     */
    for (i = 0; i < (snake->lenght - 1); i++)
    {
        snake->body[i] = snake->body[i + 1];
        mvwaddch(snake_world, snake->body[i].position.y, snake->body[i].position.x, 'o');

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


    make_food(food,snake, x, y);
    for (i = 0; i <= snake->lenght - 1; i++){
        if(x == snake->body[i].position.x && y == snake->body[i].position.y){
            delwin(snake_world);
            endwin();
            show_game_over_window();
        }
    }
    /*
     * A cabeça da snake recebe novas cordenadas, ou seja um ++.
     * Esta parta faz com que a snake se movimente.
     */
    snake->body[snake->lenght - 1].position.x = x;
    snake->body[snake ->lenght - 1].position.y = y;

    /*
     * Checa se o usuario colidiu com a comida, retorna true caso sim,
     * e falso caso nao, e armazena o valor na variavel COLLISION que sera
     * analisada dentro da funçao make_food.
     */
    COLLISION = check_food_collision(food, x, y);

    /*
     * Printa a cabeça da snake, com suas novas cordenadas
     */
    mvwaddch(snake_world, y, x, '@');

    /*
     * Desenha o quadrado ao redor da tela.
     */
    box(snake_world, 0 , 0);
    mvwprintw(snake_world, 1,WORLD_WIDTH / 2, "%d", snake_scores);
    wrefresh(snake_world);
}

void game_loop(){
    int ch, i, food_x, food_y;
    struct s_snake *snake = snake_init();
    struct s_food *food = food_init();
    snake->lenght = 5;
    set_snake_speed(snake, 200);
    timeout(get_snake_speed(snake));

    /*set_food_position(food, rand() % WORLD_WIDTH, rand() % WORLD_HEIGHT);
    mvwaddch(snake_world, get_food_pos_y(food), get_food_pos_x(food), 'X')*/
    /*
     * O tamanho da snake recebe o valor da váriavel snake_lenght a qual será
     * modificado durante a execução do jogo.
     */
    snake_lenght = snake->lenght;
    snake_scores = 1;
    for (i = 0; i < snake->lenght; i++)
    {
        snake->body[i].position.x = snake->position.x + i;
        snake->body[i].position.y = snake->position.y;
    }

    /*
     * Aqui inicia o loop do jogo, que faz com que tudo funcione, este switch
     * e para ler se as setas foram apertadas.
     */
    while ((ch = getch()) != 'x')
    {
        move_snake(snake, food);
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
