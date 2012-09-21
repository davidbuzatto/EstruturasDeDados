#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "busca.h"

/*
 * Algoritmo de busca sequencial ou linear.
 */
bool buscaSequencial( int valor, int *array, int tamanho ) {

    int i;

    for ( i = 0; i < tamanho; i++ ) {
        if ( array[i] == valor ) {
            return true;
        }
    }

    return false;

}

/*
 * Algoritmo de busca binária.
 * A estrutura a ser percorrida precisa estar ordenada.
 */
bool buscaBinaria( int valor, int *array, int tamanho ) {

    /*
     * Algoritmo iterativo.
     */
    /*int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while ( inicio <= fim ) {

        meio = ( inicio + fim ) / 2;

        if ( valor == array[meio] ) {
            return true;
        } else if ( valor < array[meio] ) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }

    }

    return false;*/


    /*
     * Algoritmo recursivo.
     */
    return buscaBinariaR( valor, array, 0, tamanho - 1 );

}

/*
 * Algoritmo recursivo da busca binária.
 */
bool buscaBinariaR( int valor, int *array, int inicio, int fim ) {

    int meio = ( inicio + fim ) / 2;

    if ( inicio <= fim ) {
        if ( valor == array[meio] ) {
            return true;
        } else if ( valor < array[meio] ) {
            return buscaBinariaR( valor, array, inicio, meio - 1 );
        } else {
            return buscaBinariaR( valor, array, meio + 1, fim );
        }
    } else {
        return false;
    }

}


