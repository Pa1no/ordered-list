#ifndef T_ORDERED_LIST_H
#define T_ORDERED_LIST_H

typedef struct {

    int *items;
    int size;
    int capacity;
} t_ordered_list;

t_ordered_list *create_list(int capacity);
void destroy_list(t_ordered_list *list);
int is_empty(t_ordered_list *list);
int is_full(t_ordered_list *list);
int list_size(t_ordered_list *list);
int list_capacity(t_ordered_list *list);
int list_insert(t_ordered_list *list, int value);
int list_remove(t_ordered_list *list, int value);
void list_print(t_ordered_list *list);

#endif