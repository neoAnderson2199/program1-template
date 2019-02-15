P = program1
CFLAGS = -Wall -Wextra -DDEBUG -g -std=c++14

all:$(P).o Star.o Planet.o List.o Vector.o Star.h Planet.h List.h Vector.h
	g++ $(CFLAGS) $(P).o Star.o Planet.o List.o Vector.o -o $(P)

Star.o:Star.cpp
	gcc -c $(CFLAGS) Star.cpp -o Star.o

Planet.o:Planet.cpp
	gcc -c $(CFLAGS) Planet.cpp -o Planet.o
	
$(P).o:$(P).cpp
	gcc -c $(CFLAGS) $(P).cpp -o $(P).o

List.o: List.cpp
	gcc -c $(CFLAGS) List.cpp -o List.o

Vector.o: Vector.cpp
	gcc -c $(CFLAGS) Vector.cpp -o Vector.o
	
run:all
	./$(P)

clean:
	rm -rf $(P) $(P).o Star.o Planet.o List.o Vector.o

memcheck:all
	valgrind ./$(P)
	