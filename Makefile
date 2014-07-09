CC = gcc
CFLAGS  = -g -Wall

all: main

main: func.o main.o input.o menumain.o io.o
	$(CC) $(CFLAGS) -o main main.o input.o menumain.o func.o io.o

menumain.o: menumain.c menumain.h input.h func.h io.h
	$(CC) $(CFLAGS) -c menumain.c

input.o: input.c input.h func.h input.h
	$(CC) $(CFLAGS) -c input.c

main.o: main.c input.h menumain.h func.h
	$(CC) $(CFLAGS) -c main.c

func.o: func.c func.h 
	$(CC) $(CFLAGS) -c func.c

io.o: io.c io.h func.h
	$(CC) $(CFLAGS) -c io.c

clean: 
	$(RM) count *.o *~

