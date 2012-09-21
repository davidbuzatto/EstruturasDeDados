#include <stdlib.h>
#include <stdio.h>
#include "deque.h"


/*
    Inicializa uma deque.
*/
void iniciar( Deque *deque ) {
    deque->cabeca = -1;
}


/*
    Fun��o para verificar se a deque est� vazia.
*/
bool estaVazia( Deque *deque ) {
    if ( deque->cabeca == -1 ) {
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

    if ( estaVazia( deque ) ) {

        deque->cabeca++;
        deque->valores[deque->cabeca] = valor;

    } else {

        if ( deque->cabeca < TAM_MAX_DEQUE - 1 ) {

            deque->cabeca++;
            deque->valores[deque->cabeca] = valor;

        } else {

            printf( "Estouro da deque - Overflow!" );
            exit( 1 );

        }

    }


}


/*
    Fun��o para inserir um elemento no fim da deque.
    � equivalente ao processo de enfileirar um elemento em uma fila.
*/
void inserirFim( Deque *deque, int valor ) {

    int i;

    if ( estaVazia( deque ) ) {

        deque->cabeca++;
        deque->valores[0] = valor;

    } else {

        if ( deque->cabeca < TAM_MAX_DEQUE - 1 ) {

            for ( i = deque->cabeca; i >= 0; i-- ) {
                deque->valores[i+1] = deque->valores[i];
            }

            deque->valores[0] = valor;
            deque->cabeca++;

        } else {

            printf( "Estouro da deque - Overflow!" );
            exit( 1 );

        }

    }

}


/*
    Fun��o para remover um elemento do in�cio da deque.
    � equivalente ao processo de desempilhar um elemeto de uma pilha ou ao
    processo de desenfileirar um elemento de uma fila.
*/
int removerInicio( Deque *deque ) {

    int valor = 0;

    if ( estaVazia( deque ) ) {
        printf( "Deque vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = deque->valores[deque->cabeca];
        deque->cabeca--;
    }

    return valor;

}


/*
    Fun��o para remover um elemento do fim da deque.
*/
int removerFim( Deque *deque ) {

    int i;
    int valor = 0;

    if ( estaVazia( deque ) ) {
        printf( "Deque vazia - Underflow!" );
        exit( 1 );
    } else {

        valor = deque->valores[0];

        for ( i = 1; i <= deque->cabeca; i++ ) {
            deque->valores[i-1] = deque->valores[i];
        }

        deque->cabeca--;

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
        valor = deque->valores[deque->cabeca];
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
        valor = deque->valores[0];
    }

    return valor;

}


/*
    Fun��o para esvaziar a deque.
*/
void esvaziar( Deque *deque ) {
    deque->cabeca = -1;
}


/*
    Fun��o para imprimir o conte�do da deque.
*/
void imprimir( Deque *deque ) {

    int i;

    for ( i = 0; i <= deque->cabeca; i++ ) {
        printf( "%d ", deque->valores[i] );
    }

    printf( "\n" );

}
