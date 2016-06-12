IDIR=include
CC=gcc
CFLAGS=-Wall -std=c99 -I$(IDIR) -g

SOURCES=$(filter-out src/stackTest.c, $(wildcard src/*.c))
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))
EXECUTABLE=bin/mazeSolver

TEST_SRC=src/stack.c src/stackTest.c src/linkedList.c
TESTS=$(patsubst %.c,%.o,$(TEST_SRC))
TEST_EXEC=bin/stackTest

all: test program

test: $(TESTS)
	$(CC) $(CFLAGS) -o $(TEST_EXEC) $(TESTS)

program: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJECTS)

clean:
	rm -f src/*.o src/*.o $(EXECUTABLE) $(TEST_EXEC)