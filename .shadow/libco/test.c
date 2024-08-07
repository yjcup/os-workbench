#include "co.h"
#include <stdio.h>
int a = 10;
void Print(void *args) {
	char temp=*(char*) args;
	for(int i=0;i<10;i++){
		printf("%c\n",temp);
	}
}

int main() {
	char a = 'A';
	char b = 'B';
  co_start("A", &Print, &a);
  co_start("A", &Print, &b);
  return 0;
}
