#include <stdio.h>

// 文件访问
// 使用库函数 fopen 与操作系统建立文件连接，并返回包含文件信息的结构，struct FILE,
// FILE *fopen(char *name, char mode);
// mode 可以为 "r"读,"w"写,"a"追加, "b" 区分文本文件和二进制文件
// fopen 发生错误返回 NULL
// getc 从文件中返回下一个字符
// int getc(FILE *fp);
// putc 将字符写入到指定的文件中
// int putc(int c, FILE *fp);

//在启动一个C程序后，操作系统环境负责打开3个文件，并将三个文件的指针提供给该程序。 stdin, stdout, stderr

#define getchar_self() getc(stdin)
#define putchar_self(c) putc((c), stdout)

// 增加错误处理 stderr, exit


/**
 * cat 函数
 */
int main(int argc, char const *argv[]) {
  FILE *fp;
  void filecopy(FILE *, FILE *);
  // 保存程序名称
  char *prog_name = argv[0];

  if (argc == 1)
    filecopy(stdin, stdout);
  else
    while (--argc > 0) {
      if ((fp = fopen(*++argv, "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", prog_name, *argv);
        exit(1);
      } else {
        filecopy(fp, stdout);
        fclose(fp);
      }
    }

  if (ferror(stdout)) {
    fprintf(stderr, "%s: error writing stdout\n", prog_name);
    exit(2);
  }

  /* code */
  return 0;
}

/**
 * filecopy 函数，
*/
void filecopy(FILE *ifp, FILE *ofp)
{
  int c;
  while ((c = getc(ifp)) != EOF)
    putc(c, ofp);
}


// 行输入和行输出


char *fgets_self(char *s, int n, FILE *fp)
{
  register int c;
  register char *cs;

  cs = s;
  while ( --n > 0 && (c = getc(fp)) != EOF) {
    if ((*cs++ = c ) != '\n')
      break;
  }
  *cs = '\0';
  return ( c == EOF && cs == s) ? NULL : s;
}

int fputs_self(char *s, FILE *iop)
{
  int c;
  while (c = *s++)
    putc(c, iop);
  return ferror(iop) ? EOF : 1;
}













