#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvoreBinariaBuscaOrdenacao.h"

/*
 * Inicia a �rvore.
 */
void iniciar( ArvoreBinariaBusca *arvore ) {
    arvore->raiz = NULL;
}


/*
 * Verifica se a �rvore est� vazia.
 */
bool estaVazia( ArvoreBinariaBusca *arvore ) {
    if ( arvore->raiz == NULL ) {
        return true;
    } else {
        return false;
    }
}


/*
 * Opera��es da �rvore.
 */
void inserir( ArvoreBinariaBusca *arvore, int valor ) {

    /*
     * Algoritmo recursivo.
     */
    arvore->raiz = inserirNo( arvore->raiz, valor );

}


bool contem( ArvoreBinariaBusca *arvore, int valor ) {

    /*
     * Algoritmo recursivo.
     */
    return contemNo( arvore->raiz, valor );

}


bool remover( ArvoreBinariaBusca *arvore, int valor ) {


    /*
     * Algoritmo recursivo.
     */
    bool achou = contemNo( arvore->raiz, valor );

    if ( achou ) {
        arvore->raiz = removerNo( arvore->raiz, valor );
    }

    return achou;

}


/*
 * Fun��es auxiliares para a execu��o das vers�es recursivas
 * das opera��es da �rvore.
 */
No* inserirNo( No *no, int valor ) {

    if ( no == NULL ) {

        no = ( No* ) malloc( sizeof( No ) );
        no->valor = valor;
        no->esquerda = NULL;
        no->direita = NULL;

    } else if ( valor < no->valor ) {
        no->esquerda = inserirNo( no->esquerda, valor );
    } else {
        no->direita = inserirNo( no->direita, valor );
    }

    return no;

}


bool contemNo( No *no, int valor ) {

    bool achou = false;

    if ( no != NULL ) {

        if ( valor == no->valor ) {
            achou = true;
        } else if ( valor < no->valor ) {
            achou = contemNo( no->esquerda, valor );
        } else {
            achou = contemNo( no->direita, valor );
        }

    }

    return achou;

}


No* removerNo( No *no, int valor ) {

    No* temp;

    if ( valor == no->valor ) {

        // o n� n�o tem filhos
        if ( no->esquerda == no->direita ) {

            free( no );
            return NULL;

        // o n� a ser removido n�o tem filho � esquerda
        } else if ( no->esquerda == NULL ) {

            temp = no->direita;
            free( no );
            return temp;

        // o n� a ser removido n�o tem filho � direita
        } else if ( no->direita == NULL ) {

            temp = no->esquerda;
            free( no );
            return temp;

        // o n� a ser removido tem filhos em ambos os lados
        } else {

            No *aux = no->direita;
            temp = no->direita;

            while ( temp->esquerda != NULL ) {
                temp = temp->esquerda;
            }

            temp->esquerda = no->esquerda;
            free( no );

            return aux;

        }

    } else if ( valor < no->valor ) {
        no->esquerda = removerNo( no->esquerda, valor );
    } else {
        no->direita = removerNo( no->direita, valor );
    }

    return no;

}


/*
 * Fun��o para execu��o dos percursos.
 */
void percorrer( ArvoreBinariaBusca *arvore, TipoPercurso tipo ) {

    switch ( tipo ) {
        case EM_ORDEM:
            percorrerEmOrdem( arvore->raiz );
            break;
        case PRE_ORDEM:
            percorrerEmPreOrdem( arvore->raiz );
            break;
        case POS_ORDEM:
            percorrerEmPosOrdem( arvore->raiz );
            break;
        case EM_ORDEM_INV:
            percorrerEmOrdemInversa( arvore->raiz );
            break;
        case PRE_ORDEM_INV:
            percorrerEmPreOrdemInversa( arvore->raiz );
            break;
        case POS_ORDEM_INV:
            percorrerEmPosOrdemInversa( arvore->raiz );
            break;
    }

    printf( "\n" );

}


/*
 * Percursos (vers�o recursiva).
 */
void percorrerEmPreOrdem( No *no ) {

    if ( no != NULL ) {

        printf( "%d ", no->valor );
        percorrerEmPreOrdem( no->esquerda );
        percorrerEmPreOrdem( no->direita );

    }

}


void percorrerEmOrdem( No *no ) {

    if ( no != NULL ) {

        percorrerEmOrdem( no->esquerda );
        printf( "%d ", no->valor );
        percorrerEmOrdem( no->direita );

    }

}

void percorrerEmOrdemInserindo( No *no, int *array, int *indice ) {

    if ( no != NULL ) {

        percorrerEmOrdemInserindo( no->esquerda, array, indice );
        array[(*indice)++] = no->valor;
        percorrerEmOrdemInserindo( no->direita, array, indice );

    }

}


void percorrerEmPosOrdem( No *no ) {

    if ( no != NULL ) {

        percorrerEmPosOrdem( no->esquerda );
        percorrerEmPosOrdem( no->direita );
        printf( "%d ", no->valor );

    }

}


/*
 * Percursos invertidos (vers�o recursiva).
 */
void percorrerEmPreOrdemInversa( No *no ) {

    if ( no != NULL ) {

        printf( "%d ", no->valor );
        percorrerEmPreOrdemInversa( no->direita );
        percorrerEmPreOrdemInversa( no->esquerda );

    }

}


void percorrerEmOrdemInversa( No *no ) {

    if ( no != NULL ) {

        percorrerEmOrdemInversa( no->direita );
        printf( "%d ", no->valor );
        percorrerEmOrdemInversa( no->esquerda );

    }

}


void percorrerEmPosOrdemInversa( No *no ) {

    if ( no != NULL ) {

        percorrerEmPosOrdemInversa( no->direita );
        percorrerEmPosOrdemInversa( no->esquerda );
        printf( "%d ", no->valor );

    }

}


/*
 * Fun��o para esvaziar a �rvore.
 */
void esvaziar( ArvoreBinariaBusca *arvore ) {
    arvore->raiz = desalocar( arvore->raiz );
}


/*
 * Fun��o recursiva para exclus�o de n�s (usada no esvaziar).
 */
No* desalocar( No* no ) {

    if ( no != NULL ) {
        no->esquerda = desalocar( no->esquerda );
        no->direita = desalocar( no->direita );
        free( no );
    }

    return NULL;

}
