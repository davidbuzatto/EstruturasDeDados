#include <stdio.h>
#include <stdlib.h>

void max_min( int a[], int n, int *max, int *min ) {

    int i;
    *max = a[0];
    *min = a[0];

    for ( i = 0; i < n; i++ ) {
        if ( *max < a[i] ) {
            *max = a[i];
        }
        if ( *min > a[i] ) {
            *min = a[i];
        }
    }

}

int main() {

    int numero;

    // ponteiro para inteiro
    int *ponteiro;

    numero = 4;

    // inicializando um ponteiro
    // & => operador de endereço
    ponteiro = &numero;

    printf( "                valor numero: %d\n", numero );
    printf( "             endereco numero: %d\n", &numero );
    printf( "              valor ponteiro: %d\n", ponteiro );
    printf( "valor apontado pelo ponteiro: %d\n\n", *ponteiro );

    // * => operador de indireção ou desreferência ou dereferência
    /*
     * o operador de indireção pode ser usado tanto para obter o valor
     * da variável apontada pelo ponteiro quanto para alterar o valor
     * da variável apontada pelo ponteiro
     */
    *ponteiro = 10;

    printf( "                valor numero: %d\n", numero );
    printf( "             endereco numero: %d\n", &numero );
    printf( "              valor ponteiro: %d\n", ponteiro );
    printf( "valor apontado pelo ponteiro: %d\n\n", *ponteiro );


    int a[] = { -1, 9, 4, 6, 2, -71 };
    int max;
    int min;
    max_min( a, 6, &max, &min );
    printf( "maximo: %d\n", max );
    printf( "minimo: %d\n\n", min );

    // aritmética de ponteiros
    int b[] = { 3, 4, 5, 6 };
    int *pb;
    pb = b; // mesma coisa que pb = &b[0]

    printf( "b[0]: %d\n", b[0] );
    printf( " *pb: %d\n", *pb );

    pb++;

    printf( "b[1]: %d\n", b[1] );
    printf( " *pb: %d\n", *pb );

    printf( "b[2]: %d\n", b[2] );
    printf( " *pb: %d\n\n", *(++pb) );

    for ( pb = b; pb < &b[4]; pb++ ) {
        printf( "%d ", *pb );
    }

    return 0;
}
