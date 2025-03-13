#include <stdio.h>
#include <stdlib.h>

    int main () {
        printf ("RAND_MAX = %d\n", RAND_MAX);
        printf("Aleatorio = %d\n", rand() % 1000 +1);
        return 0;
    }
