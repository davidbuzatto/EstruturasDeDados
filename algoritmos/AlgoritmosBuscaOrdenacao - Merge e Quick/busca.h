#ifndef BUSCA_H
#define BUSCA_H

#include <stdbool.h>

/*
 * Algoritmos de Busca.
 */

/*
 * Algoritmo de busca sequencial ou linear.
 */
bool buscaSequencial( int valor, int *array, int tamanho );

/*
 * Algoritmo de busca bin�ria.
 * A estrutura a ser percorrida precisa estar ordenada.
 */
bool buscaBinaria( int valor, int *array, int tamanho );

/*
 * Algoritmo recursivo da busca bin�ria.
 */
bool buscaBinariaR( int valor, int *array, int inicio, int fim );


#endif // BUSCA_H
