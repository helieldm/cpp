#include <iostream>
#include "list.hpp"
#include "student.hpp"
#include "exceptions.hpp"
#include "student_manager.hpp"

int main(int argc, char **argv)
{

    List<float> l1;
    List<float> l2;
    std::cout << l1 << std::endl;
    l1.push(23);
    l1.push(21);
    l1.push(2);
    l1.push(2);
    l1.push(2);
    l1.push(2);
    l1.push(2);
    l1.push(2);

    std::cout << l1[1] << std::endl;

    try
    {
        float var = l1[7];
    }
    catch (const BadIndex &e)
    {
        const char *str = e.what();
        std::cerr << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << l1 << std::endl;

    std::cout << "Test du Student Manager" << std::endl;

    StudentManager SM = StudentManager();

    Student s1 = Student();
    /*
    Student s2 = Student("Jonthan", "Brenguer");
    Student s3 = Student("Fredrique", "Gabrile");
    s2.addGrade(12);
    s2.addGrade(13);
    s2.addGrade(14);*/
    SM.addStudent(s1);/*
    SM.addStudent(s2);
    SM.addStudent(s3);*/
    SM.listStudents();
    SM.displayStudentDetails(1);
    //SM.displayStudentDetails(3);
    try
    {
        SM.displayStudentDetails(7);
    }
    catch (BadIndex e) {
        std::cerr << e.what();
    }
    
}