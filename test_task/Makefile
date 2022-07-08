GFALG = -Wall -Werror -Wextra -std=c11

all: clean build run

build: test_task.c
	gcc $(GFLAG) test_task.c -o task -lm

run:
	./task

clean:
	rm -rf task
