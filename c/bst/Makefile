bst : main.c bst.o
	g++ -Wall -Werror main.c bst.o -o bst

bst.o: bst.c bst.h
	g++ -Wall -Werror -c bst.c

clean:
	rm -rf *.o bst *~
