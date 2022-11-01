#include "world.h"

World *create_world(int size) {
    World *world = malloc(sizeof(World));
    world->size = size;
    world->field = malloc(sizeof(FieldCell) * size * size);
    return world;
}

FieldCell *get_field_cell(World *world, int x, int y) {
    if (world->size < x || world->size < y) {
        exit(1);
    }
    return world->field[x * world->size + y];

}
