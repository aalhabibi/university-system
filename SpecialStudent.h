#include <iostream>
#include <string>
#include "Course.h"
#include "Student.h"
using namespace std;

class SpecialProgramStudent : public Student
{
public:
    SpecialProgramStudent(int studentLevel, int noOfCoursesToBeRegistered, string studentName, string studentID) : Student()
    {
        level = studentLevel;

        name = studentName;
        ID = studentID;
    }

    float CalculateExpenses()
    {
        int sumOfCreditHours = 0;
        for (int i = 0; i < noOfCourses; ++i)
        {
            sumOfCreditHours += courseList[i]->getCreditHours();
        }
        float expenses = 500 * sumOfCreditHours;
        return expenses;
    };
};