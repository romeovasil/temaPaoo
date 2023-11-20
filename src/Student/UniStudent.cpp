#include <cstring>
#include "UniStudent.h"
#include <string> 

namespace studentnamespace{
    UniStudent::UniStudent(const char* name, const char* subject) 
        : Student((std::string("uni") + name ).data(), subject) {}


    void UniStudent::setName(const char* name){
            Student::setName((std::string("uni") + name ).data());
        }
}