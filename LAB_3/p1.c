// Is substring: Given two strings str1 and str2, write a program to return true if str2 is a substring of str1 and false otherwise.

#include <stdio.h>
#include <string.h>

int isSubstring(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    for (int i = 0; i <= len1 - len2; i++)
    {
        int j;
        for (j = 0; j < len2; j++)
        {
            if (str1[i + j] != str2[j])
                break;
        }
        if (j == len2)
            return 1;
    }
    return 0;
}

int main()
{
    char str1[10], str2[10];

    scanf("%s", str1);
    scanf("%s", str2);

    printf("%s", isSubstring(str1, str2) ? "True" : "False");

    return 0;
}