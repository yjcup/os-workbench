#include <setjmp.h>
#include <stdio.h>

jmp_buf jump_buffer;

void someFunction() {
  // 一些操作
  // print
  printf("baba!\n");
  //
  longjmp(jump_buffer, 1); // 跳转回 setjmp 的位置，返回值为1
}

int main() {
  // 默认返回是0
  int a = setjmp(jump_buffer); // 保存寄存器
  if (a == 0) {
    someFunction(); // 调用 someFunction，可能会执行 longjmp
  } else {
    // 从 longjmp 跳转回来后的代码
    //
    printf("kaka!\n");
  }
  return 0;
}
