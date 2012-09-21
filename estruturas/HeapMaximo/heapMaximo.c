#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heapMaximo.h"

/*
    Fun��o de troca.
 */
void swap( int *n1, int *n2 ) {

    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;

}

/*
    Inicializa um heap m�ximo.
 */
void iniciar( HeapMaximo *heapMaximo ) {
    heapMaximo->tamanho = 0;
}

/*
    Verifica se um heap m�ximo est� vazio.
 */
bool estaVazio( HeapMaximo *heapMaximo ) {

    if ( heapMaximo->tamanho == 0 ) {
        return true;
    } else {
        return false;
    }

}

/*
    Calcula a posi��o do pai do elemento de posi��o i.
 */
int calcularPai( int i ) {
    return i / 2;
}

/*
    Reorganiza o heap m�ximo.
 */
void heapfy( HeapMaximo *heapMaximo, int raiz, int tamanho ) {

    int maior = raiz;
    int filhoEsquerda = 2 * raiz + 1;
    int filhoDireita = 2 * raiz;

    if ( filhoEsquerda <= tamanho ) {

        // o n� que est� sendo analisado
        // tem filhos para a esquerda e direita
        if ( heapMaximo->valores[filhoEsquerda] >= heapMaximo->valores[filhoDireita] &&
             heapMaximo->valores[filhoEsquerda] > heapMaximo->valores[raiz] ) {

            maior = filhoEsquerda;

        } else if ( heapMaximo->valores[filhoDireita] > heapMaximo->valores[filhoEsquerda] &&
                    heapMaximo->valores[filhoDireita] > heapMaximo->valores[raiz] ) {

            maior = filhoDireita;

        }

    } else if ( filhoDireita <= tamanho ) {

        // o n� que est� sendo analizado
        // tem filho apenas para a direita
        if ( heapMaximo->valores[filhoDireita] > heapMaximo->valores[raiz] ) {
            maior = filhoDireita;
        }

    }

    if ( maior != raiz ) {

        swap( &(heapMaximo->valores[raiz]), &(heapMaximo->valores[maior]) );
        heapfy( heapMaximo, maior, tamanho );

    }

}

/*
    Insere um elemento do heap m�ximo.
 */
void inserir( HeapMaximo *heapMaximo, int valor ) {

    if ( heapMaximo->tamanho < TAM_MAX_HEAP ) {

        heapMaximo->tamanho++;
        int posicao = heapMaximo->tamanho;
        int pai = calcularPai(posicao);

        while ( posicao > 1 &&
                heapMaximo->valores[pai] < valor ) {

            heapMaximo->valores[posicao] = heapMaximo->valores[pai];
            posicao = pai;

            pai = calcularPai(posicao);

        }

        heapMaximo->valores[posicao] = valor;

    } else {

        printf( "Heap maximo cheio - Overflow!" );
        exit( 1 );

    }

}

/*
    Remove um elemento do heap m�ximo (aquele com maior prioridade).
 */
int remover( HeapMaximo *heapMaximo ) {

    if ( estaVazio( heapMaximo ) ) {

        printf( "Heap maximo vazio - Underflow!" );
        exit( 1 );

    } else {

        int maior = heapMaximo->valores[1];
        heapMaximo->valores[1] = heapMaximo->valores[heapMaximo->tamanho];
        heapMaximo->tamanho--;

        heapfy( heapMaximo, 1, heapMaximo->tamanho );

        return maior;

    }

}

/*
    Consulta um elemento do heap m�ximo (aquele com maior prioridade).
 */
int consultar( HeapMaximo *heapMaximo ) {

    if ( estaVazio( heapMaximo ) ) {
        printf( "Heap maximo vazio - Underflow!" );
        exit( 1 );
    } else {
        return heapMaximo->valores[1];
    }

}

/*
    Esvazia o heap m�ximo.
 */
void esvaziar( HeapMaximo *heapMaximo ) {
    heapMaximo->tamanho = 0;
}

/*
    Imprime o conte�do do heap m�ximo.
 */
void imprimir( HeapMaximo *heapMaximo ) {

    int i;

    for ( i = 1; i <= heapMaximo->tamanho; i++ ) {
        printf( "%d ", heapMaximo->valores[i] );
    }

    printf( "\n" );

}
