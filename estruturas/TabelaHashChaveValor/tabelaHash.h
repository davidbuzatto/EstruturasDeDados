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
    Função de dispersão.
 */
int hash( char *chave );

/*
    Função para criar um novo nó.
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
    Retorna NULL caso não encontre ou o nó com o valor caso encontre.
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
