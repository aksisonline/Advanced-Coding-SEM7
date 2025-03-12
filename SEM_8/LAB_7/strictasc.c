#include <stdio.h>
#include <stdbool.h>

bool hasStrictlyAscendingDigits(int num) {
    int prevDigit = 10; 
    while (num > 0) {
        int currentDigit = num % 10;
        if (currentDigit >= prevDigit) {
            return false;
        }
        prevDigit = currentDigit;
        num /= 10;
    }
    return true;
}

int main() {
    int arr[] = {123, 321, 456, 654, 789, 987, 135, 531};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;
    int largest = -1;

    for (int i = 0; i < n; i++) {
        if (hasStrictlyAscendingDigits(arr[i])) {
            count++;
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }
    }

    printf("Count of numbers with strictly ascending digits: %d\n", count);
    if (largest != -1) {
        printf("Largest number with strictly ascending digits: %d\n", largest);
    } else {
        printf("No numbers with strictly ascending digits found.\n");
    }

    return 0;
}