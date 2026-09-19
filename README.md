# Lista Ordenada em C
 
Implementação de uma lista ordenada dinâmica em C, utilizando um array como estrutura interna, com suporte a inserção ordenada, remoção, e crescimento automático de capacidade.

## Integrantes
 
- Eduardo Paino
- Bernardo Kapp

## Estrutura do projeto
 
```
.
├── teste.c              # Programa de teste
├── main.c              # Programa principal
├── t_ordered_list.c    # Implementação das funções da lista
├── t_ordered_list.h    # Definição da struct e protótipos das funções
├── Makefile
└── README.md
```
 
## Compilação
 
O projeto utiliza um Makefile para automatizar a compilação:
 
```bash
make            # compila o projeto e gera o executável
make run        # compila e executa o programa
make valgrind   # compila e executa verificando vazamentos de memória
make clean      # remove os arquivos objeto (.o)
make fclean     # remove os arquivos objeto e o executável
make re         # limpa tudo e recompila do zero
```