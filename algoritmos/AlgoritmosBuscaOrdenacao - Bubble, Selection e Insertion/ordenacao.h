#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <stdbool.h>

/*
 * Funções utilitárias.
 */
void swap( int *n1, int *n2 );
void shuffle( int *array, int tamanho );

/*
 * Função de ordenação genérica.
 */
void sort( void ( *funcaoOrdenacao )( int *, int ), int *array, int tamanho );

/*
 * Algoritmos de ordenação por troca.
 */
void bubbleSort( int *array, int tamanho );
void bubbleSortV1( int *array, int tamanho );
void bubbleSortV2( int *array, int tamanho );
void bubbleSortV3( int *array, int tamanho );
void bubbleSortV4( int *array, int tamanho );

/*
 * Algoritmos de ordenação por seleção.
 */
void selectionSort( int *array, int tamanho );

/*
 * Algoritmos de ordenação por inserção.
 */
void insertionSort( int *array, int tamanho );

#endif // ORDENACAO_H
