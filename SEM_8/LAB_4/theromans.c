#include <stdio.h>
#include <string.h>

void intToRoman(int num, char *roman) {
    struct Roman {
        int value;
        const char *symbol;
    } romanMap[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    int i = 0;
    while (num > 0) {
        while (num >= romanMap[i].value) {
            num -= romanMap[i].value;
            strcat(roman, romanMap[i].symbol);
        }
        i++;
    }
}

int main() {
    int number;
    char roman[100] = "";

    printf("Enter a number: ");
    scanf("%d", &number);

    intToRoman(number, roman);
    printf("Roman numeral: %s\n", roman);

    return 0;
}