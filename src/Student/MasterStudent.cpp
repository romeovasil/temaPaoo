#include <cstring>
#include "MasterStudent.h"
#include <string> 

namespace studentnamespace{
    MasterStudent::MasterStudent(const char* name, const char* subject) 
        : Student((std::string("master") + name ).data(), subject) {}


    void MasterStudent::setName(const char* name){
            Student::setName((std::string("uni") + name ).data());
        }
}