CC = gcc
TARGET = ex.out
OBJS = ex.o linkedlist_node.o

CFLAGS = -Wall
LDFLAGS = -lc

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)