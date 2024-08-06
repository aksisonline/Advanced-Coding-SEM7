#include <stdio.h>
#include <string.h>

void reverseWords(char* str) {
    int end = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        if (str[i] == ',' || str[i] == '.' || str[i] == '\n')
        {
            str[i] = ' ';
        }
        str[end++] = str[i];
    }
    str[end] = '\0'; 

    // Reverse the characters of each word in the string
    char* word = strtok(str, " ");
    char* words[1000];
    int count = 0;

    while (word != NULL) {
        int wordLength = strlen(word);
        for (int i = 0, j = wordLength - 1; i < j; i++, j--) {
            char temp = word[i];
            word[i] = word[j];
            word[j] = temp;
        }
        words[count++] = word;
        word = strtok(NULL, " ");
    }

    for (int i = 0; i < count; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

int main()
{
    char str[1000];
    printf("Enter a long string: ");
    fgets(str, sizeof(str), stdin);

    printf("Reversed words: ");
    reverseWords(str);

    return 0;
}