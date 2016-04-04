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
#include <stdlib.h>
#include "food.h"
#include "main.h"

struct s_food
{
    s_coord position;
};

struct s_food *food_init(void)
{
    struct s_food *return_food = malloc(sizeof(struct s_food));
    return return_food;
}

void set_food_position(struct s_food *food, int x, int y){
    food->position.x = x;
    food->position.y = y;
}

int get_food_pos_x(struct s_food *food){
    return food->position.x;
}

int get_food_pos_y(struct s_food *food){
    return food->position.y;
}

/*
 * Funçao que printa um 'x' na tela para representar o food. Caso a cabeça
 * da snake tenha as mesmas cordenadas que o food, entao a snake recebe
 * mais um em sua variavel lenght, ou seja mais um em tamanho
 */
void make_food(struct s_food *food,
               struct s_snake *snake,
               int snake_head_x,
               int snake_head_y)
{
    if (COLLISION == true){
        iniciar_aleatorio();

        /*
         *Gera um numero aleatorio que esteja dentro da janela, estes numeros
         * serao respectivamente as cordenadas do food
         */
        food->position.x = aleatorio(((COLS - WORLD_WIDTH) / 2) + 2, WORLD_WIDTH - 2);
        food->position.y = aleatorio(((LINES - WORLD_HEIGHT) / 2) + 2, WORLD_HEIGHT - 2);
        mvwaddch(snake_world, food->position.y, food->position.x, ' ');
    }
    mvwaddch(snake_world, food->position.y, food->position.x, 'x');

    if ((snake_head_x == food->position.x) && (snake_head_y == food->position.y)){
        snake_lenght+=4;
        snake_scores+=4;
        set_snake_lenght(snake, snake_lenght);
    }
}

/*
 * Funçao booleana que retorna true se a snake comeu o food, e false caso nao
 */
bool check_food_collision(struct s_food *food,
                          int snake_head_x,
                          int snake_head_y)
{
    if ((snake_head_x == food->position.x) && (snake_head_y == food->position.y))
    {
        return true;
    }
    else
        return false;

}

