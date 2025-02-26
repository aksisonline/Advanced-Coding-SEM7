// given a string S, display the longest palindrom substring in S

#include <stdio.h>
#include <string.h>

// Function to expand around center to find palindrome
void expandAroundCenter(char *str, int left, int right, int *start, int *maxLength) {
    int len = strlen(str);
    
    while (left >= 0 && right < len && str[left] == str[right]) {
        left--;
        right++;
    }
    
    int currentLength = right - left - 1;
    if (currentLength > *maxLength) {
        *maxLength = currentLength;
        *start = left + 1;
    }
}

// Function to find the longest palindromic substring
void findLongestPalindrome(char *str) {
    int len = strlen(str);
    if (len == 0) {
        printf("The string is empty.\n");
        return;
    }
    
    int start = 0;
    int maxLength = 1;
    
    for (int i = 0; i < len; i++) {
        // For odd length palindromes
        expandAroundCenter(str, i, i, &start, &maxLength);
        // For even length palindromes
        expandAroundCenter(str, i, i + 1, &start, &maxLength);
    }
    
    printf("Longest palindromic substring is: ");
    for (int i = start; i < start + maxLength; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    findLongestPalindrome(str);
    
    return 0;
}