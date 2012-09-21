#ifndef HEAPMINIMO_H
#define HEAPMINIMO_H

#include <stdbool.h>

#define TAM_MAX_HEAP 10

typedef struct heapMinimo {
    int valores[TAM_MAX_HEAP + 1];
    int tamanho;
} HeapMinimo;

/*
    Função de troca.
 */
void swap( int *n1, int *n2 );

/*
    Inicializa um heap mínimo.
 */
void iniciar( HeapMinimo *heapMinimo );

/*
    Verifica se um heap mínimo está vazio.
 */
bool estaVazio( HeapMinimo *heapMinimo );

/*
    Calcula a posição do pai do elemento de posição i.
 */
int calcularPai( int i );

/*
    Reorganiza o heap mínimo.
 */
void heapfy( HeapMinimo *heapMinimo, int raiz, int tamanho );

/*
    Insere um elemento do heap mínimo.
 */
void inserir( HeapMinimo *heapMinimo, int valor );

/*
    Remove um elemento do heap mínimo (aquele com menor prioridade).
 */
int remover( HeapMinimo *heapMinimo );

/*
    Consulta um elemento do heap mínimo (aquele com menor prioridade).
 */
int consultar( HeapMinimo *heapMinimo );

/*
    Esvazia o heap mínimo.
 */
void esvaziar( HeapMinimo *heapMinimo );

/*
    Imprime o conteúdo do heap mínimo.
 */
void imprimir( HeapMinimo *heapMinimo );

#endif // HEAPMINIMO_H
