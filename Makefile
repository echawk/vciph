.POSIX:
.PHONY: clean
CC=gcc
CFLAGS=-std=c99 -Wall -pedantic
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)
TARGET=ciph

all: ciph

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(TARGET) $(OBJS)
