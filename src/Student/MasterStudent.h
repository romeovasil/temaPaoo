#pragma once
#include "Student.h"


namespace studentnamespace{
    class MasterStudent : public Student{
        public:
            MasterStudent() = default;
            MasterStudent(const char* name, const char* subject);
            void setName(const char *name) override;

    };
}