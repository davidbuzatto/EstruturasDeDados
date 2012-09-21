#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {

    Lista li;
    iniciar( &li );

    inserirInicio( &li, 1 );
    inserirInicio( &li, 2 );
    imprimir( &li );
    imprimirInverso( &li );

    inserirFim( &li, 3 );
    inserirFim( &li, 4 );
    imprimir( &li );
    imprimirInverso( &li );
    printf( "tamanho: %d\n", tamanho( &li ) );

    printf( "\nInserindo 55 na posicao 0 (inicio da lista).\n" );
    inserir( &li, 55, 0 );
    imprimir( &li );
    imprimirInverso( &li );

    printf( "\nInserindo 66 na posicao 5 (fim da lista).\n" );
    inserir( &li, 66, 5 );
    imprimir( &li );
    imprimirInverso( &li );

    printf( "\nInserindo 77 na posicao -5 (inicio da lista).\n" );
    inserir( &li, 77, -5 );
    imprimir( &li );
    imprimirInverso( &li );

    printf( "\nInserindo 88 na posicao 50 (fim da lista).\n" );
    inserir( &li, 88, 50 );
    imprimir( &li );
    imprimirInverso( &li );

    printf( "\nInserindo 99 na posicao 3 (quarto elemento).\n" );
    inserir( &li, 99, 3 );
    imprimir( &li );
    imprimirInverso( &li );

    alterarInicio( &li, 555 );
    imprimir( &li );
    imprimirInverso( &li );
    alterarFim( &li, 666 );
    imprimir( &li );
    imprimirInverso( &li );
    alterar( &li, 777, 3 );
    imprimir( &li );
    imprimirInverso( &li );


    /*while ( !estaVazia( &li ) ) {
        printf( "Ini: %d\n", removerInicio( &li ) );
        imprimir( &li );
        imprimirInverso( &li );
    }*/

    while ( !estaVazia( &li ) ) {
        printf( "Fim: %d\n", removerFim( &li ) );
        imprimir( &li );
        imprimirInverso( &li );
    }

    /*while ( !estaVazia( &li ) ) {
        printf( "Pos: %d\n", remover( &li, 3 ) );
        imprimir( &li );
        imprimirInverso( &li );
    }*/

    printf( "Ini: %d\n", consultarInicio( &li ) );
    imprimir( &li );
    printf( "Fim: %d\n", consultarFim( &li ) );
    imprimir( &li );
    printf( "Pos: %d\n", consultar( &li, 4 ) );
    imprimir( &li );

    return 0;

}
