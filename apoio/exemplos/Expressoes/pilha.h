#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct no {
    char valor;
    struct no *anterior;
} No;

typedef struct pilha {
    No *topo;
} Pilha;

void iniciar( Pilha *pilha );
bool estaVazia( Pilha *pilha );
void empilhar( Pilha *pilha, char valor );
char desempilhar( Pilha *pilha );
char consultarTopo( Pilha *pilha );
void esvaziar( Pilha *pilha );
void imprimir( Pilha *pilha );

#endif // PILHA_H
