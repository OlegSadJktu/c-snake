#ifndef WORLD_H
#define  WORLD_H

#include "snake.h"
#include "apple.h"
#include <stdlib.h>

typedef struct {
    void *data;

} FieldCell;

typedef struct {
    int size;
    Snake snake;
    Apple apple;
    FieldCell **field;
} World;

World *create_world(int size);

FieldCell *get_field_cell(World *world, int x, int y);

#endif
