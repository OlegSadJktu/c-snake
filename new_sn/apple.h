#ifndef APPLE_H
#define APPLE_H

#include "direction.h"
#include <stdlib.h>

typedef struct {
    Point point;
} Apple;

Apple *create_apple(int x, int y);

#endif
