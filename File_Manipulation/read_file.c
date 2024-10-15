#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char *filename = "example.txt";
    char ch;

    printf("\n\n\n");

    file = fopen(filename, "r");

    // fgetc() - Per character
    printf("Reading file using fgetc():\n");
    ch = fgetc(file);
    printf("%c", ch); 

    
    rewind(file);

    // fgets() - Per line
    printf("\n\nReading file using fgets():\n");
    char buffer[100];
    fgets(buffer, sizeof(buffer), file);
    printf("%s", buffer);
    rewind(file);

    // fscanf() - Per word + formatting
    printf("\n\nReading file using fscanf():\n");
    char word[100];
    if (fscanf(file, "%100s", word) == 1) {
        printf("%s", word);
    }

    rewind(file);

    // fscanf() - Per line + formatting for whole sentence
    printf("\n\nReading file using fscanf() for whole sentence:\n");
    char sentence[16];
    if (fgets(sentence, sizeof(sentence), file) != NULL) {
        printf("%s", sentence);
    }

    printf("\n\n\n");

    fclose(file);
    return 0;
}