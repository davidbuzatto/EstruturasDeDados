#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "busca.h"
#include "ordenacao.h"

#define TAMANHO_ARRAY_BUSCA 10
#define TAMANHO_ARRAY_ORDENACAO 14

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

void testesOrdenacoes() {

    int dados[] = { 3, 5, 1, 2, -1, -2, 4, 8, 10, 4, 23, 2, -1, 5 };

    printf( "Bubble Sort:\n" );
    shuffle( dados, TAMANHO_ARRAY_ORDENACAO );
    imprimir( dados, TAMANHO_ARRAY_ORDENACAO );
    bubbleSort( dados, TAMANHO_ARRAY_ORDENACAO );
    // ou => sort( &bubbleSort, dados, TAMANHO_ARRAY_ORDENACAO );
    imprimir( dados, TAMANHO_ARRAY_ORDENACAO );

    printf( "\nSelection Sort:\n" );
    shuffle( dados, TAMANHO_ARRAY_ORDENACAO );
    imprimir( dados, TAMANHO_ARRAY_ORDENACAO );
    selectionSort( dados, TAMANHO_ARRAY_ORDENACAO );
    // ou => sort( &selectionSort, dados, TAMANHO_ARRAY_ORDENACAO );
    imprimir( dados, TAMANHO_ARRAY_ORDENACAO );

    printf( "\nInsertion Sort:\n" );
    shuffle( dados, TAMANHO_ARRAY_ORDENACAO );
    imprimir( dados, TAMANHO_ARRAY_ORDENACAO );
    insertionSort( dados, TAMANHO_ARRAY_ORDENACAO );
    // ou => sort( &insertionSort, dados, TAMANHO_ARRAY_ORDENACAO );
    imprimir( dados, TAMANHO_ARRAY_ORDENACAO );

    printf( "\nMerge Sort:\n" );
    shuffle( dados, TAMANHO_ARRAY_ORDENACAO );
    imprimir( dados, TAMANHO_ARRAY_ORDENACAO );
    mergeSort( dados, TAMANHO_ARRAY_ORDENACAO );
    // ou => sort( &mergeSort, dados, TAMANHO_ARRAY_ORDENACAO );
    imprimir( dados, TAMANHO_ARRAY_ORDENACAO );

    printf( "\nQuick Sort:\n" );
    shuffle( dados, TAMANHO_ARRAY_ORDENACAO );
    imprimir( dados, TAMANHO_ARRAY_ORDENACAO );
    quickSort( dados, TAMANHO_ARRAY_ORDENACAO );
    // ou => sort( &quickSort, dados, TAMANHO_ARRAY_ORDENACAO );
    imprimir( dados, TAMANHO_ARRAY_ORDENACAO );

}

int main() {

    testesOrdenacoes();
    return 0;

}
