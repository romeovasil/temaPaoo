#include "Student.h"
#include <iostream>
#include <cstring>

Student::Student(){
    name = new char[strlen("DefaultName") + 1];
    strcpy(this->name,"DefaultName");
    subject = new char[strlen("DefaultSubject") + 1];
    strcpy(this->subject,"DefaultSubject");
    std::cout<<"Default:  "<<this->name<<'\n';
}

Student::Student(const char* n, const char* s){
            name = new char[strlen(n) + 1];
            strcpy(this->name,n);
            subject = new char[strlen(s) + 1];
            strcpy(this->subject,s);
        }

void Student::display(){
            std::cout<<"Nume: "<<name<<", Subject: "<<subject<<"\n\n";
        }
Student::~Student(){
            delete[] name;
            delete[] subject;
        }


//suprascriem copy constructorul
Student::Student(const Student& other){
            //trebuie creata o zona noua de memorie in heap pentru a copia
            name = new char[strlen(other.name) + 1];
            strcpy(this->name,other.name);
            subject = new char[strlen(other.subject) + 1];
            strcpy(this->subject,other.subject);
        }

// suprasc move const
Student::Student(Student&& other){
            name = other.name;
            subject = other.subject;
            other.name = nullptr;
            other.subject = nullptr; 
        }
void Student::setName(const char* name){
            this->name = new char[strlen(name) + 1];
            strcpy(this->name,name);
        }
void Student::setSubject(char* subject){
            this->subject = new char[strlen(subject) + 1];
            strcpy(this->subject,subject);
        }


Student& Student::operator=(const Student& other) {
      if( this != &other){
            name = new char[strlen(other.name) + 1];
            strcpy(this->name,other.name);
            subject = new char[strlen(other.subject) + 1];
            strcpy(this->subject,other.subject);
    }
            return *this;
}

Student& Student::operator=(Student&& other){

        if(this != &other){
            name = other.name;
            subject = other.subject;
            other.name = nullptr;
            other.subject = nullptr; 
        }

        return *this;
}