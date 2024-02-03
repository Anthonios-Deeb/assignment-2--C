CC=gcc
AR=ar
CFLAGS= -Wall

all: connections

connections: main.o my_mat.o
	$(CC) $(CFLAGS) main.o my_mat.o -o connections

main.o: main.c my_mat.h
	$(CC) -c main.c	

my_mat.o: my_mat.c my_mat.h
	$(CC) -c my_mat.c	

.PHONY: clean all
clean:
	rm -f *.o *.a *.so connections
