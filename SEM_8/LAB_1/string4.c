// 4.	Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once. 
// Example 1:
// Input: s = "hello"
// Output: "holle"

#include <stdio.h>

int isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main(){
    char str[100];
    scanf("%s", str);
    int i = 0;
    int j = 0;
    while (str[i] != '\0')
    {
        if (isVowel(str[i]))
        {
            j++;
        }
        i++;
    }
    char vowels[j];
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (isVowel(str[i]))
        {
            vowels[j] = str[i];
            j++;
        }
        i++;
    }
    j--;
    i = 0;
    while (str[i] != '\0')
    {
        if (isVowel(str[i]))
        {
            str[i] = vowels[j];
            j--;
        }
        i++;
    }
    printf("%s\n", str);
    return 0;
}
