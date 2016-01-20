# $@-- 目标文件, $^ -- 所有依赖文件
DEBUG = -g
CC = gcc $(DEBUG) -std=c99

all: main

main: main.o
	$(CC) -o $@ $^

main.o: main.c
	$(CC) -c $^

clean:
	rm main.o main

.phony: all clean

