CC=gcc
CFLAGS= -g -Wall -Werror

graph_mat: main.o graph_mat.o
	$(CC) $(CFLAGS) main.o graph_mat.o -o $@

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

graph_mat.o: graph_mat.c
	$(CC) $(CFLAGS) -c graph_mat.c

clean:
	rm -rf *.o graph_mat *~