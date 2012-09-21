#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "tabelaHash.h"

/*
    Função de dispersão.
 */
int hash( char *chave ) {
    return ( toupper( chave[0] ) - 65 ) % TAM_MAX_HASH;
}

/*
    Função para criar um novo nó.
 */
No* novoNo( char *chave, int valor ) {

    No *novoNo = ( No * ) malloc( sizeof( No ) );

    strcpy( novoNo->chave, chave );
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
void inserir( TabelaHash *tabelaHash, char* chave, int valor ) {

    int posicao = hash( chave );
    bool criarNovo = true;

    if ( tabelaHash->valores[posicao] == NULL ){

        tabelaHash->valores[posicao] = novoNo( chave, valor );

    } else {

        No *temp = tabelaHash->valores[posicao];
        No *anterior;

        while ( temp != NULL ) {

            if ( strcmp( temp->chave, chave ) == 0 ) {
                temp->valor = valor;
                criarNovo = false;
                break;
            }

            anterior = temp;
            temp = temp->proximo;

        }

        if ( criarNovo ) {
            anterior->proximo = novoNo( chave, valor );
        }

    }

}

/*
    Busca um valor em uma tabela hash.
    Retorna NULL caso não encontre ou o nó com o valor caso encontre.
 */
No *buscar( TabelaHash *tabelaHash, char* chave ) {

    int posicao = hash( chave );
    No *temp = tabelaHash->valores[posicao];

    while ( temp != NULL ) {

        if ( strcmp( temp->chave, chave ) == 0 ) {
            return temp;
        }

        temp = temp->proximo;

    }

    return NULL;

}

/*
    Remove um valor de uma tabela hash.
 */
bool remover( TabelaHash *tabelaHash, char* chave ) {

    int posicao = hash( chave );
    No *temp = tabelaHash->valores[posicao];

    if ( temp == NULL ) {
        return false;
    } else {

        if ( strcmp( temp->chave, chave ) == 0 ) {

            tabelaHash->valores[posicao] = temp->proximo;
            free( temp );
            return true;

        } else {

            while ( temp->proximo != NULL ) {

                if ( strcmp( temp->proximo->chave, chave ) == 0 ) {

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

            printf( "(O-[%.2d]) => { \"%s\": %d }",
                   i, tabelaHash->valores[i]->chave, tabelaHash->valores[i]->valor );

            No *temp = tabelaHash->valores[i]->proximo;

            while ( temp != NULL ) {
                printf( ", { \"%s\": %d }", temp->chave, temp->valor );
                temp = temp->proximo;
            }

            printf( "\n" );

        }

    }

    printf( "\n" );

}
