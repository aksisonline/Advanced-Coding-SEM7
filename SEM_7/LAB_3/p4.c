// Single occurrence of a number: Given an array of integers which all numbers but one occurring twice, find the number that occurs only once.

#include <stdio.h>

int findSingleNumber(int arr[], int n)
{
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result ^= arr[i];
    }
    return result;
}

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int singleNumber = findSingleNumber(arr, n);
    printf("The number that occurs only once is: %d\n", singleNumber);
    return 0;
}