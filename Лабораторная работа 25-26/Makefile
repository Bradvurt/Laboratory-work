all: main.o queue.o
	gcc -o prog main.o queue.o 

main.o:	main.c queue.o
	gcc -g -Wall -pedantic -c main.c

queue.o:	queue.h queue.c
	gcc -g -Wall -pedantic -c queue.c

clean:
	-rm prog libQueue.so
