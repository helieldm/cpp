#include "student.hpp"
#include <string>
#include <iostream>
#include "list.cpp"

Student::Student(std::string fn, std::string ln) : firstname(fn), lastname(ln)
{
    grades = List<float>();
}

Student::Student()
{
    std::cout << "Entrez un prénom " << std::endl;
    std::cin >> firstname;
    std::cout << "Entrez un nom" << std::endl;
    std::cin >> lastname;
    std::cout << "Bonjour " << firstname << " " << lastname << ".";
}

//Ajouter une note
void Student::addGrade(float grade)
{
    std::cout << "Added " << grade << " to list of grades";
    grades.push(grade);
}
//Récupérer la moyenne
float Student::getAverage()
{
    float count = grades.count();
    if (count == 0)
    {
        throw NoGrades();
    }
    float r = 0;
    for (int i = 0; i < count; i++)
    {
        r += grades[i];
    }
    return r / count;
}