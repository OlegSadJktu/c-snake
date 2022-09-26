#include "double_list.h"
#include <stdio.h>


typedef struct SimpleData {
    int a;

} SimpleData;

int main() {

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
