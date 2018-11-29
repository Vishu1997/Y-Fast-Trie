HEADERS = xfast_trie.h avl.h rdtsc.h

run: yfast_trie
	./yfast_trie < ../Input_10m32.txt

default: yfast_trie

program.o: yfast_trie.c $(HEADERS)
	gcc -c yfast_trie.c -o yfast_trie.o

program: yfast_trie.o
	gcc yfast_trie.o -o yfast_trie

clean:
	-rm -f yfast_trie.o
	-rm -f yfast_trie
