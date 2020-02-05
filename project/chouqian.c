#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sui(int a,int b) {
    int c = 0;
    srand(time(NULL));

    // 生成 [a,b]范围间的数字 n = a + X % (b - a + 1)
    c = (a + rand() % (b - a + 1));
    return c;
}


int main() {
    char a[30] = {0};
    int c = 0;
    int k = 1;
    char e[30] = {"0"};

    puts(" 欢迎来到游戏");
    puts("+++++++++++++");


    while (k) {

        printf("请输入任意文字\n");
        puts("输入0退出");
        scanf("%s", a);
        c = sui(0,1000);

        if (a[0] == e[0]) {k = 0; break;}

        if (c > 0 && c <= 50) {
            puts("恭喜，你抽中了大吉");
        } else if (c > 50 && c <= 150) {
            puts("恭喜，你抽中了中吉");
        } else if (c > 150 && c <= 300) {
            puts("恭喜，你抽中了小吉");
        } else if (c > 300 && c <= 600) {
            puts("恭喜，你抽中了吉");
        } else if (c > 600 && c <= 800) {
            puts("你抽中了末吉");
        } else if (c > 800 && c <= 950) {
            puts("你抽中了凶");
        } else if (c > 950 && c <= 1000) {
            puts("你抽中了大凶");
        }

        
    }






}