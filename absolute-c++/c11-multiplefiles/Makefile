timedemo: dtime.o timedemo.o
	g++ -Wall dtime.o timedemo.o -o timedemo
timedemo.o: dtime.h timedemo.cpp
	g++ -Wall -c timedemo.cpp
dtime.o: dtime.h dtime.cpp
	g++ -Wall -c dtime.cpp
clean:
	rm *.o timedemo
