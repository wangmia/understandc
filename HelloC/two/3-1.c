#include <stdio.h>
int main(void) {
    int a, b;
    int shu;
    puts("请输入两个整数。");
    printf("整数A:"); scanf("%d", &a);
    printf("整数B:"); scanf("%d", &b);
    shu = b % a ;

    if (shu) {
        printf("B不是A的约数\n");
    } else {
        printf("B是A的约数\n");
    }

    return 0;

}
