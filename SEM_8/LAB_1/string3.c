// 3. Write a function to find the longest common prefix string amongst an array of strings.If there is no common prefix, return an empty string "".
// Example 1 : Input : strs = [ "flower", "flow", "flight" ]
// Output : "fl"


#include <stdio.h>
#include <string.h>

char* prefixes(char arr[][100], int n) {
    if (n == 0) return "";
    char* prefix = arr[0];
    for (int i = 1; i < n; i++) {
        int j = 0;
        while (prefix[j] && arr[i][j] && prefix[j] == arr[i][j]) {
            j++;
        }
        prefix[j] = '\0';
    }
    return prefix;
}

int main(){
    int n;
    scanf("%d", &n);
    char arr[n][100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    char* result = prefixes(arr, n);
    printf("%s\n", result);
}