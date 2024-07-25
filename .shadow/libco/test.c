#include "co.h"
#include <stdio.h>
int a = 10;
void Print(void *args) {
  a++;
  printf("1231asdfasdf\n");
	printf("%d\n",a);
}

int main() {
  co_start("A", &Print, NULL);
  return 0;
}
