#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

/*
    Inicializa uma pilha.
*/
void iniciar( Pilha *pilha ) {
    pilha->topo = -1;
}


/*
    Fun��o para verificar se apilha est� vazia.
*/
bool estaVazia( Pilha *pilha ) {
    if ( pilha->topo == -1 ) {
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

    if ( pilha->topo < TAM_MAX_PILHA - 1 ) {
        pilha->topo++;
        pilha->valores[pilha->topo] = valor;
    } else {
        printf( "Estouro da pilha - Overflow!" );
        exit( 1 );
    }

}


/*
    Fun��o para desempilhar um elemento na pilha.
    Em ingl�s, o termo � "pop"
*/
int desempilhar( Pilha *pilha ) {

    int valor = 0;

    if ( estaVazia( pilha ) ) {
        printf( "Pilha vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = pilha->valores[pilha->topo];
        pilha->topo--;
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
        valor = pilha->valores[pilha->topo];
    }

    return valor;

}


/*
    Fun��o para esvaziar a pilha.
*/
void esvaziar( Pilha *pilha ) {
    pilha->topo = -1;
}


/*
    Fun��o para imprimir o conte�do da pilha.
*/
void imprimir( Pilha *pilha ) {

    int topo = pilha->topo;

    while ( topo > -1 ) {
        printf( "%d\n", pilha->valores[topo--] );
    }

}
