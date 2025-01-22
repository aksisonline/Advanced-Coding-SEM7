#include <stdio.h>


int isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if(sum == n) return 1; else return 0;
}

int countPerfects(int start, int end) {
    int count = 0;
    for (int i = start; i <= end; i++) {
        if (isPerfect(i)) {
            printf("%d\t", i);
            count++;
        }
    }
    return count;
}

int main() {
    int start, end;
    printf("Enter the range: ");
    scanf("%d %d", &start, &end);
    printf("Total number of perfect numbers in the given range: %d\n", countPerfects(start, end));
    return 0;
}