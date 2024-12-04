#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;

    // Using fputc() to write a single character
    // file = fopen("output_fputc.txt", "w");
    // fputc('A', file);
    // fclose(file);
    
    // Using fputs() to write a string
    file = fopen("output_fputs.txt", "w");
    fputs("Hello, World!", file);
    fclose(file);

    // Using fprintf() to write formatted output
    // file = fopen("output_fprintf.txt", "w");
    // fprintf(file, "Name: %s, Age: %d\n", "John Doe", 30);
    // fclose(file);

    //try to print file contents in w mode
    // file = fopen("output_fputc.txt", "w");
    // char ch[10];
    // fgets(ch, sizeof(ch), file);
    // printf("%s", ch);
    // fclose(file);


    return 0;
}