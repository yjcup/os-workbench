NAME := $(shell basename $(PWD))
export MODULE := M2
all: $(NAME)-64.so $(NAME)-32.so
CFLAGS += -U_FORTIFY_SOURCE


test: test.c co.h
	gcc -I. -L. test.c co.c -o test
	@./test

include ../Makefile
