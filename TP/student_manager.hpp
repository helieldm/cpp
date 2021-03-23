#ifndef STUDENT_MANAGER_HPP
#define STUDENT_MANAGER_HPP
#include "student.hpp"
#include "list.hpp"

class StudentManager{

    List<Student> studentList;

public:

    StudentManager();

    void addStudent(Student s);

    void listStudents();

    void addStudentGrade(size_t studentIndex, float grade);

    void displayStudentDetails(size_t studentIndex);

};


#endif