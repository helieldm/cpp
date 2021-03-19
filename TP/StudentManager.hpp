#ifndef STUDENT_MANAGER_HPP
#define STUDENT_MANAGER_HPP
#include "student.hpp"
#include "list.hpp"

class StudentManager{

    List<Student> studentList;

public:

    StudentManager();

    void addStudent(Student s);

    std::string listStudents();

    void addStudent(size_t studentIndex, float grade);

    List<float> displayStudentDetails(size_t studentIndex);

};


#endif