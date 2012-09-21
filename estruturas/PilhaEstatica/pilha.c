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
    Função para verificar se apilha está vazia.
*/
bool estaVazia( Pilha *pilha ) {
    if ( pilha->topo == -1 ) {
        return true;
    } else {
        return false;
    }
}


/*
    Função para empilhar um elemento na pilha.
    Em inglês, o termo é "push"
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
    Função para desempilhar um elemento na pilha.
    Em inglês, o termo é "pop"
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
    Função para consular o topo da pilha, sem desempilhar.
    Em inglês, o termo é "peek"
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
    Função para esvaziar a pilha.
*/
void esvaziar( Pilha *pilha ) {
    pilha->topo = -1;
}


/*
    Função para imprimir o conteúdo da pilha.
*/
void imprimir( Pilha *pilha ) {

    int topo = pilha->topo;

    while ( topo > -1 ) {
        printf( "%d\n", pilha->valores[topo--] );
    }

}
