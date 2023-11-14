#include "main.h"

void revstr(char str[], int len) {
    int end = len - 1;
    for (int start = 0; start < end; start++) {
        char tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        end--;
    }
}

int intconvert(int num, char str[]) {
    int i = 0;
    int negVal = 0;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return i;
    }

    if (num < 0) {
        negVal = 1;
        num = -num;
    }

    while (num != 0) {
        int rem = num % 10;
        str[i++] = rem + '0';
        num /= 10;
    }

    if (negVal)
        str[i++] = '-';

    str[i] = '\0';

    revstr(str, i);

    return i; // Return the length of the string
}