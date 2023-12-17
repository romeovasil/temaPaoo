#pragma once
#include <string>
using namespace std;

class Student {
    private:
        char* name;
        char* subject;
        static int threadsNum;
        static string olympicTeam[5];
        bool olympic;
        static void* addNameToTeam(void *);

    public:
        void display();
        Student();
        Student(const char* name, const char* subject);
        ~Student();
        
        Student(const Student& other); //copy constructor
        Student(Student&& other);  //move constructor

        Student& operator=(const Student& other);
        Student& operator=(Student&& other);
       
        void setSubject(char* subject);
        virtual void setName(const char *str);

        void joinOlympicTeam();
        static void showTeam();
};
