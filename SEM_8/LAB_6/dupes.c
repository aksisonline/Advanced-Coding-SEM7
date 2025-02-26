// given an array of elements, remove duplicate elements from the given array

#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n <= 1) return n;
    
    int uniqueCount = 0;
    
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        
        if (!isDuplicate) {
            arr[uniqueCount] = arr[i];
            uniqueCount++;
        }
    }
    
    return uniqueCount;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    int newSize = removeDuplicates(arr, n);
    
    printf("\nArray after removing duplicates: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}