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
    Função para verificar se a pilha está vazia.
*/
bool estaVazia( Pilha *pilha ) {
    if ( pilha->topo == NULL ) {
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

    No *novoNo = ( No* ) malloc( sizeof( No ) );
    novoNo->valor = valor;

    novoNo->anterior = pilha->topo;
    pilha->topo = novoNo;

}


/*
    Função para desempilhar um elemento na pilha.
    Em inglês, o termo é "pop"
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
    Função para consular o topo da pilha, sem desempilhar.
    Em inglês, o termo é "peek"
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
    Função para esvaziar a pilha.
*/
void esvaziar( Pilha *pilha ) {

    while ( !estaVazia( pilha ) ) {
        desempilhar( pilha );
    }

}


/*
    Função para imprimir o conteúdo da pilha.
*/
void imprimir( Pilha *pilha ) {

    No *atual = pilha->topo;

    while ( atual != NULL ) {
        printf( "%d\n", atual->valor );
        atual = atual->anterior;
    }

}
