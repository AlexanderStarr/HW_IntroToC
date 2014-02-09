typedef struct list_item {
	int value;
	struct list_item *next;
	struct list_item *prev;
} list_item_t; 

/**
global variable declaration
**/
typedef struct single_list {
	list_item_t *head;
	list_item_t *tail;
} slist_t;

void add(slist_t *list, int value);
void print(slist_t *list);
void empty(slist_t *list);
void bublesort(slist_t *list);