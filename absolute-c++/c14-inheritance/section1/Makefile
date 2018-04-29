demo: employee.o hourlyEmployee.o salariedEmployee.o main.o
	g++ employee.o hourlyEmployee.o salariedEmployee.o main.o -o demo
main.o: hourlyEmployee.h salariedEmployee.h main.cpp
	g++ -Wall -c main.cpp
salariedEmployee.o: employee.h salariedEmployee.h salariedEmployee.cpp
	g++ -Wall -c salariedEmployee.cpp
hourlyEmployee.o: employee.h hourlyEmployee.h hourlyEmployee.cpp
	g++ -Wall -c hourlyEmployee.cpp
employee.o: employee.h employee.cpp
	g++ -Wall -c employee.cpp
clean:
	rm *.o demo
