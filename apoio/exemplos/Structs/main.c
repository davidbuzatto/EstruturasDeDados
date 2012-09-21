#include <stdio.h>
#include <stdlib.h>

/*
 * struct anônima
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
 * definição de tipo (Y) usando uma estrutura (struct y).
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

    // declaração de uma variável do tipo struct x e inicialização
    struct x x1 = { 1, 2, 3 };

    // declaração de uma variável do tipo struct x e inicialização usando designadores
    struct x x2 = { .a = 3, .b = 4, .c = 5 };

    // declaração de uma variável do tipo Y (que deriva de uma estrutura) e inicilização
    Y y1 = { 4, 5, 6 };

    // declaração de uma variável do tipo Y (que deriva de uma estrutura)
    // e inicialização usando designadores
    Y y2 = { .a = 6, .b = 5, .c = 4 };

    imprimirX( x1 );
    imprimirX( x2 );
    imprimirY( y1 );
    imprimirY( y2 );

    /*
     * atribuição de estruturas:
     * somente entre estruturas compatíveis
     * é feita a cópia dos valores membro a membro
     */
    x2 = x1;
    y2 = y1;

    imprimirX( x1 );
    imprimirX( x2 );
    imprimirY( y1 );
    imprimirY( y2 );

    return 0;

}
