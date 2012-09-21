#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct fila {
    No *cabeca;
    No *cauda;
} Fila;

/*
    Inicializa uma fila.
*/
void iniciar( Fila *fila );

/*
    Fun��o para verificar se a fila est� vazia.
*/
bool estaVazia( Fila *fila );

/*
    Fun��o para inserir um elemento na fila, ou seja, enfileirar
    Em ingl�s, o termo � "insert" ou "add" ou "offer" ou "enqueue".
*/
void enfileirar( Fila *fila, int valor );

/*
    Fun��o para remover um elemento da fila, ou seja, desenfileirar
    Em ingl�s, o termo � "remove" ou "delete" ou "remove" ou "poll" ou "dequeue".
*/
int desenfileirar( Fila *fila );

/*
    Fun��o para consular a cabe�a da fila, sem desenfileirar.
    Em ingl�s, o termo � "peek" ou "element"
*/
int consultarCabeca( Fila *fila );

/*
    Fun��o para esvaziar a fila.
*/
void esvaziar( Fila *fila );

/*
    Fun��o para imprimir o conte�do da fila.
*/
void imprimir( Fila *fila );

#endif // FILA_H
