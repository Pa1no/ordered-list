/* 
    Integrantes do grupo: Eduardo Paino e Bernardo Kapp
*/

#include <stdio.h>
#include <stdlib.h>

#include "t_ordered_list.h"

int main(){

    int size, qtd_value, read_value, qtd_remove;

    printf("Qual sera o tamanho da lista?\n");
    scanf("%d", &size);

    printf("Quantos valores serao inseridos?\n");
    scanf("%d", &qtd_value);

    t_ordered_list *list = create_list(size);

    printf("Quais serao os valores que serao inseridos?\n");

    for(int i = 0; i < qtd_value; i++) {

        scanf("%d", &read_value);
        list_insert(list, read_value);
    }

    list_print(list);
    printf("\n");

    printf("Quantos valores serao inseridos?\n");
    scanf("%d", &qtd_remove);

    printf("Quais serao os valores serao removidos da lista?\n");
    
    for(int i = 0; i < qtd_remove; i++) {

        scanf("%d", &read_value);
        list_remove(list, read_value);
    }

    printf("Tamanho da lista: %d\n", list_capacity(list));
    printf("Quantidade de elementos na lista: %d\n", list_size(list));
    printf("Esta vazia? (1 - SIM / 0 - NAO): %d\n", is_empty(list));
    printf("Esta cheia? (1 - SIM / 0 - NAO): %d\n", is_full(list));

    printf("\n");

    destroy_list(list);

    return 0;
}