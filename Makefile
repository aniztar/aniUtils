lib: clean
	gcc -Iinc/ -c src/linkedList.c
	ar rsv list.a linkedList.o
	mkdir -p lib
	mv list.a lib/
	rm linkedList.o

clean:
	-rm -r lib
	-rm manageList

example: lib
	gcc -Iinc -o manageList examples/manageList.c lib/list.a
