#include <stdio.h>
#include <stdlib.h>

int fat( int n ) {
    if ( n == 0 )
        return 1;
    else
        return n * fat( n - 1 );
}

int mult( int multiplicando, int multiplicador ) {
    if ( multiplicador == 0 )
        return 0;
    else if ( multiplicador == 1 )
        return multiplicando;
    else
        return mult( multiplicando, multiplicador - 1 ) + multiplicando;
}

int fib( int n ) {
    if ( n == 0 || n == 1 )
        return n;
    else
        return fib( n - 2 ) + fib( n - 1 );
}

int main() {

    int i;

    printf( "Fatorial recursivo: \n" );
    for ( i = 0; i < 10; i++ ) {
        printf( "%d! = %d\n", i, fat( i ) );
    }

    printf( "\n" );

    printf( "Multiplicacao recursiva: \n" );
    for ( i = 0; i < 10; i++ ) {
        printf( "5 x %d = %d\n", i, mult( 5, i ) );
    }

    printf( "\n" );

    printf( "Fibonacci recursivo: \n" );
    for ( i = 0; i < 10; i++ ) {
        printf( "fib(%d) = %d\n", i, fib( i ) );
    }

    return 0;

}
