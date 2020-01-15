#include <stdio.h>
int main() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int n, b, c;
    printf("请输入一个整数");
    scanf("%d", &n);
    b = n / 10;

    for (int i = 1; i <= b; i++) {
        printf("1234567890");

    }

    c = n % 10;

    for (int i = 0; i < c; i++) {
        printf("%d", a[i]);
    }

    printf("\n");
    return 0;
}