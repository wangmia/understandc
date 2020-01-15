#include <stdio.h>
int main()
{
	int a,b,c;
	printf("请输入一个整数");
    scanf("%d",&a);
    b = a/5;
    for(int i=1;i<=b;i++){
    	printf("*****");
    	printf("\n");
        }
       c = a%5;
    for(int i=1;i<=c;i++){
        printf("*");
    }
    printf("\n");
	return 0;
}