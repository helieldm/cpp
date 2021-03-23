#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include "list.hpp"

class Student
{
    std::string firstname, lastname;
public:

    List<float> grades;

    // Constructeurs
    Student(std::string fn, std::string ln);
    Student();
    //Ajouter une note
    void addGrade(float grade);
    //Récupérer la moyenne
    float getAverage();

    std::string getFname();
    std::string getLname();

};
#endif