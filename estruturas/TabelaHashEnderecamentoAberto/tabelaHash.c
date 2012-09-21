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
    Inicia uma tabela hash.
 */
void iniciar( TabelaHash *tabelaHash ) {

    int i;

    for ( i = 0; i < TAM_MAX_HASH; i++ ) {
        tabelaHash->valores[i].status = LIVRE;
        tabelaHash->valores[i].valor = 0;
    }

}

/*
    Insere um valor em uma tabela hash.
 */
void inserir( TabelaHash *tabelaHash, int valor ) {

    int posicao = hash( valor );
    int posicaoTemp = posicao;

    do {

        if ( tabelaHash->valores[posicaoTemp].status == LIVRE ){

            tabelaHash->valores[posicaoTemp].status = OCUPADO;
            tabelaHash->valores[posicaoTemp].valor = valor;

            return;

        }

        if ( posicaoTemp == TAM_MAX_HASH - 1 ){
            posicaoTemp = 0;
        } else {
            posicaoTemp++;
        }

    } while ( posicaoTemp != posicao );

    printf( "Tabela Hash cheia - Overflow!" );
    exit( 1 );

}

/*
    Busca um valor em uma tabela hash. Se não encontrar, retorna -1.
 */
int buscar( TabelaHash *tabelaHash, int valor ) {

    int posicao = hash( valor );
    int posicaoTemp = posicao;

    do {

        if ( tabelaHash->valores[posicaoTemp].status == OCUPADO &&
             tabelaHash->valores[posicaoTemp].valor == valor ) {

            return posicaoTemp;

        }

        if ( posicaoTemp == TAM_MAX_HASH - 1 ){
            posicaoTemp = 0;
        } else {
            posicaoTemp++;
        }

    } while ( tabelaHash->valores[posicaoTemp].status == OCUPADO &&
              posicaoTemp != posicao );

    return -1;

}

/*
    Remove um valor de uma tabela hash.
 */
bool remover( TabelaHash *tabelaHash, int valor ) {

    int posicao = buscar( tabelaHash, valor );

    if ( posicao != -1 ) {

        tabelaHash->valores[posicao].status = LIVRE;
        tabelaHash->valores[posicao].valor = 0;

        return true;

    } else {

        return false;

    }

}

/*
    Imprime uma tabela hash.
 */
void imprimir( TabelaHash *tabelaHash ) {

    int i;

    for ( i = 0; i < TAM_MAX_HASH; i++ ) {
        printf( "(%s-[%.2d]) => %d\n",
               tabelaHash->valores[i].status == LIVRE ? "L" : "O",
               i, tabelaHash->valores[i].valor );
    }

    printf( "\n" );

}
