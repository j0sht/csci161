lab5: growing.o main.o
	g++ main.o growing.o -o lab5
main.o: main.cpp growing.h
	g++ -c main.cpp
growing.o: growing.h growing.cpp
	g++ -c growing.cpp
clean:
	rm *.o lab5
