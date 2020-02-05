#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *SHU[] = {"请选择难度等级\n", "1.0~9\n", "2.0~99\n", "3.0~999\n", "0.退出\n"};
char *JI[] = {"0~9", "0~99", "0~999"};
int SHU_C = sizeof(SHU) / sizeof(SHU[0]);
//int JI_C=sizeof(JI)/sizeof(JI[0]);
int scanInt();
int number(int a);
int jieguo(int a, int b, int c);

//设置流程状态
enum FlowStatus {
    ROOT, QUIT, MVLU1, MVLU2
};

//设置一级目录
void mulu1() {

    for (int i = 0; i < SHU_C; i++) {
        printf("%s", SHU[i]);
    }

    printf("你的输入：");
}

//设置二级目录
void mulu2(int a) {

    switch (a) {
    case 1:
        printf("你当前选择的难度等级0~9\n");
        break;

    case 2:
        printf("你当前选择的难度等级0~99\n");
        break;

    case 3:
        printf("你当前选择的难度等级0~999\n");
        break;

    default:
        printf("你输入的选项不再范围内,请重新输入：");
        exit(0);
        break;
    }

    puts("请输入你想要猜的次数，0返回上一级");
    printf("你的输入：");

}

//设置输入函数
int scanInt() {
    int input;
    int rlt = scanf("%d", &input);

    return input;
}

//一定范围的随机数
int sui(int a, int b) {
    int c = 0;
    srand(time(NULL));

    // 生成 [a,b]范围间的数字 n = a + X % (b - a + 1)
    c = (a + rand() % (b - a + 1));
    return c;

}


//生成的随机数
int number(int a) {
    int s = 0;

    switch (a) {
    case 1:
        s = sui(0, 9);
        break;

    case 2:
        s = sui(0, 99);
        break;

    case 3:
        s = sui(0, 999);
        break;
    }

    return s;
}

//设置三级目录
int mulu3() {

    puts("是否继续？");
    puts("1.继续，0.退出");
    printf("你的输入：");

    if (scanInt() == 1) {
        return 1;
    } else {
        return 0;
    }
}


int main() {

    enum FlowStatus flowStatus = ROOT;
//用户输入第一目录的选项
    int userInput = 0;
//用户输入要猜的次数
    int yourInput = 0;
//用户输入要猜的数字
    int youInput = 0;
//系统随机产生的随机数
    int a = 0;

    while (flowStatus != QUIT) {

        switch (flowStatus) {

        case ROOT:

            mulu1();
            userInput = scanInt();

            if (userInput < 0 || userInput > SHU_C) {
                printf("不存在的选项！\n");
            } else if (userInput == 0) {
                flowStatus = QUIT;
            } else {
                flowStatus = MVLU1;
            }

            break;

        case MVLU1:

            mulu2(userInput);
            a = number(userInput);
            yourInput = scanInt();

            if (yourInput <= 0) {
                flowStatus = ROOT;
            } else {

                flowStatus = MVLU2;

            }

            break;

        case MVLU2:
            for (int i = yourInput; i > 0; i--) {
                printf("剩余次数%d,请输入数字（%s,-1返回难度选择)：", i, JI[(userInput - 1)]);
                youInput = scanInt();

                if (youInput == -1) {
                    flowStatus = ROOT;
                    i = 0;
                } else {
                    int c = 0;
                    c = jieguo(youInput, a, i);

                    if (c == 1) {
                        flowStatus = ROOT;
                        break;
                    } else if (c == 0) {
                        flowStatus = QUIT;
                        break;
                    }

                }

            }


        }
    }


}


//判断用户输入数和随机数的比较结果
int jieguo(int a, int b, int c) {
    if (a == b) {
        printf("输入的是%d,恭喜你，猜中了\n", a);

        if (mulu3() == 1) {
            return  1;

        } else {
            return  0;
        }

        return 2;
    }

    if (a > b) {
        printf("输入的是%d,没有猜中，猜大了\n", a);

        if (c == 1) {
            puts("没有猜中，请再接再厉");

            if (mulu3() == 1) {
                return  1;
            } else {
                return  0;
            }

        }

        return 2;
    }

    if (a < b) {
        printf("输入的是%d,没有猜中，猜小了\n", a);

        if (c == 1) {
            puts("没有猜中，请再接再厉");

            if (mulu3() == 1) {
                return  1;

            } else {
                return  0;
            }
        }

        return 2;
    }
}



