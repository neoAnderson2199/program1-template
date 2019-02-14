P = lab3
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all:$(P).o Star.o Planet.o
	g++ $(CFLAGS) $(P).o Star.o Planet.o -o $(P)

Star.o:Star.cpp
	gcc -c $(CFLAGS) Star.cpp -o Star.o

Planet.o:Planet.cpp
	gcc -c $(CFLAGS) Planet.cpp -o Planet.o
	
$(P).o:$(P).cpp
	gcc -c $(CFLAGS) $(P).cpp -o $(P).o

run:all
	./$(P)

clean:
	rm -rf $(P) $(P).o Star.o Planet.o

memcheck:all
	valgrind ./$(P)
	