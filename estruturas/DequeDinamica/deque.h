#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct deque {
    No *cabeca;
    No *cauda;
} Deque;

/*
    Inicializa uma deque.
*/
void iniciar( Deque *deque );

/*
    Fun��o para verificar se a deque est� vazia.
*/
bool estaVazia( Deque *deque );

/*
    Fun��o para inserir um elemento no in�cio da deque.
    � equivalente ao processo de empilhar um elemento em uma pilha.
*/
void inserirInicio( Deque *deque, int valor );

/*
    Fun��o para inserir um elemento no fim da deque.
    � equivalente ao processo de enfileirar um elemento em uma fila.
*/
void inserirFim( Deque *deque, int valor );

/*
    Fun��o para remover um elemento do in�cio da deque.
    � equivalente ao processo de desempilhar um elemeto de uma pilha ou ao
    processo de desenfileirar um elemento de uma fila.
*/
int removerInicio( Deque *deque );

/*
    Fun��o para remover um elemento do fim da deque.
*/
int removerFim( Deque *deque );

/*
    Fun��o para consultar o elemento do in�cio da deque.
    � equivalente ao processo de consultar o topo de uma pilha ou ao
    processo de consultar a cabe�a de uma fila.
*/
int consultarInicio( Deque *deque );

/*
    Fun��o para consultar o elemento do fim da deque.
*/
int consultarFim( Deque *deque );

/*
    Fun��o para esvaziar a deque.
*/
void esvaziar( Deque *deque );

/*
    Fun��o para imprimir o conte�do da deque.
*/
void imprimir( Deque *deque );

#endif // DEQUE_H
