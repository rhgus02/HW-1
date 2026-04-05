CC = gcc
CFLAGS = -Wall -O2 -std=c99 -Iinclude

TARGET = program
OBJS = sort_main.o sort_algorithms.o

$(TARGET): $(OBJS)	
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

sort_main.o: sort_main.c sort_algorithms.h
	$(CC) $(CFLAGS) -c sort_main.c

sort_algorithms.o: sort_algorithms.c sort_algorithms.h
	$(CC) $(CFLAGS) -c sort_algorithms.c

clean:
	rm -f $(OBJS) $(TARGET).exe