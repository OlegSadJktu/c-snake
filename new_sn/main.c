#include "double_list.h"
#include "world.h"
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>


typedef struct SimpleData {
    int a;

} SimpleData;


void test(unsigned int a) {
    printf("%u\n", a);
}

int main() {
    int a = 1 ;
    test(a );
    int maxy, maxx;
    int x = 0;
    initscr();
    getmaxyx(stdscr, maxy, maxx);
    curs_set(0);

    int input;
    DList *list = create_dlist();
    Snake *snake = create_snake(5, 5, 3);
    /* return 0; */

    while ((input = getch()) != 'q') {
        clear();
        /* printf("%c", input); */
        mvaddch(maxy / 2, x, 'o');
        x++;
    }
    
    endwin();


}

int main2(int argc, char **argv) {
    DList *list = create_dlist();
    for (int i = 0; i < 10 ; i ++) {
        SimpleData *data = malloc(sizeof(SimpleData));
        data->a = i;
        printf("%i ", data->a);
        add_to_dlist(list, data, START);
    }

    printf("\n\n");
    DLink *link = get_data_from_list(list, START);
    SimpleData *sd;
    for (int i = 0; i < 10; i++) {
        if (link == NULL || link->data == NULL) {
            continue;
        }
        sd = link->data;
        printf("%i ", sd->a);
        link = link->prev;
    }
    printf("\n\n");
    for (int i = 0; i < 10; i++) {
        sd = delete_from_list(list, START);
        printf("%i ", sd->a);
    }

    printf("\n\n");
    printf("%i, pointer => %p\n", list->head == list->tail, list->head);

    return 0;

}
