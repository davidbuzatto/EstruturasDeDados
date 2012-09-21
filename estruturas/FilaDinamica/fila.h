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
    Função para verificar se a fila está vazia.
*/
bool estaVazia( Fila *fila );

/*
    Função para inserir um elemento na fila, ou seja, enfileirar
    Em inglês, o termo é "insert" ou "add" ou "offer" ou "enqueue".
*/
void enfileirar( Fila *fila, int valor );

/*
    Função para remover um elemento da fila, ou seja, desenfileirar
    Em inglês, o termo é "remove" ou "delete" ou "remove" ou "poll" ou "dequeue".
*/
int desenfileirar( Fila *fila );

/*
    Função para consular a cabeça da fila, sem desenfileirar.
    Em inglês, o termo é "peek" ou "element"
*/
int consultarCabeca( Fila *fila );

/*
    Função para esvaziar a fila.
*/
void esvaziar( Fila *fila );

/*
    Função para imprimir o conteúdo da fila.
*/
void imprimir( Fila *fila );

#endif // FILA_H
