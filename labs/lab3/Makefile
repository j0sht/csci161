lab3: main.o flag.o
	g++ main.o flag.o -o lab3
main.o: main.cpp flag.h
	g++ -c main.cpp
flag.o: flag.h flag.cpp
	g++ -c flag.cpp
clean:
	rm *.o lab3
