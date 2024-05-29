#include <iostream>
#include <string>
#include "Course.h"
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

class Student
{
protected:
    Course *courseList[6];
    double Grades[6];
    int noOfCourses;
    int level;
    string name;
    string ID;

public:
    Student()
    {
        for (int i = 0; i < 6; ++i)
        {
            courseList[i] = nullptr;
        }
        noOfCourses = 0;
    }

    void printRegisteredCourses()
    {
        cout << "\n- Registered Courses: ";
        for (int i = 0; i < noOfCourses; ++i)
        {
            cout << "\n\t- Course " << i + 1 << ":" << *courseList[i];
            cout << "\t\t- Grade: " << Grades[i];
        }
    }

    virtual float CalculateExpenses() = 0;
    virtual bool RegisterCourse(Course *course)
    {

        if (noOfCourses >= 6)
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
    double getCourseGPA(double grade)
    {
        double GPA;
        if (grade >= 93)
        {
            GPA = 4.00;
        }
        else if ((grade >= 90) && (grade <= 92))
        {
            GPA = 3.70;
        }
        else if ((grade >= 87) && (grade <= 89))
        {
            GPA = 3.30;
        }
        else if ((grade >= 83) && (grade <= 86))
        {
            GPA = 3.00;
        }
        else if ((grade >= 80) && (grade <= 82))
        {
            GPA = 2.70;
        }
        else if ((grade >= 77) && (grade <= 79))
        {
            GPA = 2.30;
        }
        else if ((grade >= 73) && (grade <= 76))
        {
            GPA = 2.00;
        }
        else if ((grade >= 70) && (grade <= 72))
        {
            GPA = 1.70;
        }
        else if ((grade >= 67) && (grade <= 69))
        {
            GPA = 1.30;
        }
        else if ((grade >= 63) && (grade <= 66))
        {
            GPA = 1.00;
        }
        else if ((grade >= 60) && (grade <= 62))
        {
            GPA = 0.70;
        }
        else
        {
            GPA = 0.00;
        }
        return GPA;
    }
    double getTotalGPA()
    {
        double totalGPAPoints = 0;
        double totalCreditHours = 0;
        for (int i = 0; i < noOfCourses; ++i)
        {
            double courseGPA = getCourseGPA(Grades[i]);
            double courseCreditHours = courseList[i]->getCreditHours();
            totalGPAPoints += (courseGPA * courseCreditHours);
            totalCreditHours += courseCreditHours;
        }
        if (totalCreditHours == 0)
        {
            return 0;
        }
        else
        {
            return (totalGPAPoints / totalCreditHours);
        }
    }
    void printStudentInfo()
    {
        cout << "\n- Name: " << name;
        cout << "\n- ID: " << ID;
        cout << "\n- Level: " << level;
    }
};

#endif