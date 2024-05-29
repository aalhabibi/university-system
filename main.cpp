#include <iostream>
#include <string>
#include "Student.h"
#include "SpecialStudent.h"
#include "GeneralStudent.h"
#include "Course.h"
#include "NormalCourse.h"
#include "SummerCourse.h"

using namespace std;

static Course *COURSES[] = {new NormalCourse("Math", 1, 2),
                            new NormalCourse("Programming_1", 1, 3),
                            new NormalCourse("Technical_Writing", 1, 3),
                            new NormalCourse("Electronics", 2, 4),
                            new NormalCourse("Data_Structures", 2, 3),
                            new NormalCourse("OOP", 2, 3),
                            new NormalCourse("Algorithms", 3, 2),
                            new NormalCourse("Operating_Systems", 3, 3),
                            new NormalCourse("Databases", 3, 3),
                            new NormalCourse("Machine_Learning", 4, 3),
                            new NormalCourse("Compilers", 4, 4),
                            new NormalCourse("Programming_Concepts", 4, 4),
                            new SummerCourse("Math", 1, 2),
                            new SummerCourse("Compilers", 4, 4),
                            new SummerCourse("Algorithms", 3, 2),
                            new SummerCourse("OOP", 2, 3)};

Course *searchCourse(string code)
{
    for (int i = 0; i < 16; ++i)
    {
        if (COURSES[i]->getCode() == code)
        {
            return COURSES[i];
        }
    }
    return nullptr;
}

int main()
{

    int noOfStudents = 0;
    cout << "Enter total number of students: ";
    cin >> noOfStudents;
    Student *studentArr[noOfStudents];
    for (int i = 0; i < noOfStudents; ++i)
    {
        int studentType, level, noOfCourses;
        string name, ID;
        cout << "For student " << i + 1 << ": \n";
        cout << "\t- Enter student type (0: general, 1: special): ";
        cin >> studentType;
        if (!(studentType == 1 || studentType == 0))
        {
            cout << "\n Invalid choice of student type!\n";
            --i;
            continue;
        }

        cout << "\t- Enter name: ";
        cin >> name;
        cout << "\t- Enter ID: ";
        cin >> ID;
        cout << "\t- Enter student level:";
        cin >> level;

        while (true)
        {
            cout << "\t- Number of courses to be registered: ";
            cin >> noOfCourses;
            if (noOfCourses > 6)
                cout << "Can't register more than 6 courses\n";

            else
                break;
        }
        switch (studentType)
        {
        case 1:
            studentArr[i] = new SpecialProgramStudent(level, noOfCourses, name, ID);
            break;
        case 0:
            studentArr[i] = new GeneralProgramStudent(level, noOfCourses, name, ID);

            break;
        default:
        {
            cout << "\n Invalid choice of student type!\n";
            break;
        }
        }

        cout << "\t- Courses to be registered: \n";

        for (int j = 0; j < noOfCourses; ++j)
        {

            string courseCode;
            Course *requiredCourse;
            cout << "\t\t- Course " << j + 1 << " :";
            cout << "\n\t\t\t- Code: ";
            cin >> courseCode;

            requiredCourse = searchCourse(courseCode);

            if (requiredCourse == nullptr)
            {
                cout << "\t\t\tCourse not found" << endl;
                --j;

                continue;
            }
            if (studentArr[i]->RegisterCourse(requiredCourse))
            {
                continue;
            }
            else
            {
                cout << "\t\t\tCourse not registered.\n";
                --j;

                continue;
            }
        }
    }
    for (int i = 0; i < noOfStudents; ++i)
    {
        studentArr[i]->printStudentInfo();
        studentArr[i]->printRegisteredCourses();
        cout << "\n- Overall GPA: " << studentArr[i]->getTotalGPA();
        cout << "\n- Student expenses: " << studentArr[i]->CalculateExpenses();
        cout << endl
             << endl;
    }

    return 0;
}
