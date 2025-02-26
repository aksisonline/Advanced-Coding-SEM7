# Lab 6: C Programming Tasks

## Program 1: Finding Longest Palindromic Substring

```c
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
```

### Output
```
Enter a string: racecar
Longest palindromic substring is: racecar

Enter a string: banana
Longest palindromic substring is: anana

Enter a string: programming
Longest palindromic substring is: mm
```

## Program 2: Removing Duplicate Elements from an Array


```c
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
```

### Output
```
Enter the number of elements: 8
Enter the elements: 1 2 3 2 4 3 5 6
Original array: 1 2 3 2 4 3 5 6
Array after removing duplicates: 1 2 3 4 5 6

Enter the number of elements: 5
Enter the elements: 10 10 20 20 30
Original array: 10 10 20 20 30
Array after removing duplicates: 10 20 30
```

## Program 3: Binary Search in Sorted Array

```c
// Given a sorted array of distinct elements and a target value, display the index of the target value if the target is found, if not, display the index where it should be inserted in order. Using Binary Search

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchInsert(int nums[], int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    int numsSize;
    
    printf("Enter the size of the array: ");
    scanf("%d", &numsSize);
    
    int nums[numsSize];
    printf("Enter the sorted array elements:\n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    
    int target;
    printf("Enter the target value: ");
    scanf("%d", &target);
    
    int result = searchInsert(nums, numsSize, target);
    
    if (result < numsSize && nums[result] == target) {
        printf("Target %d found at index: %d\n", target, result);
    } else {
        printf("Target %d not found. It should be inserted at index: %d\n", target, result);
    }
    
    return 0;
}
```

### Output
```
Enter the size of the array: 4
Enter the sorted array elements:
1 3 5 7
Enter the target value: 5
Target 5 found at index: 2

Enter the size of the array: 4
Enter the sorted array elements:
1 3 5 7
Enter the target value: 2
Target 2 not found. It should be inserted at index: 1

Enter the size of the array: 4
Enter the sorted array elements:
1 3 5 7
Enter the target value: 8
Target 8 not found. It should be inserted at index: 4
