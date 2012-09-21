#include <stdio.h>
#include <stdlib.h>

/*
 * struct an�nima
 * membros a, b e c, do tipo inteiro
 */
struct {
    int a;
    int b;
    int c;
} v1, v2, vn;

/*
 * struct chamada x
 * membros a, b e c, do tipo inteiro
 */
struct x {
    int a;
    int b;
    int c;
};

/*
 * defini��o de tipo (Y) usando uma estrutura (struct y).
 */
typedef struct y {
    int a;
    int b;
    int c;
} Y;

void imprimirX( struct x p ) {
    printf( "%d %d %d\n", p.a, p.b, p.c );
}

void imprimirY( Y p ) {
    printf( "%d %d %d\n", p.a, p.b, p.c );
}

int main() {

    // declara��o de uma vari�vel do tipo struct x e inicializa��o
    struct x x1 = { 1, 2, 3 };

    // declara��o de uma vari�vel do tipo struct x e inicializa��o usando designadores
    struct x x2 = { .a = 3, .b = 4, .c = 5 };

    // declara��o de uma vari�vel do tipo Y (que deriva de uma estrutura) e iniciliza��o
    Y y1 = { 4, 5, 6 };

    // declara��o de uma vari�vel do tipo Y (que deriva de uma estrutura)
    // e inicializa��o usando designadores
    Y y2 = { .a = 6, .b = 5, .c = 4 };

    imprimirX( x1 );
    imprimirX( x2 );
    imprimirY( y1 );
    imprimirY( y2 );

    /*
     * atribui��o de estruturas:
     * somente entre estruturas compat�veis
     * � feita a c�pia dos valores membro a membro
     */
    x2 = x1;
    y2 = y1;

    imprimirX( x1 );
    imprimirX( x2 );
    imprimirY( y1 );
    imprimirY( y2 );

    return 0;

}
