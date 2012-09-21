#include <stdio.h>
#include <stdlib.h>

int main() {

    char expr[] = "1+2";
    int i = 0;
    char c;

    while ( ( c = expr[i++] ) != '\0' ) {
        printf( "%c", c );
    }

    return 0;

}
