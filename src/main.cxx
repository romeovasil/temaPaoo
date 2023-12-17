#include <iostream>
#include "Student.h"
#include "UniStudent.h"
#include "MasterStudent.h"

using namespace studentnamespace;

int main(){

    // Student s1("Romeo","PAOO");
    // Student s2("Andrei","CHS");

    // std::cout<<"Initial students"<<'\n';
    // s1.display();
    // s2.display();


    // Student s3 = s1; // folosim copy constructor 
    // s3.display();

    // Student s4 = std::move(s2); // move constructor 
    // // s4.display();


    // s1.~Student();


    // Student st;
    // UniStudent unist("Romeo","VVS");
    // MasterStudent masterst("Romeo","paoo");
    // UniStudent unist2;

    // unist2 = unist;
    // unist.display();
    // unist2.display();


    Student s1("Romeo","PAOO");
    UniStudent unist("Romeo","VVS");
    MasterStudent masterst("Romeo","paoo");


    s1.display();
    unist.display();
    masterst.display();

    s1.joinOlympicTeam();
    unist.joinOlympicTeam();


    cout<<endl<<"Olympic team: ";
    Student::showTeam();
    cout<<endl;
}