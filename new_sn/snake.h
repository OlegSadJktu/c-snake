#ifndef SNAKE_H
#define SNAKE_H

#include "direction.h"
#include "double_list.h"

typedef struct SnakeCell {
    struct Point *pos;
} SnakeCell;

typedef struct Snake {
    DList *body;
    int ate;
} Snake;

void add_cell(Snake *sn, Direction dir);

Snake *create_snake(int x, int y, int size);

void move_snake(Snake *sn, Direction dir);

#endif
