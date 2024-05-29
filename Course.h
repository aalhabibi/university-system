#include <iostream>
#include <string>
#ifndef COURSE_H
#define COURSE_H
using namespace std;


class Course {
protected:
    string Name;
    string Code;
    int MinStudentLevel;
    int CreditHours;
public:
    Course(){
        Name = " ";
        Code = " ";
        MinStudentLevel = 0;
        CreditHours = 0;
    }
    Course(string name, int level, int creditHours){
        Name = name;
        Code=" ";
        MinStudentLevel = level;
        CreditHours= creditHours;
    }
    int getCreditHours(){
        return CreditHours;
    }
    int getMinStudentLevel(){
        return MinStudentLevel;
    }
    string getCode(){
        return Code;
    }

    friend ostream& operator << ( ostream& out,const Course& obj){
        out << "\n\t\t- Course Name: "<< obj.Name<< "\n\t\t- Course Code: "<< obj.Code;
        out << "\n\t\t- Course Level: "<< obj.MinStudentLevel<< "\n\t\t- Course Credit Hours: "<< obj.CreditHours<<endl;
        return out;
    }
};

#endif