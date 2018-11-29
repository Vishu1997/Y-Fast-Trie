HEADERS = avl.h rdtsc.h

run: avl
	./avl < ../Input_10m32.txt

default: avl

program.o: avl.c $(HEADERS)
	gcc -c avl.c -o avl.o

program: avl.o
	gcc avl.o -o avl

clean:
	-rm -f avl.o
	-rm -f avl
