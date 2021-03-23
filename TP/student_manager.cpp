#include "student.hpp"
#include "student_manager.hpp"

StudentManager::StudentManager(){}

void StudentManager::addStudent(Student s)
{
    studentList.push(s);
}

void StudentManager::listStudents()
{
    std::string var = "";
    for (int i = 0; i < studentList.count(); i++)
    {
        var += "Etudiant " + studentList[i].getFname() + " " + studentList[i].getLname() + ", Moyenne: ";
        try
        {
            var += studentList[i].getAverage();
        }
        catch (NoGrades n)
        {
            var += "No grades.";
        }
        catch (std::exception e)
        {
            std::cerr << e.what();
            exit(1);
        }
        std::cout << var << std::endl;
    }
}

void StudentManager::addStudentGrade(size_t studentIndex, float grade)
{
    studentList[studentIndex].addGrade(grade);
}

void StudentManager::displayStudentDetails(size_t studentIndex)
{
    Student s = studentList[studentIndex];
    std::cout << s.getFname() << " " << s.getLname();
    if (s.grades.count() == 0)
    {
        std::cout << "[Pas de notes]";
    }
    else
    {
        std::cout << "[";
        for (int i = 0; i < s.grades.count(); i++)
        {
            if (i == s.grades.count() - 1)
            {
                std::cout << s.grades[i];
            }
            else
            {
                std::cout << s.grades[i] << ", ";
            }
        }
        std::cout << "]";
    }
    std::cout << std::endl;
}
