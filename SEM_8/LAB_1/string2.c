// Given a string, the task is to reverse the order of the words in the given string. 
// Input: s = “i love programming very much” 
// Output: s = “much very programming love i”

#include<stdio.h>

int main(){
    char str[100];
    scanf("%[^\n]s", str);
    
    int i, j, start, end, len;
    char temp;

    for (len = 0; str[len] != '\0'; len++);

    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    start = end = 0;
    while (end <= len) {
        if (str[end] == ' ' || str[end] == '\0') {
            for (i = start, j = end - 1; i < j; i++, j--) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
            start = end + 1;
        }
        end++;
    }

    printf("%s\n", str);
}