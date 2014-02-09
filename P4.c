#include <stdio.h>
#include <stdlib.h>
#include "link.h"

void add(slist_t *list, int value) {
    list_item_t *item = (list_item_t *) malloc(sizeof(list_item_t));
    item->value = value;
    item->next = NULL;
    if(list->head == NULL) {
        //printf("NULL head\n");
        list->head = item;
        list->tail = item;
        item->prev = NULL;
    } else {
        //printf("Adding to %d\n", list->tail->value);
        item->prev = list->tail;
        list->tail->next = item;
        list->tail = item;
    }
}

void print(slist_t *list) {
    printf("List: ");
    list_item_t *iter = list->head;
    while(iter != NULL) {
        printf("%d ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}

void empty(slist_t *list) {
    list_item_t *prev = list->head;
    list_item_t *iter = prev;
    list->head = NULL;
    list->tail = NULL;
    while(iter != NULL) {
        iter = prev->next;
        free(prev);
        prev = iter;
    }
}

void swap(slist_t *list, list_item_t *item1, list_item_t *item2) {
    item1->next = item2->next;
    item2->next = item1;
    item2->prev = item1->prev;
    item1->prev = item2;
    if(item2->prev == NULL) {
        list->head = item2;
    } else {
        item2->prev->next = item2;
    }
    if(item1->next == NULL) {
        list->tail = item1;
    } else {
        item1->next->prev = item1;
    }
}

void bublesort(slist_t *list) {
    list_item_t *iter1 = list->head;
    list_item_t *iter2 = iter1;
    int isSorted = 0;
    while(isSorted == 0) {

    }
}

int main() {
    slist_t myList;
    print(&myList);
    add(&myList, 4);
    add(&myList, 2);
    add(&myList, 3);
    add(&myList, 1);
    print(&myList);
    swap(&myList, myList.head->next, myList.head->next->next);
    print(&myList);
    return 0;
}