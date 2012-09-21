#ifndef HEAPMAXIMO_H
#define HEAPMAXIMO_H

#include <stdbool.h>

#define TAM_MAX_HEAP 10

typedef struct heapMaximo {
    int valores[TAM_MAX_HEAP + 1];
    int tamanho;
} HeapMaximo;

/*
    Função de troca.
 */
void swap( int *n1, int *n2 );

/*
    Inicializa um heap máximo.
 */
void iniciar( HeapMaximo *heapMaximo );

/*
    Verifica se um heap máximo está vazio.
 */
bool estaVazio( HeapMaximo *heapMaximo );

/*
    Calcula a posição do pai do elemento de posição i.
 */
int calcularPai( int i );

/*
    Reorganiza o heap máximo.
 */
void heapfy( HeapMaximo *heapMaximo, int raiz, int tamanho );

/*
    Insere um elemento do heap máximo.
 */
void inserir( HeapMaximo *heapMaximo, int valor );

/*
    Remove um elemento do heap máximo (aquele com maior prioridade).
 */
int remover( HeapMaximo *heapMaximo );

/*
    Consulta um elemento do heap máximo (aquele com maior prioridade).
 */
int consultar( HeapMaximo *heapMaximo );

/*
    Esvazia o heap máximo.
 */
void esvaziar( HeapMaximo *heapMaximo );

/*
    Imprime o conteúdo do heap máximo.
 */
void imprimir( HeapMaximo *heapMaximo );

#endif // HEAPMAXIMO_H
