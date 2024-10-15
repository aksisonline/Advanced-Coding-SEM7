#include <stdio.h>

int main() {
    FILE *file;
    long position;

    // Open a file in read mode
    file = fopen("example.txt", "r");

    position = ftell(file);
    printf("Position: %ld\n", position);

    // Move the file pointer to the end of the file
    fseek(file, 0, SEEK_END);

    position = ftell(file);
    printf("Position: %ld\n", position);

    // Move the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    position = ftell(file);
    printf("Position: %ld\n", position);

    // Move the file pointer to the current position plus an offset
    fseek(file, 8, SEEK_CUR);

    position = ftell(file);
    printf("Position: %ld\n", position);

    rewind(file);

    position = ftell(file);
    printf("Position: %ld\n", position);

    fclose(file);

    return 0;
}