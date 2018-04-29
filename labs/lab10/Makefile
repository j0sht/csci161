
lab10: main.o family.o
	g++ -o lab10 main.o family.o

main.o: main.cpp family.h
	g++ -c main.cpp

family.o: family.cpp family.h
	g++ -c family.cpp

clean:
	rm *.o lab10

