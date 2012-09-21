#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void iniciar( Pilha *pilha ) {
    pilha->topo = NULL;
}


bool estaVazia( Pilha *pilha ) {
    if ( pilha->topo == NULL ) {
        return true;
    } else {
        return false;
    }
}


void empilhar( Pilha *pilha, char valor ) {

    No *novoNo = ( No* ) malloc( sizeof( No ) );
    novoNo->valor = valor;

    novoNo->anterior = pilha->topo;
    pilha->topo = novoNo;

}


char desempilhar( Pilha *pilha ) {

    char valor = 0;
    No *temp;

    if ( estaVazia( pilha ) ) {
        printf( "Pilha vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = pilha->topo->valor;
        temp = pilha->topo;
        pilha->topo = temp->anterior;
        free( temp );
    }

    return valor;

}


char consultarTopo( Pilha *pilha ) {

    char valor = 0;

    if ( estaVazia( pilha ) ) {
        printf( "Pilha vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = pilha->topo->valor;
    }

    return valor;

}


void esvaziar( Pilha *pilha ) {

    while ( !estaVazia( pilha ) ) {
        desempilhar( pilha );
    }

}


void imprimir( Pilha *pilha ) {

    No *atual = pilha->topo;

    while ( atual != NULL ) {
        printf( "%c", atual->valor );
        atual = atual->anterior;
    }

    printf( "\n");

}
