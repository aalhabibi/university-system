#include <iostream>
#include <string>
#include "Course.h"
#include "Student.h"
using namespace std;

class GeneralProgramStudent : public Student
{
public:
    GeneralProgramStudent(int studentLevel, int noOfCoursesToBeRegistered, string studentName, string studentID) : Student()
    {
        level = studentLevel;
        name = studentName;
        ID = studentID;
    }

    bool RegisterCourse(Course *course)
    {
        if (level < (course->getMinStudentLevel()))
        {
            cout << "\t\t\tError: You cannot register in this course\n";
            return false;
        }
        if (noOfCourses > 6)
        {
            cout << "Max courses registered(6).\n";
            return false;
        }
        courseList[noOfCourses] = course;

        double grade;
        while (true)
        {
            cout << "\n\t\t\t- Grade: ";

            cin >> grade;
            if (grade > 100 || grade < 0)
            {
                cout << "\t\t\tInvalid grade! \n";
            }
            else
            {
                Grades[noOfCourses] = grade;
                break;
            }
        }

        noOfCourses++;
        return true;
    }
    float CalculateExpenses()
    {
        int expenses = 1000 * level;
        return expenses;
    };
};
