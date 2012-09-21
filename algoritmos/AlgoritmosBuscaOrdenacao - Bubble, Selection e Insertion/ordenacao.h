#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdbool.h>

/*
 * Fun��es utilit�rias.
 */
void swap( int *n1, int *n2 );
void shuffle( int *array, int tamanho );

/*
 * Fun��o de ordena��o gen�rica.
 */
void sort( void ( *funcaoOrdenacao )( int *, int ), int *array, int tamanho );

/*
 * Algoritmos de ordena��o por troca.
 */
void bubbleSort( int *array, int tamanho );
void bubbleSortV1( int *array, int tamanho );
void bubbleSortV2( int *array, int tamanho );
void bubbleSortV3( int *array, int tamanho );
void bubbleSortV4( int *array, int tamanho );

/*
 * Algoritmos de ordena��o por sele��o.
 */
void selectionSort( int *array, int tamanho );

/*
 * Algoritmos de ordena��o por inser��o.
 */
void insertionSort( int *array, int tamanho );

#endif // ORDENACAO_H
