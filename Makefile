all: stack

stack: main.o stack.o
		g++ main.o stack.o -o stack

main.o: main.cpp
		g++ -c main.cpp

stack.o: stack.cpp
		g++ -c stack.cpp

clean:
	rm -rf *.o stack 
