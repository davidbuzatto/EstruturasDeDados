#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

/*
    Inicializa uma fila.
*/
void iniciar( Fila *fila ) {
    fila->cabeca = -1;
}


/*
    Fun��o para verificar se a fila est� vazia.
*/
bool estaVazia( Fila *fila ) {
    if ( fila->cabeca == -1 ) {
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

    int i;

    if ( fila->cabeca < TAM_MAX_FILA - 1 ) {

        // realoca valores (faz a fila andar...)
        for ( i = fila->cabeca; i >= 0; i-- ) {
            fila->valores[i+1] = fila->valores[i];
        }

        fila->valores[0] = valor;
        fila->cabeca++;

    } else {
        printf( "Estouro da fila - Overflow!" );
        exit( 1 );
    }

}


/*
    Fun��o para remover um elemento da fila, ou seja, desenfileirar
    Em ingl�s, o termo � "remove" ou "delete" ou "remove" ou "poll" ou "dequeue".
*/
int desenfileirar( Fila *fila ) {

    int valor = 0;

    if ( estaVazia( fila ) ) {
        printf( "Fila vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = fila->valores[fila->cabeca];
        fila->cabeca--;
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
        valor = fila->valores[fila->cabeca];
    }

    return valor;

}


/*
    Fun��o para esvaziar a fila.
*/
void esvaziar( Fila *fila ) {
    fila->cabeca = -1;
}


/*
    Fun��o para imprimir o conte�do da fila.
*/
void imprimir( Fila *fila ) {

    int i;

    for ( i = 0; i <= fila->cabeca; i++ ) {
        printf( "%d ", fila->valores[i] );
    }

    printf( "\n" );

}
