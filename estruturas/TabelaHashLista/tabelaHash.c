#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tabelaHash.h"

/*
    Função de dispersão.
 */
int hash( int valor ) {
    return valor % TAM_MAX_HASH;
}

/*
    Função para criar um novo nó.
 */
No* novoNo( int valor ) {

    No *novoNo = ( No * ) malloc( sizeof( No ) );

    novoNo->valor = valor;
    novoNo->proximo = NULL;

    return novoNo;

}

/*
    Inicia uma tabela hash.
 */
void iniciar( TabelaHash *tabelaHash ) {

    int i;

    for ( i = 0; i < TAM_MAX_HASH; i++ ) {
        tabelaHash->valores[i] = NULL;
    }

}

/*
    Insere um valor em uma tabela hash.
 */
void inserir( TabelaHash *tabelaHash, int valor ) {

    int posicao = hash( valor );

    if ( tabelaHash->valores[posicao] == NULL ){

        tabelaHash->valores[posicao] = novoNo( valor );

    } else {

        No *temp = tabelaHash->valores[posicao];

        while ( temp->proximo != NULL ) {
            temp = temp->proximo;
        }

        temp->proximo = novoNo( valor );

    }

}

/*
    Busca um valor em uma tabela hash.
 */
bool buscar( TabelaHash *tabelaHash, int valor ) {

    int posicao = hash( valor );
    No *temp = tabelaHash->valores[posicao];

    while ( temp != NULL ) {

        if ( temp->valor == valor ) {
            return true;
        }

        temp = temp->proximo;

    }

    return false;

}

/*
    Remove um valor de uma tabela hash.
 */
bool remover( TabelaHash *tabelaHash, int valor ) {

    int posicao = hash( valor );
    No *temp = tabelaHash->valores[posicao];

    if ( temp == NULL ) {
        return false;
    } else {

        if ( temp->valor == valor ) {

            tabelaHash->valores[posicao] = temp->proximo;
            free( temp );
            return true;

        } else {

            while ( temp->proximo != NULL ) {

                if ( temp->proximo->valor == valor ) {

                    No *tempExclusao = temp->proximo;
                    temp->proximo = temp->proximo->proximo;
                    free( tempExclusao );

                    return true;

                }

                temp = temp->proximo;

            }

        }

    }

    return false;

}

/*
    Imprime uma tabela hash.
 */
void imprimir( TabelaHash *tabelaHash ) {

    int i;

    for ( i = 0; i < TAM_MAX_HASH; i++ ) {

        if ( tabelaHash->valores[i] == NULL ) {
            printf( "(L-[%.2d])\n", i );
        } else {

            printf( "(O-[%.2d]) => %d",
                   i, tabelaHash->valores[i]->valor );

            No *temp = tabelaHash->valores[i]->proximo;

            while ( temp != NULL ) {
                printf( ", %d", temp->valor );
                temp = temp->proximo;
            }

            printf( "\n" );

        }

    }

    printf( "\n" );

}
