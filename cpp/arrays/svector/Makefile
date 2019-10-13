svector: svector.o svector_test.o main.o
	g++ -Wall -Werror svector.o svector_test.o main.o -o svector

main.o: main.cc svector.o svector_test.o
	g++ -Wall -Werror -c main.cc svector.o svector_test.o

svector_test.o: svector_test.cc svector.o
	g++ -Wall -Werror -c svector.o svector_test.cc

svector.o: svector.cc
	g++ -Wall -Werror -c svector.cc

clean:
	rm *.o *~ svector
