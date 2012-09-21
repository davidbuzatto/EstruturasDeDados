#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main() {

    Deque d;
    iniciar( &d );

    inserirInicio( &d, 3 );
    inserirInicio( &d, 4 );
    inserirInicio( &d, 5 );
    imprimir( &d );

    inserirFim( &d, 9 );
    inserirFim( &d, 8 );
    inserirFim( &d, 6 );
    imprimir( &d );

    printf( "\nRemov. Ini: %d\n", removerInicio( &d ) );
    imprimir( &d );
    printf( "\nRemov. Ini: %d\n", removerInicio( &d ) );
    imprimir( &d );

    printf( "\nRemov. Fim: %d\n", removerFim( &d ) );
    imprimir( &d );
    printf( "\nRemov. Fim: %d\n", removerFim( &d ) );
    imprimir( &d );

    printf( "\nCons. Ini: %d\n", consultarInicio( &d ) );
    imprimir( &d );
    printf( "\nCons. Fim: %d\n", consultarFim( &d ) );
    imprimir( &d );

    printf( "\nA deque esta vazia? " );
    printf( estaVazia( &d ) ? "Sim" : "Nao" );

    esvaziar( &d );

    printf( "\nA deque esta vazia? " );
    printf( estaVazia( &d ) ? "Sim" : "Nao" );

    printf( "\n" );

    return 0;

}
