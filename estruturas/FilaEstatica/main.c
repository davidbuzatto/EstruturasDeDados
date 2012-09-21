#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {

    Fila f;
    iniciar( &f );

    enfileirar( &f, 3 );
    enfileirar( &f, 7 );
    enfileirar( &f, 8 );
    enfileirar( &f, 10 );

    printf( "Fila: ");
    imprimir( &f );

    printf( "\nDesenfileirou: %d\n", desenfileirar( &f ) );
    printf( "Fila: ");
    imprimir( &f );

    printf( "\nDesenfileirou: %d\n", desenfileirar( &f ) );
    printf( "Fila: ");
    imprimir( &f );

    printf( "\nDesenfileirou: %d\n", desenfileirar( &f ) );
    printf( "Fila: ");
    imprimir( &f );

    printf( "\nDesenfileirou: %d\n", desenfileirar( &f ) );
    printf( "Fila: ");
    imprimir( &f );

    enfileirar( &f, 67 );
    enfileirar( &f, 325 );
    enfileirar( &f, 5753 );

    printf( "\nFila: ");
    imprimir( &f );

    printf( "\nCabeca: %d\n", consultarCabeca( &f ) );
    printf( "Fila: ");
    imprimir( &f );

    printf( "\nA fila esta vazia? " );
    printf( estaVazia( &f ) ? "Sim" : "Nao" );

    esvaziar( &f );

    printf( "\nA fila esta vazia? " );
    printf( estaVazia( &f ) ? "Sim" : "Nao" );

    printf( "\n" );

    return 0;

}
