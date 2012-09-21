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
    Função para verificar se a deque está vazia.
*/
bool estaVazia( Deque *deque );

/*
    Função para inserir um elemento no início da deque.
    É equivalente ao processo de empilhar um elemento em uma pilha.
*/
void inserirInicio( Deque *deque, int valor );

/*
    Função para inserir um elemento no fim da deque.
    É equivalente ao processo de enfileirar um elemento em uma fila.
*/
void inserirFim( Deque *deque, int valor );

/*
    Função para remover um elemento do início da deque.
    É equivalente ao processo de desempilhar um elemeto de uma pilha ou ao
    processo de desenfileirar um elemento de uma fila.
*/
int removerInicio( Deque *deque );

/*
    Função para remover um elemento do fim da deque.
*/
int removerFim( Deque *deque );

/*
    Função para consultar o elemento do início da deque.
    É equivalente ao processo de consultar o topo de uma pilha ou ao
    processo de consultar a cabeça de uma fila.
*/
int consultarInicio( Deque *deque );

/*
    Função para consultar o elemento do fim da deque.
*/
int consultarFim( Deque *deque );

/*
    Função para esvaziar a deque.
*/
void esvaziar( Deque *deque );

/*
    Função para imprimir o conteúdo da deque.
*/
void imprimir( Deque *deque );

#endif // DEQUE_H
