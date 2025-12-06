# Change this variable to switch between implementations (v1, v2, v3, etc.)
VERSION = v1

run: main.o $(VERSION).o
	clang main.o $(VERSION).o -o run

main.o: main.c headers/tree.h headers/$(VERSION).h
	clang -c main.c -DTREE_$(shell echo $(VERSION) | tr '[:lower:]' '[:upper:]')

$(VERSION).o: headers/$(VERSION).c headers/$(VERSION).h
	clang -c headers/$(VERSION).c -o $(VERSION).o

clean:
	rm -f *.o run