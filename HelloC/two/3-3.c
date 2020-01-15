#include <stdio.h>
 int main(void)
{
	int a;
	printf("请输入一个整数");
	scanf("%d",&a);
	printf("%d的绝对值是%d \n",a,-a);
	return 0;
}