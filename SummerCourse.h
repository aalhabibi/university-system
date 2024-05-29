#include <iostream>
#include <string>
#include "Course.h"
using namespace std;


class SummerCourse : public Course{
public:
    SummerCourse() : Course(){}
    SummerCourse( string name, int level, int creditHours ) : Course(name,level,creditHours){
        Code = Name+"_S" + to_string(level);
    }
};