#include <stdio.h>
#include <string.h>

int main() {
    char serial[100];
    int count = 0;

    printf("Enter the serial number: ");
    scanf("%s", serial);

    int length = strlen(serial);

    for (int i = 0; i < length; i++) {
        if (serial[length - 1 - i] - '0' == i + 1) {
            count++;
        }
    }

    printf("The number of matching positions is: %d\n", count);

    return 0;
}


// Input: 321
// Output: 3