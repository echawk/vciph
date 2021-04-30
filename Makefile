.POSIX:
.PHONY: clean test
CC=gcc
CFLAGS:=$(CFLAGS) -std=c89 -Wall -pedantic
#SRCS=$(wildcard *.c)
SHAREDSRC=reverse_string.c vigenere.c
SRCS=ciph.c $(SHAREDSRC)
OBJS=$(SRCS:.c=.o)
TARGET=ciph

TESTSRCS=munit/munit.c test_runner.c $(SHAREDSRC)
TESTOBJS=$(TESTSRCS:.c=.o)
TEST_RUNNER=test_runner

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_RUNNER): $(TESTOBJS)
	$(CC) $(CFLAGS) -o $@ $(TESTOBJS)

clean:
	rm $(TARGET) $(OBJS) $(TESTOBJS) $(TEST_RUNNER)

test: $(TEST_RUNNER)
	./$(TEST_RUNNER)
