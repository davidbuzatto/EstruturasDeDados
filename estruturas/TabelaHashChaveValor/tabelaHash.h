#ifndef TABELAHASH_H
#define TABELAHASH_H

#include <stdbool.h>

#define TAM_MAX_HASH 10

typedef struct no {
    char chave[40];
    int valor;
    struct no *proximo;
} No;

typedef struct tabelaHash {
    No *valores[TAM_MAX_HASH];
} TabelaHash;


/*
    Fun��o de dispers�o.
 */
int hash( char *chave );

/*
    Fun��o para criar um novo n�.
 */
No* novoNo( char *chave, int valor );

/*
    Inicia uma tabela hash.
 */
void iniciar( TabelaHash *tabelaHash );

/*
    Insere um valor em uma tabela hash.
 */
void inserir( TabelaHash *tabelaHash, char *chave, int valor );

/*
    Busca um valor em uma tabela hash.
    Retorna NULL caso n�o encontre ou o n� com o valor caso encontre.
 */
No *buscar( TabelaHash *tabelaHash, char *chave );

/*
    Remove um valor de uma tabela hash.
 */
bool remover( TabelaHash *tabelaHash, char *chave );

/*
    Imprime uma tabela hash.
 */
void imprimir( TabelaHash *tabelaHash );

#endif // TABELAHASH_H
