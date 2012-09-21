#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

#define TAM_MAX_PILHA 10

typedef struct pilha {
    int valores[TAM_MAX_PILHA];
    int topo;
} Pilha;

/*
    Inicializa uma pilha.
*/
void iniciar( Pilha *pilha );

/*
    Função para verificar se apilha está vazia.
*/
bool estaVazia( Pilha *pilha );

/*
    Função para empilhar um elemento na pilha.
    Em inglês, o termo é "push"
*/
void empilhar( Pilha *pilha, int valor );

/*
    Função para desempilhar um elemento na pilha.
    Em inglês, o termo é "pop"
*/
int desempilhar( Pilha *pilha );

/*
    Função para consular o topo da pilha, sem desempilhar.
    Em inglês, o termo é "peek"
*/
int consultarTopo( Pilha *pilha );

/*
    Função para esvaziar a pilha.
*/
void esvaziar( Pilha *pilha );

/*
    Função para imprimir o conteúdo da pilha.
*/
void imprimir( Pilha *pilha );

#endif // PILHA_H
