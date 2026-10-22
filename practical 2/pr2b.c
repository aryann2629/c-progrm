#include <stdio.h>

void swapByValue(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("Inside swapByValue    : a = %d, b = %d\n", a, b);
}

void swapByReference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("Inside swapByReference: a = %d, b = %d\n", *a, *b);
}

int main() {
    int x = 10, y = 20;

    printf("Original values       : x = %d, y = %d\n\n", x, y);

    swapByValue(x, y);
    printf("After swapByValue     : x = %d, y = %d  (NOT changed)\n\n", x, y);

    swapByReference(&x, &y);
    printf("After swapByReference : x = %d, y = %d  (changed!)\n", x, y);

    return 0;
}
