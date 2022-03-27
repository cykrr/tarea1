CC=gcc
NAME=tarea1
SRC=$(wildcard src/*.c)
INCLUDES=-Iinclude
OBJS=$(patsubst src/%.c, out/%.o, $(SRC))
INCLUDE=$(wildcard include/*)
TESTS=$(wildcard tests/*)
TESTS=$(wildcard tests/*)




$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(INCLUDES) $(OBJS) -o $(NAME)

prepare:
	mkdir -p src out include tests/testList

all: tests prepare $(OBJS) link

out/%.o: src/%.c
	$(CC) -o $@ -c $^ $(INCLUDES)

clean:
	rm $(NAME) $(OBJS)


tests/testList: tests/listTest.c out/list.o
	$(CC) -o tests/testList $^ $(INCLUDES) 

