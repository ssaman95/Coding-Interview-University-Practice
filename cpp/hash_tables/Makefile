hash_table: main.cc hash_table.o tests.o
	g++ -Wall -Werror main.cc hash_table.o tests.o -o hash_table

tests.o: tests.cc hash_table.o
	g++ -Wall -Werror -c tests.cc 

hash_table.o: hash_table.cc
	g++ -Wall -Werror -c hash_table.cc

clean:
	rm -rf *o *~ hash_table
