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
 * Inicia a árvore.
 */
void iniciar( ArvoreBinariaBusca *arvore );

/*
 * Verifica se a árvore está vazia.
 */
bool estaVazia( ArvoreBinariaBusca *arvore );

/*
 * Operações da árvore.
 */
void inserir( ArvoreBinariaBusca *arvore, int valor );
bool contem( ArvoreBinariaBusca *arvore, int valor );
bool remover( ArvoreBinariaBusca *arvore, int valor );

/*
 * Funções auxiliares para a execução das versões recursivas
 * das operações da árvore.
 */
No* inserirNo( No *no, int valor );
bool contemNo( No *no, int valor );
No* removerNo( No *no, int valor );

/*
 * Função para execução dos percursos.
 */
void percorrer( ArvoreBinariaBusca *arvore, TipoPercurso tipo );

/*
 * Percursos (versão recursiva).
 */
void percorrerEmPreOrdem( No *no );
void percorrerEmOrdem( No *no );    // em order == ordem simétrica
void percorrerEmPosOrdem( No *no ); // pós-ordem == ordem final
void percorrerEmOrdemInserindo( No *no, int *array, int *indice );

/*
 * Percursos invertidos (versão recursiva).
 */
void percorrerEmPreOrdemInversa( No *no );
void percorrerEmOrdemInversa( No *no );
void percorrerEmPosOrdemInversa( No *no );

/*
 * Função para esvaziar a árvore.
 */
void esvaziar( ArvoreBinariaBusca *arvore );

/*
 * Função recursiva para exclusão de nós (usada no esvaziar).
 */
No* desalocar( No* no );

#endif // ARVOREBINARIABUSCAORDENACAO_H
