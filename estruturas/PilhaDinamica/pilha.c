#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

/*
    Inicializa uma pilha.
*/
void iniciar( Pilha *pilha ) {
    pilha->topo = NULL;
}


/*
    Fun��o para verificar se a pilha est� vazia.
*/
bool estaVazia( Pilha *pilha ) {
    if ( pilha->topo == NULL ) {
        return true;
    } else {
        return false;
    }
}


/*
    Fun��o para empilhar um elemento na pilha.
    Em ingl�s, o termo � "push"
*/
void empilhar( Pilha *pilha, int valor ) {

    No *novoNo = ( No* ) malloc( sizeof( No ) );
    novoNo->valor = valor;

    novoNo->anterior = pilha->topo;
    pilha->topo = novoNo;

}


/*
    Fun��o para desempilhar um elemento na pilha.
    Em ingl�s, o termo � "pop"
*/
int desempilhar( Pilha *pilha ) {

    int valor = 0;
    No *temp;

    if ( estaVazia( pilha ) ) {
        printf( "Pilha vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = pilha->topo->valor;
        temp = pilha->topo;
        pilha->topo = temp->anterior; // ou pilha->topo = pilha->topo->anterior;
        free( temp );
    }

    return valor;

}


/*
    Fun��o para consular o topo da pilha, sem desempilhar.
    Em ingl�s, o termo � "peek"
*/
int consultarTopo( Pilha *pilha ) {

    int valor = 0;

    if ( estaVazia( pilha ) ) {
        printf( "Pilha vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = pilha->topo->valor;
    }

    return valor;

}


/*
    Fun��o para esvaziar a pilha.
*/
void esvaziar( Pilha *pilha ) {

    while ( !estaVazia( pilha ) ) {
        desempilhar( pilha );
    }

}


/*
    Fun��o para imprimir o conte�do da pilha.
*/
void imprimir( Pilha *pilha ) {

    No *atual = pilha->topo;

    while ( atual != NULL ) {
        printf( "%d\n", atual->valor );
        atual = atual->anterior;
    }

}
