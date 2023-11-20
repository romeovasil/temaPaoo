#pragma once
#include "Student.h"


namespace studentnamespace{
    class UniStudent : public Student{
        public:
            UniStudent() = default;
            UniStudent(const char* name, const char* subject);
            void setName(const char *name) override;

    };
}