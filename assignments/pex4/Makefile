pex4:  url.o urlstack.o main.o
	g++ -Wall url.o urlstack.o main.o -o pex4
main.o:  url.h urlstack.h main.cpp
	g++ -Wall -c main.cpp
urlstack.o: url.h urlstack.h urlstack.cpp
	g++ -Wall -c urlstack.cpp
url.o: url.h url.cpp
	g++ -Wall -c url.cpp
clean:
	rm *.o pex4
