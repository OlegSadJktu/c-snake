#include <time.h>
#include <stdio.h>
#include <curses.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

// Prime numbers
typedef enum {
    TOP=2,
    RIGHT=3,
    BOTTOM=5,
    LEFT=7,
} Direction;

typedef struct SnakeCell {
    int x;
    int y;
    struct SnakeCell *prev, *next;
} SnakeCell;


typedef struct Snake {
    Direction ate_dir;
    struct SnakeCell *head, *tail;
    int lenght;
} Snake;

typedef struct Apple {
    int x;
    int y;
} Apple;

typedef struct World {
    int x, y, size;
    Snake *snake;
    Apple *apple;
} World;

int body_collision(Snake *snake, int x, int y);


void apple_new_pos(World *world, int *x, int *y) {
    int free_space = pow(world->size - 2, 2) - world->snake->lenght;
    int ran = 2;// rand() % free_space;
    for (int i = 1; i < world->size - 1; i++) {
        for (int j = 1; j < world->size - 1; j++) {
            if (!body_collision(world->snake, i + world->x, j + world->y)) {
                ran--;
                if (!ran) {
                    *x = i + world->x;
                    *y = j + world->y;
                    return;
                }
            }
        }
    }
    exit(1);
}

void increment_coord(int *x, int *y, Direction dir) {
    switch (dir) {
        case BOTTOM:
            (*y)++;
            break;
        case TOP:
            (*y)--;
            break;
        case LEFT:
            (*x)--;
            break;
        case RIGHT:
            (*x)++;
            break;
    }
}

Direction get_dir_by_two_cells(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (!(dy ^ dx)) {
        exit(1);
    }
    if (dx == 1) {
        return RIGHT;
    } else if (dx == -1) {
        return LEFT;
    } else if (dy == 1) {
        return BOTTOM;
    }
    return TOP;
}

void add_cell(Snake *shake, Direction dir) {
    shake->lenght++;
    SnakeCell *last = shake->tail;
    int x = last->x;
    int y = last->y;
    increment_coord(&x,  &y, dir);
    SnakeCell *new = malloc(sizeof(SnakeCell));
    new->x = x;
    new->y = y;
    new->next = last;
    last->prev = new;
    shake->tail = new;
}

Direction get_dir(int key) {
    switch (key) {
        case KEY_UP:
        case 'k':
            return TOP;
        case KEY_DOWN:
        case 'j':
            return BOTTOM;
        case KEY_RIGHT:
        case 'l':
            return RIGHT;
        case KEY_LEFT:
        case 'h':
            return LEFT;
    }
    return -1;
}

int wall_collision(World *world, int x, int y) {
    int xc = world->x >= x || world->x + world->size - 1 <= x;
    int yc = world->y >= y || world->y + world->size - 1 <= y;
    if (xc || yc) {
        return 1;
    }
    return 0;
}

int body_collision(Snake *snake, int x, int y) {
    SnakeCell *sc = snake->head;
    while (sc->prev != NULL) {
        if (sc->x == x && sc->y == y) {
            return 1;
        }
        sc = sc->prev;
    }
    return 0;
}

int apple_collision(World *world, int x, int y) {
    if (world->apple->x == x && world->apple->y == y) {
        return 1;
    }
    return 0;
}

void apple_collision_handler(World *world) {
    int x, y;
    /* apple_new_pos(world, &x, &y); */
    SnakeCell *last = world->snake->tail;
    SnakeCell *preLast = last->next;
    /* world->apple->x = x; */
    /* world->apple->y = y; */
    world->snake->ate_dir = get_dir_by_two_cells(preLast->x, preLast->y, last->x, last->y);
}

void move_shake(World *world, Snake *shake, Direction dir) {
    SnakeCell *first = shake->head;
    SnakeCell *preFirst = first->prev;
    SnakeCell *last = shake->tail;
    SnakeCell *preLast = shake->tail->next;
    Direction prevdir = get_dir_by_two_cells(first->x, first->y, preFirst->x, preFirst->y);
    if (prevdir == dir) {
        return;
    }
    int x = first->x;
    int y = first->y;
    increment_coord(&x, &y, dir);
    if (wall_collision(world, x, y)) {
        return;
    } 
    if (shake->ate_dir != 0) {
        add_cell(shake, shake->ate_dir);
        shake->ate_dir = 0;
    }
    if (body_collision(shake, x, y)) {
        return;
    }
    if (apple_collision(world, x, y)){
        apple_collision_handler(world);
    }

    last->x = x;
    last->y = y;
    shake->tail = preLast;
    shake->head = last;
    preLast->prev = NULL;
    last->next = NULL;
    first->next = last;
    last->prev = first;
};

Direction get_collinear(Direction dir) {
    switch (dir) {
        case TOP:
            return BOTTOM;
        case BOTTOM:
            return TOP;
        case RIGHT:
            return LEFT;
        case LEFT:
            return RIGHT;
    }
}

char *get_drawsymbol(int vectors) {
    switch (vectors) {
        case 6: 
            return "\u2570";
        case 15:
            return "\u256d";
        case 35:
            return "\u256e";
        case 14: 
            return "\u256f";
        case 10:
            return "\u2502";
        case 21:
            return "\u2500";
        default:
            return "o";
    }
}

void draw_cell(Direction next, Direction prev, int x, int y) {
    /* printf("prev and next %i %i\n", prev, next); */
    int a = next * prev;
    char *str = get_drawsymbol(a);
    mvaddstr(y, x, str);
}

void draw_snake(Snake *snake) {
    SnakeCell *cell = snake->head;
    move(cell->y, cell->x);
    addstr("o");
    cell = cell->prev;
    Direction prev, next;
    while(cell != NULL) {
        /* move(cell->y, cell->x); */
        /* addstr("o"); */
        next = get_dir_by_two_cells(cell->x, cell->y, 
                cell->next->x, cell->next->y);
        printf("prev , next => %i %i   ", prev, next);
        if (cell->prev == NULL) {
            prev = get_collinear(next);
        } else {
            prev = get_dir_by_two_cells(cell->x, cell->y, 
                    cell->prev->x, cell->prev->y);
        }
        draw_cell(next, prev, cell->x, cell->y);
        cell = cell->prev;
    }
}

void draw_wall(int x, int y, int size) {
    move(y, x);
    addstr(" ");
    for (int i = 2; i < size; i++) {
        addstr("-");
    }
}

void draw_world(World *world) {
    draw_wall(world->x, world->y,  world->size);
    for (int i = 1; i < world->size -1; i++) {
        move(i + world->y, world->x);
        addstr("|");
        move(i + world->y, world->x + world->size-1);
        addstr("|");
    }
    draw_wall(world->x, world->y + world->size - 1, world->size);
    draw_snake(world->snake);
    move(world->apple->y, world->apple->x);
    addstr("*");
    refresh();
}

Snake *create_shake(int x, int y, int lenght) {
    Snake *sh = malloc(sizeof(Snake));
    SnakeCell *cell = malloc(sizeof(SnakeCell));
    cell->x = x; 
    cell->y = y;
    sh->head = cell;
    sh->tail = cell;
    sh->lenght = 1;
    for (int i = 0; i < lenght; i++) {
        add_cell(sh, LEFT);
    }
    return sh;
}

World *create_world(int x, int y, int size, Snake *snake) {
    World *world = malloc(sizeof(World));
    Apple *apple = malloc(sizeof(Apple));
    world->apple = apple;
    world->x = x - size / 2;
    world->y = y - size / 2;
    apple->x = world->x + 1;
    apple->y = world->y + 1;
    world->snake = snake;
    world->size = size;
    return world;
}

const int world_size = 11;
const int snake_size = 2;


int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    int row, col;
    initscr();
    getmaxyx(stdscr, row, col);
    keypad(stdscr, 1);
    int key;
    int y = row / 2;
    int x = col / 2;
    curs_set(0);
    Snake *snake = create_shake(x, y, snake_size);
    World *world = create_world(x, y, world_size, snake);
    draw_world(world);
    while((key = getch()) != 'q') {
        clear();
        move_shake(world, snake, get_dir(key));
        draw_world(world);
    }

    endwin(); 
    return 0;

}
