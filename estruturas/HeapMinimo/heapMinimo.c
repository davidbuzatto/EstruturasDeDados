#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heapMinimo.h"

/*
    Fun��o de troca.
 */
void swap( int *n1, int *n2 ) {

    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;

}

/*
    Inicializa um heap m�nimo.
 */
void iniciar( HeapMinimo *heapMinimo ) {
    heapMinimo->tamanho = 0;
}

/*
    Verifica se um heap m�nimo est� vazio.
 */
bool estaVazio( HeapMinimo *heapMinimo ) {

    if ( heapMinimo->tamanho == 0 ) {
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
    Reorganiza o heap m�nimo.
 */
void heapfy( HeapMinimo *heapMinimo, int raiz, int tamanho ) {

    int maior = raiz;
    int filhoEsquerda = 2 * raiz + 1;
    int filhoDireita = 2 * raiz;

    if ( filhoEsquerda <= tamanho ) {

        // o n� que est� sendo analisado
        // tem filhos para a esquerda e direita
        if ( heapMinimo->valores[filhoEsquerda] <= heapMinimo->valores[filhoDireita] &&
             heapMinimo->valores[filhoEsquerda] < heapMinimo->valores[raiz] ) {

            maior = filhoEsquerda;

        } else if ( heapMinimo->valores[filhoDireita] < heapMinimo->valores[filhoEsquerda] &&
                    heapMinimo->valores[filhoDireita] < heapMinimo->valores[raiz] ) {

            maior = filhoDireita;

        }

    } else if ( filhoDireita <= tamanho ) {

        // o n� que est� sendo analizado
        // tem filho apenas para a direita
        if ( heapMinimo->valores[filhoDireita] < heapMinimo->valores[raiz] ) {
            maior = filhoDireita;
        }

    }

    if ( maior != raiz ) {

        swap( &(heapMinimo->valores[raiz]), &(heapMinimo->valores[maior]) );
        heapfy( heapMinimo, maior, tamanho );

    }

}

/*
    Insere um elemento do heap m�nimo.
 */
void inserir( HeapMinimo *heapMinimo, int valor ) {

    if ( heapMinimo->tamanho < TAM_MAX_HEAP ) {

        heapMinimo->tamanho++;
        int posicao = heapMinimo->tamanho;
        int pai = calcularPai(posicao);

        while ( posicao > 1 &&
                heapMinimo->valores[pai] > valor ) {

            heapMinimo->valores[posicao] = heapMinimo->valores[pai];
            posicao = pai;

            pai = calcularPai(posicao);

        }

        heapMinimo->valores[posicao] = valor;

    } else {

        printf( "Heap maximo cheio - Overflow!" );
        exit( 1 );

    }

}

/*
    Remove um elemento do heap m�nimo (aquele com menor prioridade).
 */
int remover( HeapMinimo *heapMinimo ) {

    if ( estaVazio( heapMinimo ) ) {

        printf( "Heap minimo vazio - Underflow!" );
        exit( 1 );

    } else {

        int menor = heapMinimo->valores[1];
        heapMinimo->valores[1] = heapMinimo->valores[heapMinimo->tamanho];
        heapMinimo->tamanho--;

        heapfy( heapMinimo, 1, heapMinimo->tamanho );

        return menor;

    }

}

/*
    Consulta um elemento do heap m�nimo (aquele com menor prioridade).
 */
int consultar( HeapMinimo *heapMinimo ) {

    if ( estaVazio( heapMinimo ) ) {
        printf( "Heap minimo vazio - Underflow!" );
        exit( 1 );
    } else {
        return heapMinimo->valores[1];
    }

}

/*
    Esvazia o heap m�nimo.
 */
void esvaziar( HeapMinimo *heapMinimo ) {
    heapMinimo->tamanho = 0;
}

/*
    Imprime o conte�do do heap m�nimo.
 */
void imprimir( HeapMinimo *heapMinimo ) {

    int i;

    for ( i = 1; i <= heapMinimo->tamanho; i++ ) {
        printf( "%d ", heapMinimo->valores[i] );
    }

    printf( "\n" );

}
