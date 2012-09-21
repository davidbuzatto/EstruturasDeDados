#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "ordenacao.h"
#include "arvoreBinariaBuscaOrdenacao.h"



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

/*
 * Ordenação usando Heap.
 *
 * Usa um heap para fazer a ordenação. O heap nada mais é
 * que uma árvore binária de busca organizada em um array.
 *
 * Complexidade:
 *     Melhor caso: O(n log n)
 *      Caso médio: O(n log n)
 *       Pior caso: O(n log n)
 */
void heapSort( int *array, int tamanho ) {

    gerarHeap( array, tamanho );
    ordenarHeapSort( array, tamanho );

}

void gerarHeap( int *array, int tamanho ) {

    int i;

    for ( i = tamanho / 2; i >= 1; i-- ) {
        heapfy( array, i, tamanho );
    }

}

void ordenarHeapSort( int *array, int tamanho ) {

    int i;

    for ( i = tamanho; i >= 2; i-- ) {
        swap( &array[1], &array[i] );
        heapfy( array, 1, i - 1 );
    }

}

void heapfy( int *array, int raiz, int tamanho ) {

    int maior = raiz;
    int filhoEsquerda = 2 * raiz + 1;
    int filhoDireita = 2 * raiz;

    if ( filhoEsquerda <= tamanho ) {

        // o nó que está sendo analisado
        // tem filhos para a esquerda e direita
        if ( array[filhoEsquerda] >= array[filhoDireita] &&
             array[filhoEsquerda] > array[raiz] ) {

            maior = filhoEsquerda;

        } else if ( array[filhoDireita] > array[filhoEsquerda] &&
                    array[filhoDireita] > array[raiz] ) {

            maior = filhoDireita;

        }

    } else if ( filhoDireita <= tamanho ) {

        // o nó que está sendo analizado
        // tem filho apenas para a direita
        if ( array[filhoDireita] > array[raiz] ) {
            maior = filhoDireita;
        }

    }

    if ( maior != raiz ) {

        swap( &array[raiz], &array[maior] );
        heapfy( array, maior, tamanho );

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

/*
 * Ordenação shell.
 *
 * Compara elementos usando uma sequência de intervalos, finalizando
 * com um intervalo igual a 1. A primeira versão deste algoritmo
 * foi publicada por Donald Shell em 1959. O tempo de execução
 * do mesmo depende da sequência de intervalos utilizada.
 * Para verificar as sequências, veja:
 * http://en.wikipedia.org/wiki/Shell_sort
 *
 * Complexidade:
 *     Melhor caso: O(n)
 *      Caso médio: O(n(log n)^2) ou O(n^(3/2))
 *       Pior caso: O(n(log n)^2)
 */
void shellSort( int *array, int tamanho ) {

    // sequência de intervalos de Marcin Ciura
    int intervalos[] = { 701, 301, 132, 57, 23, 10, 4, 1 };
    int nIntervalos = 8;
    int intervalo = 0;

    int i;
    int j;
    int k;
    int temp;

    for ( k = 0; k < nIntervalos; k++ ) {

        intervalo = intervalos[k];

        for ( i = intervalo; i < tamanho; i++ ) {

            temp = array[i];

            for ( j = i;
                  j >= intervalo && array[j - intervalo] > temp;
                  j -= intervalo ) {

                array[j] = array[j - intervalo];

            }

            array[j] = temp;


            /* ou...
            for ( j = i - intervalo;
                  j >= 0 && temp < array[j];
                  j -= intervalo ) {

                array[j + intervalo] = array[j];

            }

            array[j + intervalo] = temp;*/


        }
    }

}


 /*
 * Ordenação usando árvore binária de busca.
 *
 * Neste algoritmo é usada uma árvore binária de busca,
 * onde os elementos do array a ser ordenado são inseridos um
 * a um. Após a inserção, a árvore é percorrida em ordem e cada
 * raiz visitada é inserida de volta no array do início ao fim.
 *
 * Complexidade:
 *     Melhor caso: O(n)
 *      Caso médio: O(n log n)
 *       Pior caso: O(n log n)
 */
void binaryTreeSort( int *array, int tamanho ) {

    int i;

    ArvoreBinariaBusca a;
    iniciar( &a );

    for ( i = 0; i < tamanho; i++ ) {
        inserir( &a, array[i] );
    }

    int indice = 0;
    percorrerEmOrdemInserindo( a.raiz, array, &indice );
    esvaziar( &a );

}



/*****************************************************
 * Algoritmos de ordenação por merge (intercalação). *
 *****************************************************/

/*
 * Ordenação por intercalação.
 *
 * Neste algoritmo, o array é particionado em duas partes
 * e a ordenação é feita intercalando os elementos das partes
 * criadas. O particionamento é feito de forma recursiva.
 *
 * Complexidade:
 *     Melhor caso: O(n log n)
 *      Caso médio: O(n log n)
 *       Pior caso: O(n log n)
 */
void mergeSort( int *array, int tamanho ) {
    mergeSortR( array, 0, tamanho - 1 );
}

/*
 * Função recursiva do mergeSort.
 */
void mergeSortR( int *array, int inicio, int fim ) {

    int meio;

    if ( inicio < fim ) {

        meio = ( inicio + fim ) / 2;
        mergeSortR( array, inicio, meio );
        mergeSortR( array, meio + 1, fim );
        intercalar( array, inicio, meio, fim );

    }

}

/*
 * Algoritmo de intercalação do método de ordenação mergeSort.
 */
void intercalar( int *array, int inicio, int meio, int fim ) {

    int i;

    int inicioParte1 = inicio;
    int inicioParte2 = meio + 1;
    int posLivre = inicio;

    // aloca um array temporário
    int *temp = ( int* ) malloc( sizeof( int ) * ( inicio + fim + 1 ) );

    // intercalando...
    while ( inicioParte1 <= meio && inicioParte2 <= fim ) {

        if ( array[inicioParte1] <= array[inicioParte2] ) {
            temp[posLivre++] = array[inicioParte1++];
        } else {
            temp[posLivre++] = array[inicioParte2++];
        }

    }

    // se ainda existem números no primeiro array
    // que não foram intercalados...
    for ( i = inicioParte1; i <= meio; i++ ) {
        temp[posLivre++] = array[i];
    }

    // se ainda existem números no segundo array
    // que não foram intercalados...
    for ( i = inicioParte2; i <= fim; i++ ) {
        temp[posLivre++] = array[i];
    }

    // retorna os valores do array temporário para o array original
    for ( i = inicio; i <= fim; i++ ) {
        array[i] = temp[i];
    }

    // libera o array temporário
    free( temp );

}



/************************************************
 * Algoritmos de ordenação por particionamento. *
 ************************************************/

/*
 * Ordenação rápida.
 *
 * Neste algoritmo, o array é particionado em duas partes
 * e a ordenação é feita chamando-se recursivamente a
 * função de ordenação.
 *
 * Complexidade:
 *     Melhor caso: O(n log n)
 *      Caso médio: O(n log n)
 *       Pior caso: O(n^2)
 */
void quickSort( int *array, int tamanho ) {
    quickSortR( array, 0, tamanho - 1 );
}

/*
 * Função recursiva do quickSort.
 */
void quickSortR( int* array, int inicio, int fim ) {

    int meio;

    if ( inicio < fim ) {
        meio = particionar( array, inicio, fim );
        quickSortR( array, inicio, meio );
        quickSortR( array, meio + 1, fim );
    }

}

/*
 * Algoritmo de particionamento.
 */
int particionar( int* array, int inicio, int fim ) {

    int i = inicio - 1;
    int j = fim + 1;
    int pivo = array[ ( inicio + fim ) / 2 ]; // elemento do meio

    while ( i < j ) {

        do {
            j--;
        } while ( array[j] > pivo );

        do {
            i++;
        } while ( array[i] < pivo );

        if ( i < j ) {
            swap( &array[i], &array[j] );
        }

    }

    return j;

}
