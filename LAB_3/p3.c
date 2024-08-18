// Maximum value subarray: Given an array of integers arr, return the maximum sum of a subarray (with contiguous elements) of that array.

#include <stdio.h>

int maxSubarraySum(int arr[], int size)
{
    int maxSum = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (currentSum < 0)
        {
            currentSum = arr[i];
        }
        else
        {
            currentSum += arr[i];
        }

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int _3LAB3()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxSum = maxSubarraySum(arr, n);
    printf("Maximum sum of a subarray: %d\n", maxSum);

    return 0;
}