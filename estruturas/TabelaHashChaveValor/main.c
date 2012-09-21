#include <stdio.h>
#include <stdlib.h>
#include "tabelaHash.h"

int main() {

    TabelaHash tabelaHash;

    iniciar( &tabelaHash );

    printf( "remover a - %d\n", remover( &tabelaHash, "a" ) );

    imprimir( &tabelaHash );

    inserir( &tabelaHash, "a", 10 );
    inserir( &tabelaHash, "aa", 20 );
    inserir( &tabelaHash, "ab", 20 );
    inserir( &tabelaHash, "Aa", 30 );
    inserir( &tabelaHash, "b", 21 );
    inserir( &tabelaHash, "ba", 32 );
    inserir( &tabelaHash, "c", 43 );
    inserir( &tabelaHash, "k", 50 );
    inserir( &tabelaHash, "l", 60 );
    inserir( &tabelaHash, "ui", 70 );
    inserir( &tabelaHash, "ja", 80 );
    inserir( &tabelaHash, "jaa", 90 );
    inserir( &tabelaHash, "yu", 34 );
    inserir( &tabelaHash, "uy", 58 );
    inserir( &tabelaHash, "asd", 62 );
    inserir( &tabelaHash, "ds", 55 );
    inserir( &tabelaHash, "ge", 3465 );
    inserir( &tabelaHash, "yu", 57 );
    inserir( &tabelaHash, "yh", 4567 );
    inserir( &tabelaHash, "ew", 112 );
    inserir( &tabelaHash, "ss", 433 );
    inserir( &tabelaHash, "sd", 1238 );
    inserir( &tabelaHash, "sw", 212 );

    imprimir( &tabelaHash );

    printf( "remover a - %d\n", remover( &tabelaHash, "a" ) );
    printf( "remover AA - %d\n", remover( &tabelaHash, "AA" ) );
    printf( "remover c - %d\n", remover( &tabelaHash, "c" ) );
    printf( "remover d - %d\n", remover( &tabelaHash, "d" ) );
    printf( "remover Aa - %d\n", remover( &tabelaHash, "Aa" ) );

    imprimir( &tabelaHash );

    inserir( &tabelaHash, "a", 110 );
    inserir( &tabelaHash, "a", 120 );

    imprimir( &tabelaHash );

    printf( "[%s]: a\n", buscar( &tabelaHash, "a" ) != NULL ? "Achou" : "Nao Achou" );
    printf( "[%s]: aa\n", buscar( &tabelaHash, "aa" ) != NULL ? "Achou" : "Nao Achou" );
    printf( "[%s]: aaa\n", buscar( &tabelaHash, "aaa" ) != NULL ? "Achou" : "Nao Achou" );
    printf( "[%s]: aaaa\n\n", buscar( &tabelaHash, "aaaa" ) != NULL ? "Achou" : "Nao Achou" );


    imprimir( &tabelaHash );


    return 0;
}
