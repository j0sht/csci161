lab8: person.o student.o main.o
	g++ person.o student.o  main.o -o lab8
main.o: person.h student.h  main.cpp
	g++ -c main.cpp
student.o: person.h student.h student.cpp
	g++ -c student.cpp
person.o: person.h person.cpp
	g++ -c person.cpp
clean:
	rm *.o lab8
