#include <iostream>
#include <cstring>
#include <utility>

class Student
{
    unsigned int maxGrades;
    unsigned int amtGrades;
    float *grades;

public:
    Student(unsigned int max) : maxGrades(max), amtGrades(0)
    {
        std::cout << "Default constructor allocating memory" << std::endl;
        grades = new float[maxGrades];
    }

    Student() : Student(30) {}

    // Copy constructor
    Student(const Student &s) : maxGrades(s.maxGrades), amtGrades(s.amtGrades)
    {
        std::cout << "Copy constructor allocating memory." << std::endl;
        grades = new float[maxGrades];
        std::memcpy(grades, s.grades, amtGrades * sizeof(float));
    }
    // Assignement operator
    Student &operator=(Student s) {
        std::cout << "Assignment operator. ";
        maxGrades = s.maxGrades;
        amtGrades = s.amtGrades;
        std::swap(grades, s.grades);
        return *this;
    }

    void addGrade(float grade)
    {
        if (amtGrades == maxGrades)
        {
            return;
        }
        grades[amtGrades] = grade;
        amtGrades++;
    }
    float getAverage()
    {
        if (amtGrades == 0)
        {
            return 0;
        }
        float result = 0;
        for (int i = 0; i < amtGrades; i++)
        {
            result += grades[i];
        }
        return result / amtGrades;
    }
    ~Student()
    {
        std::cout << "Student has been... Terminated." << std::endl;
        delete[] grades;
    }
};

int main(int argc, char **argv)
{
    Student s1;
    Student s2(5);
    s1.addGrade(12);
    s1.addGrade(17);
    s1.addGrade(15);
    s1.addGrade(9);
    s2.addGrade(20);
    s2.addGrade(20);
    s2.addGrade(20);
    s2.addGrade(20);
    s2.addGrade(20);
    s2.addGrade(0);
    std::cout << "Student 1 average : " << s1.getAverage() << std::endl;
    std::cout << "Student 2 average : " << s2.getAverage() << std::endl;
    // delete s1;
    return 0;
}