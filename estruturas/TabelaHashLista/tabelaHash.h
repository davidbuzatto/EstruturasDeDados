#ifndef TABELAHASH_H
#define TABELAHASH_H

#include <stdbool.h>

#define TAM_MAX_HASH 10

typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct tabelaHash {
    No *valores[TAM_MAX_HASH];
} TabelaHash;


/*
    Função de dispersão.
 */
int hash( int valor );

/*
    Função para criar um novo nó.
 */
No* novoNo( int valor );

/*
    Inicia uma tabela hash.
 */
void iniciar( TabelaHash *tabelaHash );

/*
    Insere um valor em uma tabela hash.
 */
void inserir( TabelaHash *tabelaHash, int valor );

/*
    Busca um valor em uma tabela hash.
 */
bool buscar( TabelaHash *tabelaHash, int valor );

/*
    Remove um valor de uma tabela hash.
 */
bool remover( TabelaHash *tabelaHash, int valor );

/*
    Imprime uma tabela hash.
 */
void imprimir( TabelaHash *tabelaHash );

#endif // TABELAHASH_H
