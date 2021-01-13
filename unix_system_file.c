#include "syscall.h"

#define BUFSIZE 100000

// Unix操作系统通过一系列的系统调用提供服务，其实是操作系统内的函数，它们也可以被用户调用


// 8.1 文件描述符
// 通常情况下，在读写文件之前，必须通知系统，该过程称为打开文件，若是写文件，则有可能需要先创建文件，若是一切正常，则
// 则系统返回一个非负整数，为文件描述符，任何对文件的输入输出都是通过文件描述符标识文件
// 当命令解释系统 shell 运行一个程序时，将打开三个文件，对应的文件描述符分别为 0 1 2，标准输入，标准输出，标准错误
// 程序的使用者可以用 < 和 > 重定向程序的I/O

// 8.2 低级I/O

// 参数 fd: 文件描述符，buf: 程序中存放读或写的数据的字符数组，n: 传输的字节数
int read_self(int fd, char *buf, int n);
int written_self(int fd, char *buf, int n);



int main(int argc, char const *argv[])
{
    return 0;
}


/**
 * 将输入转换为输出
 * input_transform_output
 */
void input_transform_output()
{
    char buf[BUFSIZE];
    int n;
}








