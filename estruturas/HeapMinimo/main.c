#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heapMinimo.h"

int main() {

    HeapMinimo heap;
    iniciar( &heap );

    inserir( &heap, 10 );
    inserir( &heap, 4 );
    inserir( &heap, 2 );
    inserir( &heap, 21 );
    inserir( &heap, -1 );
    inserir( &heap, 3 );

    printf( "Item com menor prioridade: %d\n", consultar( &heap ) );

    imprimir( &heap );

    printf( "Removendo: %d\n", remover( &heap ) );
    printf( "Removendo: %d\n", remover( &heap ) );
    printf( "Removendo: %d\n", remover( &heap ) );
    printf( "Removendo: %d\n", remover( &heap ) );
    printf( "Removendo: %d\n", remover( &heap ) );
    //printf( "Removendo: %d\n", remover( &heap ) );
    //printf( "Removendo: %d\n", remover( &heap ) );

    imprimir( &heap );

    esvaziar( &heap );

    inserir( &heap, 2 );
    inserir( &heap, 21 );
    inserir( &heap, -1 );

    imprimir( &heap );

    printf( "Removendo: %d\n", remover( &heap ) );

    imprimir( &heap );

    return 0;

}
