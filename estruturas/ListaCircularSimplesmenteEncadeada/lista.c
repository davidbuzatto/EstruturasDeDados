#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista.h"

void iniciar( Lista *lista ) {
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->tamanho = 0;
}


bool estaVazia( Lista *lista ) {
    if ( lista->cauda == NULL ) {
        return true;
    } else {
        return false;
    }
}


int tamanho( Lista *lista ) {
    return lista->tamanho;
}


/*
 * Funções para inserir elementos na lista.
 * Normalmente chamadas de "add" em inglês.
 */
void inserirInicio( Lista *lista, int valor ) {

    No *novoNo = ( No* ) malloc( sizeof( No ) );
    novoNo->valor = valor;

    if ( estaVazia( lista ) ) {
        novoNo->proximo = novoNo;
        lista->cauda = novoNo;
        lista->cabeca = novoNo;
    } else {
        novoNo->proximo = lista->cabeca;
        lista->cabeca = novoNo;
        lista->cauda->proximo = lista->cabeca;
    }

    lista->tamanho++;

}


void inserirFim( Lista *lista, int valor) {

    No *novoNo = ( No* ) malloc( sizeof( No ) );
    novoNo->valor = valor;

    if ( estaVazia( lista ) ) {
        novoNo->proximo = novoNo;
        lista->cauda = novoNo;
        lista->cabeca = novoNo;
    } else {
        lista->cauda->proximo = novoNo;
        lista->cauda = novoNo;
        lista->cauda->proximo = lista->cabeca;
    }

    lista->tamanho++;

}


void inserir( Lista *lista, int valor, int posicao ) {

    int i;
    No *temp;

    if ( estaVazia( lista ) ) {
        inserirFim( lista, valor );
        // ou inserir no fim, tanto faz
    } else {

        if ( posicao <= 0 ) {
            inserirInicio( lista, valor );
        } else if ( posicao >= tamanho( lista ) ) {
            inserirFim( lista, valor );
        } else {

            No *novoNo = ( No* ) malloc( sizeof( No ) );
            novoNo->valor = valor;

            temp = lista->cabeca;

            for ( i = 0; i < posicao - 1; i++ ) {
                temp = temp->proximo;
            }

            novoNo->proximo = temp->proximo;
            temp->proximo = novoNo;

            lista->tamanho++;

        }

    }

}


/*
 * Funções para alterar elementos da lista.
 * Normalmente chamadas de "set" em inglês.
 */
void alterarInicio( Lista *lista, int valor ) {

    if ( estaVazia( lista ) ) {
        printf( "Lista vazia!" );
    } else {
        lista->cabeca->valor = valor;
    }

}


void alterarFim( Lista *lista, int valor ) {

    if ( estaVazia( lista ) ) {
        printf( "Lista vazia!" );
    } else {
        lista->cauda->valor = valor;
    }

}


void alterar( Lista *lista, int valor, int posicao ) {

    int i;
    No *temp;

    if ( estaVazia( lista ) ) {
        printf( "Lista vazia!" );
    } else {

        if ( posicao <= 0 ) {
            alterarInicio( lista, valor );
        } else if ( posicao >= tamanho( lista ) - 1 ) {
            alterarFim( lista, valor );
        } else {

            temp = lista->cabeca;

            for ( i = 0; i < posicao; i++ ) {
                temp = temp->proximo;
            }

            temp->valor = valor;

        }

    }

}


/*
 * Funções para remover elementos da lista.
 * Normalmente chamadas de "remove" ou "delete" em inglês.
 */
int removerInicio( Lista *lista ) {

    int valor = 0;
    No *temp;

    if ( estaVazia( lista ) ) {
        printf( "Lista vazia - Underflow!" );
        exit( 1 );
    } else if ( lista->cabeca == lista->cauda ) {

        valor = lista->cabeca->valor;

        free( lista->cabeca );
        lista->cauda = NULL;
        lista->cabeca = NULL;

        lista->tamanho--;

    } else {

        valor = lista->cabeca->valor;
        temp = lista->cabeca;

        lista->cabeca = lista->cabeca->proximo;
        lista->cauda->proximo = lista->cabeca;

        free( temp );

        lista->tamanho--;

    }

    return valor;

}


int removerFim( Lista *lista ) {

    int valor = 0;
    No *temp;

    if ( estaVazia( lista ) ) {
        printf( "Lista vazia - Underflow!" );
        exit( 1 );
    } else if ( lista->cabeca == lista->cauda ) {

        valor = lista->cauda->valor;

        free( lista->cauda );
        lista->cauda = NULL;
        lista->cabeca = NULL;

        lista->tamanho--;

    } else {

        valor = lista->cauda->valor;
        temp = lista->cabeca;

        while ( temp->proximo != lista->cauda ) {
            temp = temp->proximo;
        }

        lista->cauda = temp;
        free( temp->proximo );

        lista->cauda->proximo = lista->cabeca;

        lista->tamanho--;

    }

    return valor;

}


int remover( Lista *lista, int posicao ) {

    int i;
    int valor = 0;
    No *temp;
    No *tempExc;

    if ( estaVazia( lista ) ) {
        printf( "Lista vazia - Underflow!" );
        exit( 1 );
    } else {

        if ( posicao <= 0 ) {
            valor = removerInicio( lista );
        } else if ( posicao >= tamanho( lista ) - 1 ) {
            valor = removerFim( lista );
        } else {

            temp = lista->cabeca;

            for ( i = 0; i < posicao - 1; i++ ) {
                temp = temp->proximo;
            }

            valor = temp->proximo->valor;

            tempExc = temp->proximo;
            temp->proximo = tempExc->proximo;

            free( tempExc );

            lista->tamanho--;

        }

    }

    return valor;

}


/*
 * Funções para consultar elementos da lista, sem removê-los.
 * Normalmente chamadas de "get" em inglês.
 */
int consultarInicio( Lista *lista ) {

    int valor = 0;

    if ( estaVazia( lista ) ) {
        printf( "Lista vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = lista->cabeca->valor;
    }

    return valor;

}


int consultarFim( Lista *lista ) {

    int valor = 0;

    if ( estaVazia( lista ) ) {
        printf( "Lista vazia - Underflow!" );
        exit( 1 );
    } else {
        valor = lista->cauda->valor;
    }

    return valor;

}


int consultar( Lista *lista, int posicao ) {

    int i;
    int valor = 0;
    No *temp;

    if ( estaVazia( lista ) ) {
        printf( "Lista vazia - Underflow!" );
        exit( 1 );
    } else {

        if ( posicao <= 0 ) {
            valor = consultarInicio( lista );
        } else if ( posicao >= tamanho( lista ) - 1 ) {
            valor = consultarFim( lista );
        } else {

            temp = lista->cabeca;

            for ( i = 0; i < posicao; i++ ) {
                temp = temp->proximo;
            }

            valor = temp->valor;

        }

    }

    return valor;

}


void esvaziar( Lista *lista ) {

    while ( !estaVazia( lista ) ) {
        removerInicio( lista );
    }

}


void imprimir( Lista *lista ) {

    No *temp = lista->cabeca;

    if ( !estaVazia( lista ) ) {
        do {
            printf( "%d ", temp->valor );
            temp = temp->proximo;
        } while ( temp != lista->cabeca );
    }

    printf( "\n" );

}
