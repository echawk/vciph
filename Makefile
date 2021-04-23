.POSIX:
.PHONY: clean
CC=gcc
CFLAGS:=$(CFLAGS) -std=c89 -Wall -pedantic
#SRCS=$(wildcard *.c)
SRCS=ciph.c reverse_string.c vigenere.c
OBJS=$(SRCS:.c=.o)
TARGET=ciph

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(TARGET) $(OBJS)
