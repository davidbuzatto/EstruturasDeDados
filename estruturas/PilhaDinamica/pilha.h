#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *anterior;
} No;

typedef struct pilha {
    No *topo;
} Pilha;

/*
    Inicializa uma pilha.
*/
void iniciar( Pilha *pilha );

/*
    Fun��o para verificar se a pilha est� vazia.
*/
bool estaVazia( Pilha *pilha );

/*
    Fun��o para empilhar um elemento na pilha.
    Em ingl�s, o termo � "push"
*/
void empilhar( Pilha *pilha, int valor );

/*
    Fun��o para desempilhar um elemento na pilha.
    Em ingl�s, o termo � "pop"
*/
int desempilhar( Pilha *pilha );

/*
    Fun��o para consular o topo da pilha, sem desempilhar.
    Em ingl�s, o termo � "peek"
*/
int consultarTopo( Pilha *pilha );

/*
    Fun��o para esvaziar a pilha.
*/
void esvaziar( Pilha *pilha );

/*
    Fun��o para imprimir o conte�do da pilha.
*/
void imprimir( Pilha *pilha );

#endif // PILHA_H
