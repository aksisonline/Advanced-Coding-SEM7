// 1. Given a string s representing characters typed into an editor, with "<-" representing a backspace, return the current state of the editor.
// Input

//     s = "abc<-z"

//     Output

//         "abz"

#include <stdio.h>

int main(){
    char str[100];
    scanf("%s", str);
    int i = 0;
    int j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '<')
        {
            if (j > 0) {
                j--;
            }
            i++; 
        }
        else
        {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
    printf("%s\n", str);
    return 0;
}