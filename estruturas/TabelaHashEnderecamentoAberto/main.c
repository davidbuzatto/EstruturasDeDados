#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int main() {

    TabelaHash tabelaHash;

    iniciar( &tabelaHash );
    imprimir( &tabelaHash );

    inserir( &tabelaHash, 10 );
    inserir( &tabelaHash, 21 );
    inserir( &tabelaHash, 32 );
    inserir( &tabelaHash, 43 );
    //inserir( &tabelaHash, 50 );
    //inserir( &tabelaHash, 60 );
    //inserir( &tabelaHash, 70 );
    //inserir( &tabelaHash, 80 );
    //inserir( &tabelaHash, 90 );
    inserir( &tabelaHash, 34 );
    inserir( &tabelaHash, 58 );
    inserir( &tabelaHash, 62 );
    inserir( &tabelaHash, 57 );
    //inserir( &tabelaHash, 110 );

    imprimir( &tabelaHash );

    printf( "[%d]: %d\n", buscar( &tabelaHash, 62 ), 62 );

    printf( "remover %d - %d\n", 10, remover( &tabelaHash, 10 ) );
    printf( "remover %d - %d\n", 32, remover( &tabelaHash, 32 ) );
    inserir( &tabelaHash, 110 );
    inserir( &tabelaHash, 120 );

    printf( "[%d]: %d\n", buscar( &tabelaHash, 62 ), 62 );
    printf( "[%d]: %d\n", buscar( &tabelaHash, 110 ), 110 );
    printf( "[%d]: %d\n", buscar( &tabelaHash, 120 ), 120 );
    printf( "[%d]: %d\n\n", buscar( &tabelaHash, 32 ), 32 );

    printf( "remover %d - %d\n", 62, remover( &tabelaHash, 62 ) );
    printf( "remover %d - %d\n", 62, remover( &tabelaHash, 62 ) );
    imprimir( &tabelaHash );


    return 0;
}
