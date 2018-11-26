linkedlist: main.o tests.o slist.o
	gcc -g -Wall -Werror main.o tests.o slist.o -o linkedlist

main.o: main.c
	gcc -g -Wall -Werror -c main.c

tests.o: tests.c 
	gcc -g -Wall -Werror -c tests.c 

slist.o: slist.c
	gcc -g -Wall -Werror -c slist.c

clean:
	rm -rf *.o linkedlist *~
