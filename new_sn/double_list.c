#include "double_list.h"

void add_to_dlist(DList *list, void *data, Pos pos) {
    DLink *newLink = malloc(sizeof(DLink));
    newLink->data = data;
    if (list->head == NULL) {
        list->head = newLink;
        list->tail = newLink;
        return;
    }
    DLink *tmp;
    switch (pos) {
        case START:
            tmp = list->head;
            tmp->next = newLink;
            newLink->prev = tmp;
            list->head = newLink;
            break;
        case END:
            tmp = list->tail;
            tmp->prev = newLink;
            newLink->next = tmp;
            list->tail =  newLink;
            break;
    }
}

DLink *get_data_from_list(DList *list, Pos pos) {
    if (pos == START) {
        return list->head;
    }
    return list->tail;
}

void *delete_from_list(DList *list, Pos pos) {
    DLink *link;
    if (list->head == NULL) {
        return NULL;
    }
    void *data;
    if (list->head == list->tail) {
        link = list->head;
        list->head = NULL;
        list->tail = NULL;
        data = link->data;
        free(link);
        return data;
    }
    switch(pos) {
        case START:
            link = list->head;
            link->prev->next = NULL;
            list->head = link->prev;
            break;
        case END:
            link = list->tail;
            link->next->prev = NULL;
            list->tail = link->prev;
            break;
    }
    data = link->data;
    free(link);
    return data;
}

DList *create_dlist() {
    return malloc(sizeof(DList));
}
