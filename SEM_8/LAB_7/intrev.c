#include <stdio.h>
#include <string.h>

int main() {
    char str[1000], digits[1000];
    int count = 0;
    
    printf("Enter a string: ");
    scanf("%999s", str);  
    
    // Extract all digits
    for (int i = 0; str[i]; i++)
        if (str[i] >= '0' && str[i] <= '9')
            digits[count++] = str[i];
    
    // Replace digits in reverse order
    for (int i = 0; str[i]; i++)
        if (str[i] >= '0' && str[i] <= '9')
            str[i] = digits[--count];
    
    printf("Result: %s\n", str);
    return 0;
}
