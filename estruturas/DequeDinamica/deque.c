#include <stdlib.h>
#include <stdio.h>
#include "deque.h"


/*
    Inicializa uma deque.
*/
void iniciar( Deque *deque ) {
    deque->cabeca = NULL;
    deque->cauda = NULL;
}


/*
    Fun��o para verificar se a deque est� vazia.
*/
bool estaVazia( Deque *deque ) {
    if ( deque->cabeca == NULL ) {
        return true;
    } else {
        return false;
    }
}


/*
    Fun��o para inserir um elemento no in�cio da deque.
    � equivalente ao processo de empilhar um elemento em uma pilha.
*/
void inserirInicio( Deque *deque, int valor ) {

    No *novoNo = ( No* ) malloc( sizeof( No ) );
    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if ( estaVazia( deque ) ) {
        deque->cabeca = novoNo;
        deque->cauda = novoNo;
    } else {
        deque->cabeca->proximo = novoNo;
        deque->cabeca = novoNo;
    }

}


/*
    Fun��o para inserir um elemento no fim da deque.
    � equivalente ao processo de enfileirar um elemento em uma fila.
*/
void inserirFim( Deque *deque, int valor ) {

    No *novoNo = ( No* ) malloc( sizeof( No ) );
    novoNo->valor = valor;

    if ( estaVazia( deque ) ) {
        novoNo->proximo = NULL;
        deque->cabeca = novoNo;
        deque->cauda = novoNo;
    } else {
        novoNo->proximo = deque->cauda;
        deque->cauda = novoNo;
    }

}


/*
    Fun��o para remover um elemento do in�cio da deque.
    � equivalente ao processo de desempilhar um elemeto de uma pilha ou ao
    processo de desenfileirar um elemento de uma fila.
*/
int removerInicio( Deque *deque ) {

    int valor = 0;
    No *temp;

    if ( estaVazia( deque ) ) {
        printf( "Deque vazia - Underflow!" );
        exit( 1 );
    } else if ( deque->cauda == deque->cabeca ) {

        valor = deque->cabeca->valor;

        free( deque->cabeca );
        deque->cabeca = NULL;
        deque->cauda = NULL;

    } else {

        valor = deque->cabeca->valor;
        temp = deque->cauda;

        while ( temp->proximo != deque->cabeca ) {
            temp = temp->proximo;
        }

        deque->cabeca = temp;
        free( temp->proximo );

        deque->cabeca->proximo = NULL;

    }

    return valor;

}


/*
    Fun��o para remover um elemento do fim da deque.
*/
int removerFim( Deque *deque ) {

    int valor = 0;
    No *temp;

    if ( estaVazia( deque ) ) {
        printf( "Deque vazia - Underflow!" );
        exit( 1 );
    } else if ( deque->cauda == deque->cabeca ) {

        valor = deque->cauda->valor;

        free( deque->cauda );
        deque->cabeca = NULL;
        deque->cauda = NULL;

    } else {

        valor = deque->cauda->valor;
        temp = deque->cauda;

        deque->cauda = deque->cauda->proximo;

        free( temp );

    }

    return valor;

}


/*
    Fun��o para consultar o elemento do in�cio da deque.
    � equivalente ao processo de consultar o topo de uma pilha ou ao
    processo de consultar a cabe�a de uma fila.
*/
int consultarInicio( Deque *deque ) {

    int valor = 0;

    if ( estaVazia( deque ) ) {
        printf( "Deque vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = deque->cabeca->valor;
    }

    return valor;

}


/*
    Fun��o para consultar o elemento do fim da deque.
*/
int consultarFim( Deque *deque ) {

    int valor = 0;

    if ( estaVazia( deque ) ) {
        printf( "Deque vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = deque->cauda->valor;
    }

    return valor;

}


/*
    Fun��o para esvaziar a deque.
*/
void esvaziar( Deque *deque ) {

    while ( !estaVazia( deque ) ) {
        removerFim( deque );
    }

}


/*
    Fun��o para imprimir o conte�do da deque.
*/
void imprimir( Deque *deque ) {

    No *temp = deque->cauda;

    while ( temp != NULL ) {
        printf( "%d ", temp->valor );
        temp = temp->proximo;
    }

    printf( "\n" );

}
