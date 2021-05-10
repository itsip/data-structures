ds:  main.o
	g++ -std=c++11 -o ds main.o -lpthread
main.o:  main.cpp Array.hpp LinkedList.hpp
	g++ -std=c++11 -c main.cpp
clean:
	rm -f ds *.o core
