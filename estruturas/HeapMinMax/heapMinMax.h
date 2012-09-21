#ifndef HEAPMINMAX_H
#define HEAPMINMAX_H

#include <stdbool.h>

#define TAM_MAX_HEAP 10

typedef struct heapMinMax {
    int valores[TAM_MAX_HEAP + 1];
    int tamanho;
} HeapMinMax;

/*
    Fun��o de troca.
 */
void swap( int *n1, int *n2 );

/*
    Inicializa um heap min-max.
 */
void iniciar( HeapMinMax *heapMinMax );

/*
    Verifica se um heap min-max est� vazio.
 */
bool estaVazio( HeapMinMax *heapMinMax );

/*
    Verifica se a posi��o passada � o �ndice do valor m�nimo.
 */
bool ehMinimo( int posicao );

/*
    Reposiciona acima o elemento de maior prioridade.
 */
void subirMaximo( HeapMinMax *heapMinMax, int posicao );

/*
    Reposiciona acima o elemento de menor prioridade.
 */
void subirMinimo( HeapMinMax *heapMinMax, int posicao );

/*
    Reposiciona acima um elemento.
 */
void subir( HeapMinMax *heapMinMax, int posicao );

/*
    Retorna o �ndice do elemento de maior prioridade.
 */
int indiceMaiorPrioridade( HeapMinMax *heapMinMax );

/*
    Retorna o �ndice do menor dos descendentes entre filhos e netos
    da posi��o passada.
 */
int indiceMenorDescendente( HeapMinMax *heapMinMax, int posicao );

/*
    Retorna o �ndice do maior dos descendentes entre filhos e netos
    da posi��o passada.
 */
int indiceMaiorDescendente( HeapMinMax *heapMinMax, int posicao );

/*
    Reposiciona abaixo o elemento de menor prioridade.
 */
void descerMinimo( HeapMinMax *heapMinMax, int posicao );

/*
    Reposiciona abaixo o elemento de maior prioridade.
 */
void descerMaximo( HeapMinMax *heapMinMax, int posicao );

/*
    Reposiciona abaixo um elemento.
 */
void descer( HeapMinMax *heapMinMax, int posicao );

/*
    Reorganiza o heap min-max.
 */
void heapfy( HeapMinMax *heapMinMax, int raiz, int tamanho );

/*
    Insere um elemento do heap min-max.
 */
void inserir( HeapMinMax *heapMinMax, int valor );

/*
    Remove o elemento de menor prioridade do heap min-max.
 */
int removerMenorPrioridade( HeapMinMax *heapMinMax );

/*
    Remove o elemento de maior prioridade do heap min-max.
 */
int removerMaiorPrioridade( HeapMinMax *heapMinMax );

/*
    Consulta o elemento de menor prioridade do heap min-max.
 */
int consultarMenorPrioridade( HeapMinMax *heapMinMax );

/*
    Consulta o elemento de maior prioridade do heap min-max.
 */
int consultarMaiorPrioridade( HeapMinMax *heapMinMax );

/*
    Esvazia o heap min-max.
 */
void esvaziar( HeapMinMax *heapMinMax );

/*
    Imprime o conte�do do heap min-max.
 */
void imprimir( HeapMinMax *heapMinMax );

#endif // HEAPMINMAX_H
