demo: pfarrayd.o pfarraydbak.o main.o
	g++ pfarrayd.o pfarraydbak.o main.o -o demo
main.o: pfarraydbak.h main.cpp
	g++ -Wall -c main.cpp
pfarraydbak.o: pfarrayd.h pfarraydbak.h pfarraydbak.cpp
	g++ -Wall -c pfarraydbak.cpp
pfarrayd.o: pfarrayd.h pfarrayd.cpp
	g++ -Wall -c pfarrayd.cpp
clean:
	rm *.o demo
