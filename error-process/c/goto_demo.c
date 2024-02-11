#include <stdio.h>

int main() {
    int x = 5;

    if (x > 0) {
        printf("x is positive\n");
        goto cleanup;
        printf("continue\n");
    }

    printf("x is non-positive\n");

cleanup:
    printf("Cleaning up...\n");
    //return 0;

    printf("goto process test...\n");
}