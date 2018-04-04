pex5: country.o  main.o
	g++ -Wall country.o main.o -o pex5
main.o: country.h
	g++ -Wall -c main.cpp
country.o: country.h country.cpp
	g++ -Wall -c country.cpp
clean:
	rm *.o pex5
