#include <malloc.h>
#include <stdio.h>

void func(void *arg) {
  char *a = arg;
  printf("%s\n", a);
}

int main() {
  char *a = "123123";
  void *addr = malloc(1024);
  addr += 1023;
  /*printf("%p\n", addr);*/
  void (*func_ar)(void *) = &func;
  asm inline("movq %0, %%rsp;" : : "r"(addr));
  func_ar(a);
  return 0;
}
