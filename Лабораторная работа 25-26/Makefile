all: exe lib

exe:	queue.h main.c lib
	gcc main.c -L. -lQueue -o prog

lib:	queue.h queue.c
	gcc -shared -fPIC queue.c -o libQueue.so

clean:
	-rm prog libQueue.so
