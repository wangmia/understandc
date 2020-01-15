#include <stdio.h>
int main(){
puts("请输入两个整数");
int a,b;
printf("整数1：");scanf("%d",&a);
printf("整数2：");scanf("%d",&b);
printf("%d是%d的%.2f%%",(double)((a/b)*100));
return 0;
}
