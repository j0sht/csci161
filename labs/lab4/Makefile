lab4: main.o complexNumber.o
	g++ main.o complexNumber.o -o lab4
main.o: main.cpp complexNumber.h
	g++ -c main.cpp
complexNumber.o: complexNumber.h complexNumber.cpp
	g++ -c complexNumber.cpp
clean:
	rm *.o lab4
