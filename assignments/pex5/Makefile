pex5: country.o  main.o
	g++ -Wall country.o main.o -o pex5
main.o: country.h
	g++ -Wall -c -std=c++11 main.cpp
country.o: country.h country.cpp
	g++ -Wall -c -std=c++11 country.cpp
clean:
	rm *.o pex5
