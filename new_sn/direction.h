#ifndef DIRECTION_H
#define DIRECTION_H

typedef struct Point {
    int x, y;
} Point;

typedef enum Direction {
    TOP=2,
    RIGHT=3, 
    BOTTOM=5, 
    LEFT=7,
} Direction;

Direction get_collinear(Direction dir);

Direction get_direction_by_two_points(Point *a, Point *b);

void increment_points(Direction dir, int *x, int *y);

const char* get_name_by_direction(const Direction dir);

#endif
