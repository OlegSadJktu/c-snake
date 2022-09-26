#ifndef APPLE_H
#define APPLE_H

#include "direction.h"

typedef struct Apple {
    Point point;
} Apple;

Apple *create_apple(Point *pos);

#endif
