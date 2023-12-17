#include "Student.h"
#include <iostream>
#include <cstring>

std::mutex olympicTeamMutex;
std::mutex threadsNumMutex;


string Student::olympicTeam[5];
int Student:: threadsNum;


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



void Student:: joinOlympicTeam(){
    pthread_t pthr;

    threadsNumMutex.lock();
    threadsNum++;
    threadsNumMutex.unlock();

    pthread_create(&pthr, NULL, addNameToTeam, this);
    this->olympic = true;
}

void* Student::addNameToTeam(void* arg){
    Student* student = static_cast<Student*> (arg);
    olympicTeamMutex.lock();
    for(int i=0;i<5;i++)
    {
        if(olympicTeam[i].empty()){
            olympicTeam[i] = student->name;
            break;
        }
    }

    olympicTeamMutex.unlock();

    threadsNumMutex.lock();
    threadsNum--;
    threadsNumMutex.unlock();

    return NULL;
}

void Student::showTeam() {
    while(threadsNum != 0);

    for(int i=0; i<5; i++) {
        cout<<" "<<olympicTeam[i]<<" ";
    }

    cout<<endl;
}

