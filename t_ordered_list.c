/* 
    Integrantes do grupo: Eduardo Paino e Bernardo Kapp
*/

#include <stdio.h>
#include <stdlib.h>

#include "t_ordered_list.h"

t_ordered_list *create_list(int capacity) {

    t_ordered_list *list = malloc(sizeof(t_ordered_list));

    if(list == NULL){

        return 1;
    }

    list->items = malloc(capacity * sizeof(int));

    if(list->items == NULL){

        return 1;
    }

    list->size = 0;
    list->capacity = capacity;

    return list;
}

void destroy_list(t_ordered_list *list) {

    free(list->items);
    free(list);
}

int is_empty(t_ordered_list *list) {

    if(list->size == NULL) {

        return 1;
    }
    return 0;
}

int is_full(t_ordered_list *list) {

    if(list->size == list->capacity) {

        return 1;
    }
    return 0;
}

int list_size(t_ordered_list *list) {

    return list->size;
}

int list_capacity(t_ordered_list *list) {

    return list->capacity;
}

int list_insert(t_ordered_list *list, int value) {

    if (list->size == list->capacity) {

        return 0;
    }

    int pos = list->size;

    for(int i = 0; i < list->size; i++) {

        if(list->items[i] > value){

            pos = i;
            break;
        }
    }

    for(int j = list->size; j > pos; j--) {

        list->items[j] = list->items[j - 1];
    }

    list->items[pos] = value;
    list->size++;
}

int list_remove(t_ordered_list *list, int value) {

    for(int i = 0; i < list->size; i++) {
        
        if(list->items[i] == value){
            for(int j = i; j < list->size - 1; j++) {

                list->items[j] == list->items[j + 1];
            }
            list->size--;
            return 1;
        }
    }

    return 0;
}

void list_print(t_ordered_list *list) {

    for(int i = 0; i < list->size; i++) {

        printf("%d", list->items[i]);
    }
}