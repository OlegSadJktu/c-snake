#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdlib.h>
typedef enum {
    START, END
} Pos;

typedef struct DLink {
    struct DLink *prev, *next;
    void *data;

} DLink;

typedef struct DList {
    DLink *head, *tail;
} DList;

void add_to_dlist(DList *list, void *data, Pos pos);

void *delete_from_list(DList *list, Pos pos);

DLink *get_data_from_list(DList *list, Pos pos);

DList *create_dlist();
#endif
