exceptions.o : exceptions.cpp exceptions.hpp
	g++ -c exceptions.cpp -o exceptions.o

student.o : student.cpp student.hpp 
	g++ -c student.cpp -o student.o

main.o : main.cpp
	g++ -c main.cpp -o main.o

main : main.o exceptions.o student.o
	g++ exceptions.o student.o main.o -o main