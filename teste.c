#include <stdio.h>
#include "t_ordered_list.h"

int main() {

    printf("Teste 1: Criando lista com capacidade para 5 espacos\n");
    t_ordered_list *list = create_list(5);
    printf("Lista vazia? %d (1 - SIM / 0 - NAO)\n", is_empty(list));
    printf("Lista cheia? %d (1 - SIM / 0 - NAO)\n", is_full(list));
    printf("Tamanho: %d (esperado: 0)\n\n", list_size(list));

    printf("Teste 2: Inserindo valores fora de ordem\n");
    list_insert(list, 30);
    list_insert(list, 10);
    list_insert(list, 20);
    printf("Lista apos insercoes: ");
    list_print(list);
    printf("\n(esperado: 10 20 30)\n");
    printf("Tamanho: %d (esperado: 3)\n\n", list_size(list));

    printf("Teste 3: Removendo um valor existente\n");
    int removido = list_remove(list, 20);
    printf("Removeu 20? %d (esperado: 1)\n", removido);
    printf("Lista apos remocao: ");
    list_print(list);
    printf("\n(esperado: 10 30)\n\n");

    printf("Teste 4: Removendo um valor inexistente\n");
    int removido2 = list_remove(list, 999);
    printf("Removeu 999? %d (esperado: 0)\n\n", removido2);

    printf("Teste 5: Enchendo a lista (capacidade para 5 espacos)\n");
    list_insert(list, 5);
    list_insert(list, 40);
    list_insert(list, 50);
    printf("Lista cheia? %d (esperado: 1)\n", is_full(list));
    printf("Lista atual: ");
    list_print(list);
    printf("\n\n");

    printf("Teste 6: Tentando inserir em lista cheia\n");
    int inserido = list_insert(list, 100);
    printf("Inseriu 100? %d (esperado: 0, lista ja esta cheia)\n\n", inserido);

    printf("Teste 7: Destruindo a lista\n");
    destroy_list(list);
    printf("Lista destruida (verificar com Valgrind se teve vazamento de memoria)\n");

    return 0;
}