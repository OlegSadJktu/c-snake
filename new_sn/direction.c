#include "direction.h"
#include <stdio.h>
#include <stdlib.h>


Direction get_collinear(Direction dir) {
    switch(dir) {
        case TOP:
            return BOTTOM;
        case BOTTOM:
            return TOP;
        case RIGHT:
            return LEFT;
        case LEFT:
            return RIGHT;
    }
    exit(1);
}

Direction get_direction_by_two_points(struct Point *a, struct Point *b) {
    int dx = b->x - a->x;
    int dy = b->y - a->y;
    if ((dx == 0) ^ (dy == 0)) {
        printf("Error while getting direction");
        exit(1);
    }
    if (dx > 0) {
        return RIGHT;
    } else if (dx < 0) {
        return LEFT;
    } else if (dy > 0) {
        return BOTTOM;
    } else if (dy < 0) {
        return TOP;
    }
    return 0;
}

void increment_points(Direction dir, int *x, int *y) {
    switch (dir) {
        case TOP:
            (*y)--;
            break;
        case BOTTOM:
            (*y)++;
            break;
        case RIGHT:
            (*x)++;
            break;
        case LEFT:
            (*x)--;
            break;
    }
}

const char* get_name_by_direction(const Direction dir) {
    switch (dir) {
        case TOP:
            return "TOP";
        case BOTTOM:
            return "BOTTOM";
        case RIGHT:
            return "RIGHT";
        case LEFT:
            return "LEFT";
    }
    exit(1);
}



