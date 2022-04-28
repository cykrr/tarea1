CC=gcc
NAME=tarea1
SRC=$(wildcard src/*.c)
INCLUDES=-Iinclude
OBJS=$(patsubst src/%.c, out/%.o, $(SRC))
INCLUDE=$(wildcard include/*)
TESTS=$(wildcard tests/*)
TESTS=$(wildcard tests/*)




$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(INCLUDES) $(OBJS) -o $(NAME) -g

prepare:
	mkdir -p src out include tests/testList

all: tests prepare $(OBJS) link

out/%.o: src/%.c
	$(CC) -o $@ -c $^ $(INCLUDES) -g

clean:
	rm $(NAME) $(OBJS)


tests/list: tests/listTest.c out/list.o
	$(CC) -o tests/testList $^ $(INCLUDES) 

tests/map: tests/mapTest.c out/map.o out/item.o
	$(CC) -o tests/testMap $^ -Iinclude

