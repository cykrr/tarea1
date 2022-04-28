CC=gcc
NAME=tarea2
SRC=$(wildcard src/*.c)
INCLUDES=-Iinclude
OBJS=$(patsubst src/%.c, out/%.o, $(SRC))
INCLUDE=$(wildcard include/*)
TESTS=$(wildcard tests/*)
TESTS=$(wildcard tests/*)

all: tests prepare $(OBJS) $(NAME) tests/map tests/list



$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(INCLUDES) main.c $(OBJS) -o $(NAME) -g

prepare:
	mkdir -p src out include tests


out/%.o: src/%.c
	$(CC) -o $@ -c $^ $(INCLUDES) -g

clean:
	rm $(NAME) $(OBJS)


tests/list: tests/listTest.c out/list.o
	$(CC) -o tests/list $^ $(INCLUDES) 

tests/map: tests/mapTest.c $(OBJS)
	$(CC) $(INCLUDES) -o tests/map $^ 

