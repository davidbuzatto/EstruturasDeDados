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
    Função para verificar se a fila está vazia.
*/
bool estaVazia( Fila *fila ) {
    if ( fila->cabeca == -1 ) {
        return true;
    } else {
        return false;
    }
}


/*
    Função para inserir um elemento na fila, ou seja, enfileirar
    Em inglês, o termo é "insert" ou "add" ou "offer" ou "enqueue".
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
    Função para remover um elemento da fila, ou seja, desenfileirar
    Em inglês, o termo é "remove" ou "delete" ou "remove" ou "poll" ou "dequeue".
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
    Função para consular a cabeça da fila, sem desenfileirar.
    Em inglês, o termo é "peek" ou "element"
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
    Função para esvaziar a fila.
*/
void esvaziar( Fila *fila ) {
    fila->cabeca = -1;
}


/*
    Função para imprimir o conteúdo da fila.
*/
void imprimir( Fila *fila ) {

    int i;

    for ( i = 0; i <= fila->cabeca; i++ ) {
        printf( "%d ", fila->valores[i] );
    }

    printf( "\n" );

}
