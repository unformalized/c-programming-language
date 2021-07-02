#include <stdio.h>



int add_rang(int low, int high)
{
    // 局部变量的存储空间在每次函数调用时分配，在函数返回时释放
    // 局部变量在定义时不初始化则初始值是不确定的
    // 可能依赖系统环境，上次调用的结果...
    int i,sum;
    for (i = low; i <= high; i++)
        sum = sum + i;
    return sum; 
}

int main(void)
{
    int result[100];
    result[0] = add_rang(1, 10);
    result[1] = add_rang(1, 100);
    printf("result[0]=%d\nresult[1]=%d\n", result[0], result[1]);
	return 0;
}

