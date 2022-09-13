#include "direction.h"
#include "double_list.h"

typedef struct SnakeCell {
    struct Point *pos;
} SnakeCell;

typedef struct Snake {
    DList *body;
} Snake;

void add_cell(Snake *sn, Direction dir);

Snake *create_snake(int x, int y, int size);
