exceptions.o : #exceptions.cpp exceptions.hpp
	g++ -c TP/exceptions.cpp -o exceptions.o

student_manager.o :# student_manager.cpp student_manager.hpp 
	g++ -c TP/student_manager.cpp -o student_manager.o

student.o : #student.cpp student.hpp 
	g++ -c TP/student.cpp -o student.o

main.o : #main.cpp
	g++ -c TP/main.cpp -o main.o

main : main.o exceptions.o student_manager.o student.o
	g++ exceptions.o student_manager.o student.o main.o -o main

