pex3: reservation.o reservationlist.o main.o
	g++ -Wall reservation.o reservationlist.o main.o -o pex3
main.o: reservation.h reservationlist.h main.cpp
	g++ -Wall -c main.cpp
reservationlist.o: reservation.h reservationlist.h reservationlist.cpp
	g++ -Wall -c reservationlist.cpp
reservation.o: reservation.h reservation.cpp
	g++ -Wall -c reservation.cpp
clean:
	rm *.o pex3
