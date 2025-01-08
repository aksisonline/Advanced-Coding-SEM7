#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    file = fopen("example.txt", "r");

    fclose(file);
    return 0;
}