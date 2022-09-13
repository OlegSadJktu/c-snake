#include "snake.h"


void add_cell(Snake *sn, Direction dir) {
    SnakeCell *cell = malloc(sizeof(SnakeCell));
    SnakeCell *tail = sn->body->tail->data;
    int x = tail->pos->y;
    int y = tail->pos->y;
    increment_points(dir, &x, &y);
    cell->pos->x = x;
    cell->pos->y = y;
    add_to_dlist(sn->body, cell, END);
}


Snake *create_snake(int x, int y, int size) {
    Snake *sn = malloc(size);
    SnakeCell *sc = malloc(sizeof(SnakeCell));
    sc->pos->x = x;
    sc->pos->y = y;
    sn->body = create_dlist();
    add_to_dlist(sn->body, sc, END);
    add_cell(sn, LEFT);
    for (int i = 0; i < size; i++)  {
        add_cell(sn, LEFT);
    }
    return sn;
}
