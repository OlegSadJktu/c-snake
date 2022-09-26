#ifndef WORLD_H
#define  WORLD_H

#include "snake.h"
#include "apple.h"
#include <stdlib.h>

typedef struct {
    int size;
    Snake *snake;
    Apple *apple;
} World;

World *create_world(int size);

#endif
