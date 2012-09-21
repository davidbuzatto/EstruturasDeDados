#ifndef HEAPMAXIMO_H
#define HEAPMAXIMO_H

#include <stdbool.h>

#define TAM_MAX_HEAP 10

typedef struct heapMaximo {
    int valores[TAM_MAX_HEAP + 1];
    int tamanho;
} HeapMaximo;

/*
    Fun��o de troca.
 */
void swap( int *n1, int *n2 );

/*
    Inicializa um heap m�ximo.
 */
void iniciar( HeapMaximo *heapMaximo );

/*
    Verifica se um heap m�ximo est� vazio.
 */
bool estaVazio( HeapMaximo *heapMaximo );

/*
    Calcula a posi��o do pai do elemento de posi��o i.
 */
int calcularPai( int i );

/*
    Reorganiza o heap m�ximo.
 */
void heapfy( HeapMaximo *heapMaximo, int raiz, int tamanho );

/*
    Insere um elemento do heap m�ximo.
 */
void inserir( HeapMaximo *heapMaximo, int valor );

/*
    Remove um elemento do heap m�ximo (aquele com maior prioridade).
 */
int remover( HeapMaximo *heapMaximo );

/*
    Consulta um elemento do heap m�ximo (aquele com maior prioridade).
 */
int consultar( HeapMaximo *heapMaximo );

/*
    Esvazia o heap m�ximo.
 */
void esvaziar( HeapMaximo *heapMaximo );

/*
    Imprime o conte�do do heap m�ximo.
 */
void imprimir( HeapMaximo *heapMaximo );

#endif // HEAPMAXIMO_H
