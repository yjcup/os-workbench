#include <setjmp.h>
#include <stdio.h>
int main() {
  int n = 0;
  jmp_buf buf;
  // 保存当前的执行环境
  int a = setjmp(buf);
  printf("hello %d\n", a);
  longjmp(buf, n++);
  return 0;
}
