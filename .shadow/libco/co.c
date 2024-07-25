#include "co.h"
#include <stdio.h>
#include <stdlib.h>
// how  to implement the balabala
struct co {};
// function pointer  rettype(*func)(args list);
// void*??
// 一个线程就是共享内存和独立堆栈
struct co *co_start(const char *name, void (*func)(void *), void *arg) {
  // execute the func
  // change the value of $rsp
  func(arg);
  return NULL;
}

void co_wait(struct co *co) {}

//
void co_yield () {}
