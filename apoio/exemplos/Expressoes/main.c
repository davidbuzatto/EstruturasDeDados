#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"


int avaliarInfixadaParentesesExternos( char expr[] ) {

    char c;
    int i;
    int t = strlen( expr );

    char op;
    int op1;
    int op2;
    int res;

    Pilha p;
    iniciar( &p );

    for ( i = 0; i < t; i++ ) {

        c = expr[i];

        if ( c == '(' ) {

            empilhar( &p, c );
            //imprimir( &p );

        } else if ( c >= '0' && c <= '9' ) {

            empilhar( &p, c );
            //imprimir( &p );

        } else if ( c == '+' ||
                    c == '-' ||
                    c == '*' ||
                    c == '/' ) {

            empilhar( &p, c );
            //imprimir( &p );

        } else if ( c == ')' ) {

            op2 = desempilhar( &p ) - '0';
            op = desempilhar( &p );
            op1 = desempilhar( &p ) - '0';
            desempilhar( &p );

            switch ( op ) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
            }

            empilhar( &p, res + '0' );
            //imprimir( &p );

        }

    }

    return desempilhar( &p ) - '0';

}


int avaliarPrefixada( char expr[] ) {

    char c;
    int i;
    int t = strlen( expr );

    char op;
    int op1;
    int op2;
    int res;

    Pilha pc;
    Pilha pi;
    iniciar( &pc );
    iniciar( &pi );

    for ( i = 0; i < t; i++ ) {
        empilhar( &pc, expr[i] );
    }

    while ( !estaVazia( &pc ) ) {

        c = desempilhar( &pc );

        if ( c >= '0' && c <= '9' ) {

            empilhar( &pi, c );

        } else if ( c == '+' ||
                    c == '-' ||
                    c == '*' ||
                    c == '/' ) {
            op = c;
            op1 = desempilhar( &pi ) - '0';
            op2 = desempilhar( &pi ) - '0';

            switch ( op ) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
            }

            empilhar( &pi, res + '0' );
        }

    }

    return desempilhar( &pi ) - '0';

}


int avaliarPosfixada( char expr[] ) {

    char c;
    int i;
    int t = strlen( expr );

    char op;
    int op1;
    int op2;
    int res;

    Pilha p;
    iniciar( &p );

    for ( i = 0; i < t; i++ ) {

        c = expr[i];

        if ( c >= '0' && c <= '9' ) {

            empilhar( &p, c );

        } else if ( c == '+' ||
                    c == '-' ||
                    c == '*' ||
                    c == '/' ) {

            op = c;
            op1 = desempilhar( &p ) - '0';
            op2 = desempilhar( &p ) - '0';

            switch ( op ) {
                case '+':
                    res = op1 + op2;
                    break;
                case '-':
                    res = op1 - op2;
                    break;
                case '*':
                    res = op1 * op2;
                    break;
                case '/':
                    res = op1 / op2;
                    break;
            }

            empilhar( &p, res + '0' );

        }

    }

    return desempilhar( &p ) - '0';

}


void infixadaParaPosfixada( char expr[], char *posExpr ) {

    char c;
    int i;
    int t = strlen( expr );
    int cont = 0;

    Pilha p;
    iniciar( &p );

    for ( i = 0; i < t; i++ ) {

        c = expr[i];

        if ( c == '(' ) {

            empilhar( &p, c );

        } else if ( c >= '0' && c <= '9' ) {

            posExpr[cont++] = c;

        } else if ( c == '+' ||
                    c == '-' ||
                    c == '*' ||
                    c == '/' ) {

            empilhar( &p, c );

        } else if ( c == ')' ) {

            c = desempilhar( &p );

            while ( c != '(' ) {
                posExpr[cont++] = c;
                c = desempilhar( &p );
            }

        }

    }

    posExpr[cont] = '\0';

}

int main() {

    int r1 = avaliarInfixadaParentesesExternos( "(((2 * 5) - (1 * 2)) / (1 - 9))" );
    int r2 = avaliarPrefixada( "/ - * 2 5 * 1 2 - 1 9" );
    int r3 = avaliarPosfixada( "1 2 4 * + 3 +" );
    char posExpr[50];
    infixadaParaPosfixada( "(((8 + 1) - (7 - 4)) / (1 - 9))", posExpr );

    printf( "%d\n", r1 );
    printf( "%d\n", r2 );
    printf( "%d\n", r3 );
    printf( "%s\n", posExpr );

    return 0;
}
