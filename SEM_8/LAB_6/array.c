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