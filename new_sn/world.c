#include "world.h"
#include <stdlib.h>

World *create_world(int size) {
    World *world = malloc(sizeof(World));
    world->size = size;
    world->apple = create_apple(1, 1);
    world->snake = create_snake(size / 2, size/2, 3);
    return world;
}
