pex3: reservation.o linkedlist.o main.o
	g++ -Wall reservation.o linkedlist.o main.o -o pex3
main.o: reservation.h linkedlist.h main.cpp
	g++ -Wall -c main.cpp
linkedlist.o: reservation.h linkedlist.h linkedlist.cpp
	g++ -Wall -c linkedlist.cpp
reservation.o: reservation.h reservation.cpp
	g++ -Wall -c reservation.cpp
clean:
	rm *.o pex3
