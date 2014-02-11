#include <stdio.h>
#include <stdlib.h>
#include "link.h"

// Initializes the linked head and tail.
void init(slist_t *list) {
    list->head = NULL;
    list->tail = NULL;
}

// Adds a new element with the supplied value to the end of
// the linked list supplied by the pointer.
void add(slist_t *list, int value) {
    // Allocate memory and initialize the list item.
    list_item_t *item = (list_item_t *) malloc(sizeof(list_item_t));
    item->value = value;
    item->next = NULL;
    // If the list is empty, make the new item the head and tail.
    if(list->head == NULL) {
        //printf("NULL head\n");
        list->head = item;
        list->tail = item;
        item->prev = NULL;
    } else {
        // Otherwise, make the element the new tail and
        // rearrange the pointers appropriately.
        //printf("Adding to %d\n", list->tail->value);
        item->prev = list->tail;
        list->tail->next = item;
        list->tail = item;
    }
}

// Prints the supplied linked list from head to tail.
void print(slist_t *list) {
    printf("List: ");
    list_item_t *iter = list->head;
    while(iter != NULL) {
        printf("%d ", iter->value);
        iter = iter->next;
    }
    printf("\n");
}

// Removes the elements of the supplied list.  Frees the memory
// used by these items as well.
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

// Handles rearranging pointers to properly swap two elements.
// item1 must occur directly before item2 in the list.
void swap(slist_t *list, list_item_t *item1, list_item_t *item2) {
    // First move the pointers rooted at the two elements.
    item1->next = item2->next;
    item2->next = item1;
    item2->prev = item1->prev;
    item1->prev = item2;
    // If the now-first element has no predecessor, then it must
    // be the head element.  Otherwise, change its predecessor's
    // next field to now point to the right element.
    if(item2->prev == NULL) {
        list->head = item2;
    } else {
        item2->prev->next = item2;
    }
    // If the now-second element has no next, then it must be the
    // tail element. Otherwise, carrect the next element's prev field.
    if(item1->next == NULL) {
        list->tail = item1;
    } else {
        item1->next->prev = item1;
    }
}

// Sorts the supplied list using the bubble sort algorithm.
void bublesort(slist_t *list) {
    list_item_t *iter1;
    list_item_t *iter2;
    int isSorted = 0;
    while(isSorted == 0) {
        isSorted = 1;
        iter1 = list->head;
        iter2 = iter1->next;
        while(iter2 != NULL) {
            if(iter1->value > iter2->value) {
                isSorted = 0;
                swap(list, iter1, iter2);
                // iter1 is now the latter element, iter2 the earlier.
                // So they must be advanced accordingly.
                iter2 = iter1->next;
            } else {
                iter1 = iter2;
                iter2 = iter2->next;
            }
        }
    }
}

int main() {
    /*
    // Tests for the linked list implementation.
    slist_t myList;
    init(&myList);
    print(&myList);
    add(&myList, 5);
    add(&myList, 4);
    add(&myList, 3);
    add(&myList, 2);
    add(&myList, 1);
    print(&myList);
    bublesort(&myList);
    print(&myList);
    */
    return 0;
}
