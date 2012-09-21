#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main() {

    Pilha p;
    iniciar( &p );

    empilhar( &p, -5 );
    empilhar( &p, 4 );
    empilhar( &p, 9 );
    empilhar( &p, -56 );

    printf( "Topo: %d\n", consultarTopo( &p ) );
    printf( "Pilha: \n" );
    imprimir( &p );

    printf( "\nDesempilhou: %d\n", desempilhar( &p ) );
    printf( "Pilha: \n" );
    imprimir( &p );

    printf( "\nTopo: %d\n", consultarTopo( &p ) );
    printf( "Pilha: \n" );
    imprimir( &p );

    printf( "\nA pilha esta vazia? " );
    if ( estaVazia( &p ) ) {
        printf( "Sim!\n\n" );
    } else {
        printf( "Nao!\n\n" );
    }

    printf( "Esvaziando a pilha...\n" );
    esvaziar( &p );

    printf( "\nA pilha esta vazia? " );
    if ( estaVazia( &p ) ) {
        printf( "Sim!\n\n" );
    } else {
        printf( "Nao!\n\n" );
    }

    desempilhar( &p );

    return 0;

}
