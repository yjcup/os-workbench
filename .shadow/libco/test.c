#include "co.h"
#include <stdio.h>
void Print() {
  for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
  }
}

int main() {
  co_start("A", Print, NULL);
  return 0;
}
