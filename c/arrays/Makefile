array: main.o array.o
	gcc -Wall -Werror array.o main.o -o array

main.o: main.c array.o
	gcc -Wall -Werror -c array.o main.c

array.o: array.c array.h
	gcc -Wall -Werror -c array.c

clean:
	rm *.o array *~

