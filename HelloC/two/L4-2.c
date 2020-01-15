#include <stdio.h>
int main()
{
	int a,b,sum;
	puts("请输入两个整数的值");
	printf("第一个数");scanf("%d",&a);
	printf("第二个数");scanf("%d",&b);
    sum = 0;
    if(a>b){
     for(int i = b+1;i<a;i++){
        sum =sum+i;
     }
    }else{
        for(int c = a+1;c<b;c++){
         sum += c;
        }
    }
    printf("它们之间的和是%d\n",sum);

	return 0;
}
