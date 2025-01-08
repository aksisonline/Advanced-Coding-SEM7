#include <stdio.h>
#include <stdlib.h>

int partition(int* nums, int left, int right) {
    int pivot = nums[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (nums[j] >= pivot) {
            i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    int temp = nums[i + 1];
    nums[i + 1] = nums[right];
    nums[right] = temp;
    return i + 1;
}

int quickSelect(int* nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];
    }

    int pivotIndex = partition(nums, left, right);

    if (k == pivotIndex) {
        return nums[k];
    } else if (k < pivotIndex) {
        return quickSelect(nums, left, pivotIndex - 1, k);
    } else {
        return quickSelect(nums, pivotIndex + 1, right, k);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums, 0, numsSize - 1, k - 1);
}

int main() {
    int nums1[] = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    printf("The %dth largest element is %d\n", k1, findKthLargest(nums1, 6, k1));

    int nums2[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    printf("The %dth largest element is %d\n", k2, findKthLargest(nums2, 9, k2));

    return 0;
}
