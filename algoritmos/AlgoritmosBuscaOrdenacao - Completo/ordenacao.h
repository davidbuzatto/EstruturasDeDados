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
void heapSort( int *array, int tamanho );
void gerarHeap( int *array, int tamanho );
void ordenarHeapSort( int *array, int tamanho );
void heapfy( int *array, int raiz, int tamanho );

/*
 * Algoritmos de ordenação por inserção.
 */
void insertionSort( int *array, int tamanho );
void shellSort( int *array, int tamanho );
void binaryTreeSort( int *array, int tamanho );

/*
 * Algoritmos de ordenação por merge (intercalação).
 */
void mergeSort( int *array, int tamanho );
void mergeSortR( int *array, int inicio, int fim );
void intercalar( int *array, int inicio, int fim, int meio );

/*
 * Algoritmos de ordenação por particionamento.
 */
void quickSort( int *array, int tamanho );
void quickSortR( int* array, int p, int r );
int particionar( int* array, int p, int r );

#endif // ORDENACAO_H
