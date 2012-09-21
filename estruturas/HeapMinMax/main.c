#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heapMinMax.h"

int main() {

    HeapMinMax heap;
    iniciar( &heap );

    inserir( &heap, 10 );
    inserir( &heap, 4 );
    inserir( &heap, 2 );
    inserir( &heap, 21 );
    inserir( &heap, -1 );
    inserir( &heap, 3 );

    printf( "Item com maior prioridade: %d\n", consultarMaiorPrioridade( &heap ) );
    printf( "Item com menor prioridade: %d\n", consultarMenorPrioridade( &heap ) );

    imprimir( &heap );

    printf( "Removendo maior: %d\n", removerMaiorPrioridade( &heap ) );
    printf( "Removendo maior: %d\n", removerMaiorPrioridade( &heap ) );
    printf( "Removendo menor: %d\n", removerMenorPrioridade( &heap ) );
    printf( "Removendo menor: %d\n", removerMenorPrioridade( &heap ) );

    imprimir( &heap );

    esvaziar( &heap );

    inserir( &heap, 2 );
    inserir( &heap, 21 );
    inserir( &heap, -1 );

    imprimir( &heap );

    printf( "Removendo maior: %d\n", removerMaiorPrioridade( &heap ) );

    imprimir( &heap );

    return 0;

}
