#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "ordenacao.h"



/************************
 * Funções utilitárias. *
 ************************/

/*
 * Função de troca.
 */
void swap( int *n1, int *n2 ) {

    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;

    // ou (somente para tipos integrais!!!)
    //*n2 = *n1 + ( *n1 = *n2 ) - *n1;

}

/*
 * Função de embaralhamento.
 */
void shuffle( int *array, int tamanho ) {

    int i;

    srand( time( NULL ) );

    for ( i = 0; i < tamanho; i++ ) {
        swap( &array[i], &array[rand() % tamanho] );
    }

}



/*********************************
 * Função de ordenação genérica. *
 *********************************/

void sort( void ( *funcaoOrdenacao )( int *, int ), int *array, int tamanho ) {
    funcaoOrdenacao( array, tamanho );
}



/**************************************
 * Algoritmos de ordenação por troca. *
 **************************************/

/*
 * Ordenação por borbulhamento ou flutuação.
 *
 * Complexidade:
 *     Melhor caso: O(n) ou O(n^2), depende da implementação.
 *      Caso médio: O(n^2)
 *       Pior caso: O(n^2)
 */
void bubbleSort( int *array, int tamanho ) {

    // versão simples (clássica)
    //bubbleSortV1( array, tamanho );

    // versão melhorada 1
    //bubbleSortV2( array, tamanho );

    // versão melhorada 2
    //bubbleSortV3( array, tamanho );

    // versão melhorada 3
    bubbleSortV4( array, tamanho );

}

/*
 * Ordenação por borbulhamento - versão 1.
 *
 * Complexidade:
 *     Melhor caso: O(n^2)
 *      Caso médio: O(n^2)
 *       Pior caso: O(n^2)
 */
void bubbleSortV1( int *array, int tamanho ) {

    int i;
    int j;

    for ( i = 0; i < tamanho; i++ ) {
        for ( j = 0; j < tamanho - 1; j++ ) {
            if ( array[j] > array[j+1] ) {
                swap( &array[j], &array[j+1] );
            }
        }
    }

}

/*
 * Ordenação por borbulhamento - versão 2.
 * A última posição do ciclo anterior já está na posição correta.
 *
 * Complexidade:
 *     Melhor caso: O(n^2)
 *      Caso médio: O(n^2)
 *       Pior caso: O(n^2)
 */
void bubbleSortV2( int *array, int tamanho ) {

    int i;
    int j;

    for ( i = 0; i < tamanho; i++ ) {
        for ( j = 0; j < tamanho - 1 - i; j++ ) {
            if ( array[j] > array[j+1] ) {
                swap( &array[j], &array[j+1] );
            }
        }
    }

}

/*
 * Ordenação por borbulhamento - versão 3.
 * A última posição do ciclo anterior já está na posição correta.
 * Se não houver troca em um ciclo o algoritmo para.
 *
 * Complexidade:
 *     Melhor caso: O(n)
 *      Caso médio: O(n^2)
 *       Pior caso: O(n^2)
 */
void bubbleSortV3( int *array, int tamanho ) {

    int i;
    int j;
    bool trocou;

    for ( i = 0; i < tamanho; i++ ) {

        trocou = false;

        for ( j = 0; j < tamanho - 1 - i; j++ ) {
            if ( array[j] > array[j+1] ) {
                swap( &array[j], &array[j+1] );
                trocou = true;
            }
        }

        if ( !trocou ) {
            return;
        }

    }

}

/*
 * Ordenação por borbulhamento - versão 4.
 * A última posição do ciclo anterior já está na posição correta.
 * Se não houver troca em um ciclo o algoritmo para, pois o
 * limite da busca é controlado.
 *
 * Complexidade:
 *     Melhor caso: O(n)
 *      Caso médio: O(n^2)
 *       Pior caso: O(n^2)
 */
void bubbleSortV4( int *array, int tamanho ) {

    int j;
    int posicaoUltimaTroca;
    int limite = tamanho - 1;

    while ( true ) {

        posicaoUltimaTroca = 0;

        for ( j = 0; j < limite; j++ ) {

            if ( array[j] > array[j+1] ) {
                swap( &array[j], &array[j+1] );
                posicaoUltimaTroca = j;
            }

        }

        if ( posicaoUltimaTroca == 0 ) {
            return;
        }

        limite = posicaoUltimaTroca;

    }

}



/****************************************
 * Algoritmos de ordenação por seleção. *
 ****************************************/

/*
 * Ordenação por seleção.
 *
 * Um elemento é eleito para participar da seleção,
 * onde os elementos à sua direita serão comparados
 * e então trocados se necessário.
 * Nesse algoritmo, um número menor que o eleito é procurado
 * (caso a ordenação seja crescente) ou um maior (caso a
 * a ordenação seja descrescente).
 *
 * Complexidade:
 *     Melhor caso: O(n^2)
 *      Caso médio: O(n^2)
 *       Pior caso: O(n^2)
 */
void selectionSort( int *array, int tamanho ) {

    int i;
    int j;
    int eleito;
    int menor;
    int posicao;

    for ( i = 0; i < tamanho - 1; i++ ) {

        // elege o elemento a ser usado nas comparações
        eleito = array[i];

        // considera o primeiro elemento depois do
        // eleito como o "menor"
        menor = array[i+1];

        // salva a posição desse elemento "menor"
        posicao = i + 1;

        // busca à direita do eleito pelo menor número
        // existente e sua respectiva posição
        for ( j = i+1; j < tamanho; j++ ) {

            // se o elemento atual for menor que menor,
            // salva os dados do valor e da posição
            if ( array[j] < menor ) {
                menor = array[j];
                posicao = j;
            }

        }

        // o menor é menor que o eleito?
        if ( menor < eleito ) {

            // se sim, quer dizer que o eleito deve ficar à
            // direita do menor, fazendo então a troca desses elementos
            swap( &array[i], &array[posicao] );

        }

    }

}



/*****************************************
 * Algoritmos de ordenação por inserção. *
 *****************************************/

/*
 * Ordenação por inserção.
 *
 * Neste algoritmo, a estrutura é iterada n-1 vezes
 * pois o algoritmo inicia no segundo elemento.
 * Ao eleger o número que será comparado, navega-se
 * por todos os elementos à sua esquerda, deslocando
 * os valoresdo array para a direita até que a posição
 * que o eleito deve ser inserido seja encontrada e então
 * receba o eleito.
 *
 * Complexidade:
 *     Melhor caso: O(n)
 *      Caso médio: O(n^2)
 *       Pior caso: O(n^2)
 */
void insertionSort( int *array, int tamanho ) {

    int i;
    int j;
    int eleito;

    // inicia a iteração no segundo elemento do array
    for ( i = 1; i < tamanho; i++ ) {

        eleito = array[i];

        // percorrendo os elementos à esquerda do eleito
        // até encontrar a posição para
        // recolocar o eleito, respeitando a ordenação desejada (crescente)
        for ( j = i-1; j >= 0 && eleito < array[j]; j-- ) {

            // desloca para a direita
            array[j+1] = array[j];

        }

        // a posição de inserção foi encontrada
        // armazena o eleito
        array[j+1] = eleito;

    }

}
