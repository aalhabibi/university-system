#include <iostream>
#include <string>
#include "Course.h"
using namespace std;

class NormalCourse : public Course{
public:
    NormalCourse() : Course(){}
    NormalCourse( string name, int level, int creditHours ) : Course(name,level,creditHours){
        Code = Name+"_N" + to_string(level);
    }
};