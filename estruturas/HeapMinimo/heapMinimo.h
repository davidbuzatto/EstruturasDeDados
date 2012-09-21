#ifndef HEAPMINIMO_H
#define HEAPMINIMO_H

#include <stdbool.h>

#define TAM_MAX_HEAP 10

typedef struct heapMinimo {
    int valores[TAM_MAX_HEAP + 1];
    int tamanho;
} HeapMinimo;

/*
    Fun��o de troca.
 */
void swap( int *n1, int *n2 );

/*
    Inicializa um heap m�nimo.
 */
void iniciar( HeapMinimo *heapMinimo );

/*
    Verifica se um heap m�nimo est� vazio.
 */
bool estaVazio( HeapMinimo *heapMinimo );

/*
    Calcula a posi��o do pai do elemento de posi��o i.
 */
int calcularPai( int i );

/*
    Reorganiza o heap m�nimo.
 */
void heapfy( HeapMinimo *heapMinimo, int raiz, int tamanho );

/*
    Insere um elemento do heap m�nimo.
 */
void inserir( HeapMinimo *heapMinimo, int valor );

/*
    Remove um elemento do heap m�nimo (aquele com menor prioridade).
 */
int remover( HeapMinimo *heapMinimo );

/*
    Consulta um elemento do heap m�nimo (aquele com menor prioridade).
 */
int consultar( HeapMinimo *heapMinimo );

/*
    Esvazia o heap m�nimo.
 */
void esvaziar( HeapMinimo *heapMinimo );

/*
    Imprime o conte�do do heap m�nimo.
 */
void imprimir( HeapMinimo *heapMinimo );

#endif // HEAPMINIMO_H
