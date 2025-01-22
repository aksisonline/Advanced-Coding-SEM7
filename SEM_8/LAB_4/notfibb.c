#include <stdio.h>

int main() {
    int ia;
    int ib;
    printf("Enter a:");
    scanf("%d", &ia);
    printf("\nEnter b:");
    scanf("%d", &ib);

    int FibCount = 0;

    int a = 0;
    int b = 1;
    int c = a + b;
    printf("Fibbs between a and b:\n");
    do
    {
        if(c <= ib && c >= ia) { FibCount++; printf("%d\n",c); }
        a = b;
        b = c;
        c = a + b;
    }while (c < ib);

    int nonFibCount = ib - ia + 1 - FibCount;
    
    if (ia == 0) nonFibCount -= 2;
    
    printf("\nNumber of non-Fibonacci numbers: %d\n", nonFibCount);
    return 0;
}