demo: sale.o discountsale.o main.o
	g++ -Wall sale.o discountsale.o main.o -o demo
main.o: sale.h discountsale.h main.cpp
	g++ -Wall -c main.cpp
discountsale.o: sale.h discountsale.h discountsale.cpp
	g++ -Wall -c discountsale.cpp
sale.o: sale.h sale.cpp
	g++ -Wall -c sale.cpp
clean:
	rm *.o demo
