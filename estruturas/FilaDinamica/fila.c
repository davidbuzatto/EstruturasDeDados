#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

/*
    Inicializa uma fila.
*/
void iniciar( Fila *fila ) {
    fila->cabeca = NULL;
    fila->cauda = NULL;
}


/*
    Fun��o para verificar se a fila est� vazia.
*/
bool estaVazia( Fila *fila ) {
    if ( fila->cabeca == NULL ) {
        return true;
    } else {
        return false;
    }
}


/*
    Fun��o para inserir um elemento na fila, ou seja, enfileirar
    Em ingl�s, o termo � "insert" ou "add" ou "offer" ou "enqueue".
*/
void enfileirar( Fila *fila, int valor ) {

    No *novoNo = ( No* ) malloc( sizeof( No ) );
    novoNo->valor = valor;

    if ( estaVazia( fila ) ) {
        novoNo->proximo = NULL;
        fila->cabeca = novoNo;
        fila->cauda = novoNo;
    } else {
        novoNo->proximo = fila->cauda;
        fila->cauda = novoNo;
    }

}


/*
    Fun��o para remover um elemento da fila, ou seja, desenfileirar
    Em ingl�s, o termo � "remove" ou "delete" ou "remove" ou "poll" ou "dequeue".
*/
int desenfileirar( Fila *fila ) {

    int valor = 0;
    No *temp;

    if ( estaVazia( fila ) ) {
        printf( "Fila vazia - Underflow!" );
        exit( 1 );
    } else if ( fila->cauda == fila->cabeca ) {

        valor = fila->cabeca->valor;

        free( fila->cabeca );
        fila->cabeca = NULL;
        fila->cauda = NULL;

    } else {

        valor = fila->cabeca->valor;
        temp = fila->cauda;

        while ( temp->proximo != fila->cabeca ) {
            temp = temp->proximo;
        }

        fila->cabeca = temp;
        free( temp->proximo );

        fila->cabeca->proximo = NULL;

    }

    return valor;

}


/*
    Fun��o para consular a cabe�a da fila, sem desenfileirar.
    Em ingl�s, o termo � "peek" ou "element"
*/
int consultarCabeca( Fila *fila ) {

    int valor = 0;

    if ( estaVazia( fila ) ) {
        printf( "Fila vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = fila->cabeca->valor;
    }

    return valor;

}


/*
    Fun��o para esvaziar a fila.
*/
void esvaziar( Fila *fila ) {

    while ( !estaVazia( fila ) ) {
        desenfileirar( fila );
    }

}


/*
    Fun��o para imprimir o conte�do da fila.
*/
void imprimir( Fila *fila ) {

    No *temp = fila->cauda;

    while ( temp != NULL ) {
        printf( "%d ", temp->valor );
        temp = temp->proximo;
    }

    printf( "\n" );

}
