pex2: main.o image.o
	g++ -Wall main.o image.o -o pex2
main.o: main.cpp image.h
	g++ -c main.cpp
image.o: image.h image.cpp
	g++ -c image.cpp
clean:
	rm *.o pex2
