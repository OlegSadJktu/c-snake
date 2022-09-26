#include "apple.h"

Apple *create_apple(int x, int y) {
    Apple *ap = malloc(sizeof(Apple));
    Point point = {x, y};
    ap->point = point;
    return ap;
}
