CC=gcc
CFLAGS= -g -Wall -Werror

queue: main.o queue.o
	$(CC) $(CFLAGS) main.o queue.o -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

queue.o: queue.c
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -rf *.o queue *~
