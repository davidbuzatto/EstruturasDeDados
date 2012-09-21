#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arvoreBinariaBusca.h"


int main() {

    int i;

    ArvoreBinariaBusca arvore;
    iniciar( &arvore );

    inserir( &arvore, 6 );
    inserir( &arvore, 4 );
    inserir( &arvore, 5 );
    inserir( &arvore, 3 );
    inserir( &arvore, 8 );
    inserir( &arvore, 7 );
    inserir( &arvore, 9 );

    /*inserir( &arvore, 6 );
    inserir( &arvore, 2 );
    inserir( &arvore, 1 );
    inserir( &arvore, 4 );
    inserir( &arvore, 3 );
    inserir( &arvore, 8 );*/

    /*inserir( &arvore, 2 );
    inserir( &arvore, 2 );
    inserir( &arvore, 2 );
    inserir( &arvore, 2 );
    inserir( &arvore, 2 );
    inserir( &arvore, 2 );*/

    for ( i = 0; i < 20; i++ ) {
        printf( "Contem o %d? %s\n", i, contem( &arvore, i ) ? "Sim" : "Nao" );
    }

    printf( "Percursos:\n" );
    printf( "Pre-ordem: " );
    percorrer( &arvore, PRE_ORDEM );

    printf( "Em ordem: " );
    percorrer( &arvore, EM_ORDEM );

    printf( "Pos-ordem: " );
    percorrer( &arvore, POS_ORDEM );

    printf( "Pre-ordem inversa: " );
    percorrer( &arvore, PRE_ORDEM_INV );

    printf( "Em ordem inversa: " );
    percorrer( &arvore, EM_ORDEM_INV );

    printf( "Pos-ordem inversa: " );
    percorrer( &arvore, POS_ORDEM_INV );



    int aRemover[] = { 6, 7, 2, 4, 5, 8, 9, 3, 1, 3 };

    for ( i = 0; i < 10; i++ ) {
        printf( "\nRemoveu o %d? %s\n", aRemover[i], remover( &arvore, aRemover[i] ) ? "Sim" : "Nao" );
        printf( "Pre-ordem: " );
        percorrer( &arvore, PRE_ORDEM );
        printf( "Em ordem: " );
        percorrer( &arvore, EM_ORDEM );
        printf( "Pos-ordem: " );
        percorrer( &arvore, POS_ORDEM );
    }




    inserir( &arvore, 5 );
    inserir( &arvore, 2 );
    inserir( &arvore, 3 );
    inserir( &arvore, 7 );
    printf( "\n\nNova arvore:\n" );
    printf( "Pre-ordem: " );
    percorrer( &arvore, PRE_ORDEM );
    printf( "Em ordem: " );
    percorrer( &arvore, EM_ORDEM );
    printf( "Pos-ordem: " );
    percorrer( &arvore, POS_ORDEM );

    printf( "\nA arvore esta vazia? %s\n", estaVazia( &arvore ) ? "Sim" : "Nao" );
    esvaziar( &arvore );
    printf( "A arvore esta vazia? %s\n", estaVazia( &arvore ) ? "Sim" : "Nao" );

    return 0;

}
