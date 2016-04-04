#include <stdlib.h>
#include "food.h"
#include "main.h"

int aleatorio(int a,int b){
    double r;
    r=(double)rand()/RAND_MAX;
    return (int)(a+(r*(b-a)));
}
void iniciar_aleatorio(void) {
    srand((unsigned int)time(NULL));
    rand();  rand();  rand(); rand();
}

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

void make_food(struct s_food *food,struct
               s_snake *snake,
               int snake_head_x,
               int snake_head_y)
{
    static int new_lenght;

    if (COLLISION == true){
        iniciar_aleatorio();
        food->position.x = aleatorio(((COLS - WORLD_WIDTH) / 2) + 2, WORLD_WIDTH - 2);
        food->position.y = aleatorio(((LINES - WORLD_HEIGHT) / 2) + 2, WORLD_HEIGHT - 2);
        mvwaddch(snake_world, food->position.y, food->position.x, ' ');
    }
    mvwaddch(snake_world, food->position.y, food->position.x, 'x');

    if ((snake_head_x == food->position.x) && (snake_head_y == food->position.y)){
        set_snake_lenght(snake, new_lenght++);
    }
}

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

