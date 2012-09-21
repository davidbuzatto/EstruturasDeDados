#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "busca.h"

#define TAMANHO_ARRAY_BUSCA 10

void testesBuscas() {

    int dados[] = { 1, 3, 5, 6, 7, 9, 10, 12, 14, 20 };
    int i;

    printf( "Busca Sequencial ou Linear:\n" );
    for ( i = 0; i < 10; i++ ) {
        printf( "%d %s\n", i, buscaSequencial( i, dados, TAMANHO_ARRAY_BUSCA ) ? "***" : "" );
    }

    printf( "\nBusca Binaria:\n" );
    for ( i = 0; i < 10; i++ ) {
        printf( "%d %s\n", i, buscaBinaria( i, dados, TAMANHO_ARRAY_BUSCA ) ? "***" : "" );
    }

}

void imprimir( int *array, int tamanho ) {
    int i;
    for ( i = 0; i < tamanho; i++ ) {
        printf( "%d ", array[i] );
    }
    printf( "\n" );
}

int main() {

    testesBuscas();

    return 0;

}
