#ifndef LISTA_H
#define LISTA_H

#include <stdbool.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct lista {
    No *cauda;
    No *cabeca;
    int tamanho;
} Lista;

void iniciar( Lista *lista );
bool estaVazia( Lista *lista );
int tamanho( Lista *lista );

/*
 * Fun��es para inserir elementos na lista.
 * Normalmente chamadas de "add" em ingl�s.
 */
void inserirInicio( Lista *lista, int valor );
void inserirFim( Lista *lista, int valor );
void inserir( Lista *lista, int valor, int posicao );

/*
 * Fun��es para alterar elementos da lista.
 * Normalmente chamadas de "set" em ingl�s.
 */
void alterarInicio( Lista *lista, int valor);
void alterarFim( Lista *lista, int valor );
void alterar( Lista *lista, int valor, int posicao );

/*
 * Fun��es para remover elementos da lista.
 * Normalmente chamadas de "remove" ou "delete" em ingl�s.
 */
int removerInicio( Lista *lista );
int removerFim( Lista *lista );
int remover( Lista *lista, int posicao );

/*
 * Fun��es para consultar elementos da lista, sem remov�-los.
 * Normalmente chamadas de "get" em ingl�s.
 */
int consultarInicio( Lista *lista );
int consultarFim( Lista *lista );
int consultar( Lista *lista, int posicao );

void esvaziar( Lista *lista );
void imprimir( Lista *lista );

#endif // LISTA_H
