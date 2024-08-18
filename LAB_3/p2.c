//Is subsequence: Given two strings str1 and str2, write a program to return true if str2 is a subsequence of str1 and false otherwise.

#include <stdio.h>
#include <string.h>

int isSubsequence(char *str1, char *str2)
{
    int count = 0, temp = 0;
    for (int i = 0; i < strlen(str1); i++)
    {
        for (int j = temp; j < strlen(str2); j++)
        {
            if (str1[i] == str2[j])
            {
                count++;
                temp = j + 1;
                break;
            }
        }
    }
    if (count == strlen(str2))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int _2LAB3()
{
    char str1[10], str2[10];

    scanf("%s", str1);
    scanf("%s", str2);

    printf("%s", isSubsequence(str1, str2) ? "True" : "False");

    return 0;
}
