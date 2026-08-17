CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDFLAGS =

TARGET = simpleBash
SRCS = src/main.c \
       src/core/shell.c \
       src/core/parser.c \
       src/core/builtins.c \
       src/core/executor.c \
       src/ui/terminal.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
