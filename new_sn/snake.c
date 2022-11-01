#include "snake.h"


void add_cell(Snake *sn, Direction dir) {
    SnakeCell *cell = malloc(sizeof(SnakeCell));
    SnakeCell *tail = sn->body->tail->data;
    tail->pos = malloc(sizeof(Point));
    int x = tail->pos->y;
    int y = tail->pos->y;
    increment_points(dir, &x, &y);
    cell->pos = malloc(sizeof(Point));
    cell->pos->x = x;
    /* printf("debu\n"); */
    cell->pos->y = y;
    add_to_dlist(sn->body, cell, END);
}

Snake *create_snake(int x, int y, int size) {
    SnakeCell *sc = malloc(sizeof(SnakeCell));
    Snake *sn = malloc(sizeof(Snake));
    sc->pos = malloc(sizeof(Point));
    sn->ate = 0;
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

void move_snake(Snake *sn, Direction dir) {
    DList *body = sn->body;
    SnakeCell *tail = body->tail->data;
    SnakeCell *head = body->head->data;
    int nx, ny;
    nx = head->pos->x;
    ny = head->pos->y;
    increment_points(dir, &nx, &ny);
    delete_from_list(body, END);
    add_to_dlist(body, tail, START);
    /* increment_points(dir, , int *y) */
}

