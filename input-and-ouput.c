#include <stdio.h>


// 使用 < 符号进行输入重定向
// ./prog <CMakeLists.txt
// 将输出CMakeLists.txt 中的字符

// putchar 在使用 > 符号时会进行输出重定向，将不会将字符输出到标准输出上（屏幕），而是重定向输出到指定文件中

int main(int argc, char const *argv[]) {
  int c;

  while ((c = getchar()) != EOF)
    putchar(c);

  return 0;
}
