#ifndef ARVOREBINARIABUSCAORDENACAO_H
#define ARVOREBINARIABUSCAORDENACAO_H

#include <stdbool.h>

typedef enum tipoPercurso {
    EM_ORDEM,
    PRE_ORDEM,
    POS_ORDEM,
    EM_ORDEM_INV,
    PRE_ORDEM_INV,
    POS_ORDEM_INV
} TipoPercurso;

typedef struct no {
    int valor;
    struct no* esquerda;
    struct no* direita;
} No;

typedef struct arvoreBinariaBusca {
    No *raiz;
} ArvoreBinariaBusca;


/*
 * Inicia a �rvore.
 */
void iniciar( ArvoreBinariaBusca *arvore );

/*
 * Verifica se a �rvore est� vazia.
 */
bool estaVazia( ArvoreBinariaBusca *arvore );

/*
 * Opera��es da �rvore.
 */
void inserir( ArvoreBinariaBusca *arvore, int valor );
bool contem( ArvoreBinariaBusca *arvore, int valor );
bool remover( ArvoreBinariaBusca *arvore, int valor );

/*
 * Fun��es auxiliares para a execu��o das vers�es recursivas
 * das opera��es da �rvore.
 */
No* inserirNo( No *no, int valor );
bool contemNo( No *no, int valor );
No* removerNo( No *no, int valor );

/*
 * Fun��o para execu��o dos percursos.
 */
void percorrer( ArvoreBinariaBusca *arvore, TipoPercurso tipo );

/*
 * Percursos (vers�o recursiva).
 */
void percorrerEmPreOrdem( No *no );
void percorrerEmOrdem( No *no );    // em order == ordem sim�trica
void percorrerEmPosOrdem( No *no ); // p�s-ordem == ordem final
void percorrerEmOrdemInserindo( No *no, int *array, int *indice );

/*
 * Percursos invertidos (vers�o recursiva).
 */
void percorrerEmPreOrdemInversa( No *no );
void percorrerEmOrdemInversa( No *no );
void percorrerEmPosOrdemInversa( No *no );

/*
 * Fun��o para esvaziar a �rvore.
 */
void esvaziar( ArvoreBinariaBusca *arvore );

/*
 * Fun��o recursiva para exclus�o de n�s (usada no esvaziar).
 */
No* desalocar( No* no );

#endif // ARVOREBINARIABUSCAORDENACAO_H
