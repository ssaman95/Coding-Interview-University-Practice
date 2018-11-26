CC=gcc
CFLAGS= -g -Wall -Werror

graph_adj: main.o graph_adj.o queue.o
	$(CC) $(CFLAGS) main.o graph_adj.o queue.o -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

graph_adj.o: graph_adj.c
	$(CC) $(CFLAGS) -c graph_adj.c

queue.o: queue.c
	$(CC) $(CFLAGS) -c queue.c

clean:
	rm -rf *.o graph_adj *~
