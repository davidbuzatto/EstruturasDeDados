#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int main() {

    TabelaHash tabelaHash;

    iniciar( &tabelaHash );

    printf( "remover %d - %d\n", 11, remover( &tabelaHash, 11 ) );

    imprimir( &tabelaHash );

    inserir( &tabelaHash, 10 );
    inserir( &tabelaHash, 21 );
    inserir( &tabelaHash, 32 );
    inserir( &tabelaHash, 43 );
    inserir( &tabelaHash, 50 );
    inserir( &tabelaHash, 60 );
    inserir( &tabelaHash, 70 );
    inserir( &tabelaHash, 80 );
    inserir( &tabelaHash, 90 );
    inserir( &tabelaHash, 34 );
    inserir( &tabelaHash, 58 );
    inserir( &tabelaHash, 62 );
    inserir( &tabelaHash, 55 );
    inserir( &tabelaHash, 3465 );
    inserir( &tabelaHash, 57 );
    inserir( &tabelaHash, 4567 );
    inserir( &tabelaHash, 112 );
    inserir( &tabelaHash, 433 );
    inserir( &tabelaHash, 1238 );
    inserir( &tabelaHash, 212 );

    imprimir( &tabelaHash );

    printf( "[%s]: %d\n", buscar( &tabelaHash, 62 ) ? "Achou" : "Nao Achou", 62 );

    printf( "remover %d - %d\n", 11, remover( &tabelaHash, 11 ) );
    printf( "remover %d - %d\n", 32, remover( &tabelaHash, 32 ) );
    printf( "remover %d - %d\n", 62, remover( &tabelaHash, 62 ) );
    printf( "remover %d - %d\n", 212, remover( &tabelaHash, 212 ) );
    printf( "remover %d - %d\n", 111, remover( &tabelaHash, 111 ) );

    //inserir( &tabelaHash, 110 );
    //inserir( &tabelaHash, 120 );

    printf( "[%s]: %d\n", buscar( &tabelaHash, 62 ) ? "Achou" : "Nao Achou", 62 );
    printf( "[%s]: %d\n", buscar( &tabelaHash, 110 ) ? "Achou" : "Nao Achou", 110 );
    printf( "[%s]: %d\n", buscar( &tabelaHash, 120 ) ? "Achou" : "Nao Achou", 120 );
    printf( "[%s]: %d\n\n", buscar( &tabelaHash, 33 ) ? "Achou" : "Nao Achou", 33 );


    imprimir( &tabelaHash );


    return 0;
}
