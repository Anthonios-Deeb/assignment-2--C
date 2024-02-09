CC=gcc
AR=ar
CFLAGS= -Wall

all: connections connections2

connections: my_graph.o my_mat.o
	$(CC) $(CFLAGS) my_graph.o my_mat.o -o connections

connections2: my_Knapsack.o
	$(CC) $(CFLAGS) my_Knapsack.o -o connections2

my_Knapsack.o: my_Knapsack.c
	$(CC) -c my_Knapsack.c

my_graph.o: my_graph.c my_mat.h
	$(CC) -c my_graph.c	

my_mat.o: my_mat.c my_mat.h
	$(CC) -c my_mat.c	

.PHONY: clean all

clean:
	rm -f *.o *.a *.so connections connections2
