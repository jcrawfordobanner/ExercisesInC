main.o: main.c
	gcc -c main.c
trout.o: trout.h trout.c
	gcc -c trout.c

util.o: util.h util.c
	gcc -c util.c

trout: main.o util.c trout.o util.o
	gcc main.o trout.o util.o -o trout

test: test_util.c util.c
	gcc test_util.c util.c -o test
