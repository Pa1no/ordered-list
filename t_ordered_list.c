/* 
    Integrantes do grupo: Eduardo Paino e Bernardo Kapp
*/

/*
    Pontos fortes:
        - Busca eficiente: como os elementos estão sempre em ordem, é possível usar busca binária para encontrar um elemento, 
        em vez de percorrer o array inteiro elemento por elemento. Isso é uma vantagem em relação a uma lista não ordenada, 
        que exigiria busca linear (O(n)) sempre.
        - Acesso direto pelo índice (O(1)): por ser implementada como um array, qualquer elemento pode ser acessado diretamente por items[i], 
        sem precisar percorrer a estrutura
        - Facilidade de percorrer em ordem: como os dados já estão ordenados, operações como imprimir a lista, encontrar mínimo/máximo (primeiro e último elemento), 
        ou percorrer em ordem crescente/decrescente são triviais e rápidas.
    Pontos fracos:
        - Inserção com alto custo (O(n)): como vimos na função list_insert, ao inserir um novo elemento no meio da lista, 
        é necessário deslocar todos os elementos seguintes uma posição para frente, para manter a ordem e abrir espaço.
        - Remoção custosa (O(n)): pelo mesmo motivo, remover um elemento do meio (como em list_remove) exige deslocar todos os elementos seguintes uma posição para trás, 
        para fechar o buraco.
        - Desperdício de memória: se o capacity for muito maior que o size real usado na maior parte do tempo, a memória fica alocada sem uso nenhum.
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

        int new_capacity = (list->capacity == 0) ? 1 : list->capacity * 2;
        int *new_items = realloc(list->items, new_capacity * sizeof(int));

        if (new_items == NULL) {
            return 0;
        }

        list->items = new_items;
        list->capacity = new_capacity;
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