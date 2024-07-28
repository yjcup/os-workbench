#include "co.h"
#include <setjmp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>

#define STACK_SIZE 1024 * 8

// os：创建，就绪，执行，睡眠，结束
// 正常情况下，os通过时间片轮转调度算法来对进程（线程）进行调度
// 但是os是感知不到协程的存在的，只有通过调用yield方法来手动完成调度,
// 这里的调度算法就是随机的
//
//
struct co *current;      // point to the current coroutine
struct co *queue = NULL; // 可执行队列
                         //

void add(struct co *co) {}

struct co *getCoRandomly() { return queue; }

enum co_status {
  CO_NEW = 1, // create
  CO_RUNNING, //
  CO_WATTING,
  CO_DEAD
};

// how  to implement the balabala
// all kinds of regs;
struct context {

  /*uint64_t rax; // return value*/
  jmp_buf jmp;
};

struct co {
  char *name;
  void (*func)(void *); // entry pointer
  void *arg;
  enum co_status status; // coroutine status
                         //
  struct context context;
  struct co *waiter;         // 是否有其他线程在等待当前线程
  uint8_t stack[STACK_SIZE]; // independent stack
                             // how to implement coroutine switching
                             //
};
// function pointer  rettype(*func)(args list);
// void*??
// 一个线程就是共享内存和独立堆栈
// 内核态线程和协程的区别：就是前者是os负责调度，而后者需要通过yield自己完成调度
struct co *co_start(const char *name, void (*func)(void *), void *arg) {
  // 创建携程的对象并返回
  struct co *co = malloc(sizeof(struct co));
  co->func = func;
  co->arg = arg;
  co->name = name;
  co->status = CO_NEW;
  // add the coroutine to the queue
  add(co);
  return co;
}

// 表示当前协程需要等待，知道co协程执行完才能继续执行
// main
// 函数也是一个协程，当我调用这个函数的时候，只需要将co加入waiter之后进行切换
// zhuyi co_wait执行的孙旭
void co_wait(struct co *co) {}
// co_wait(co1)那我需要等待co1执行完成才能继续执行
// 此时我需要将co1加入到当前线程的co1wait中

// select a thread randomly to execute
// save the context(regs,pc)
// change the pc
// recover the context(regs,pc)
// 要进行上下文切换进程会自己将调用者保存寄存器保存到栈中，然后进行函数调用
// 所有我们要自行保存被调用者寄存器的值 rbx rsp rbp r12 r13 r14 r15 (7)
// 由于yield没有参数 6个参数寄存器不需要保存
// rax为什么不保存
// 调用者保存寄存器保存到哪里了
// 需要一个全局变量来保存当前的就绪队列
//

void co_yield () {
  /*int val = setjmp(current->context);*/
  /*if (val == 0) {*/
  /*  选择一个函数执行*/
  /*  longjmp(co.context, 1);*/
  /*} else {*/
  /*  此时是返回的状态继续执行*/
  /*}*/
  // 继续完成补充
  int val = setjmp(current->context.jmp);
  if (val == 0) {
    // 随机选择一个
    struct co *temp = getCoRandomly();
    current = temp;
    longjmp(current->context.jmp, 1);
  } else {
    // 恢复继续执行
  }
}
