#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

void imprimir( Data *d ) {

    // d->dia   =>   (*d).dia, ou seja, o operador -> é um atalho
    printf( "%.2d/%.2d/%.4d\n", d->dia, d->mes, (*d).ano );

    // pode-se usar uma expressão com -> para receber valor, por exemplo
    // d->dia = 25; (o membro dia da estrutura apontada por d recebe o valor 25)

}

int main() {

    Data d = { .dia = 10, .mes = 11, .ano = 2012 };
    imprimir( &d );

    return 0;

}
