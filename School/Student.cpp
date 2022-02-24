//
//Author: Salah Arjeh
//Date: 21/11/2021
//

#include "Student.hpp"
#include "Degree.h"

Student::Student(){
    this->id = "";
    this->first_name = "";
    this->last_name = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < SIZE; i++) this->days[i] = 0;
    this->department = DegreeProgram::SECURITY;
}

Student::Student(string id, string first_name, string last_name, string email, int age, int days[], DegreeProgram department){
    this->id = id;
    this->first_name = first_name;
    this->last_name = last_name;
    this-> email = email;
    this->age = age;
    for (int i = 0; i < SIZE; i++) this ->days[i] = days[i];
    this ->department = department;
}

Student::~Student() {}
string Student::getID() {return this->id;}
string Student::getEmail() {return this->email;}
int Student::getAge() {return this->age;}
int* Student::getDays() {return this->days;}
string Student::getFirst_name() {return this->first_name;}
string Student::getLast_name() {return this->last_name;}
DegreeProgram Student::getDegreeProgram(){return this->department;}
void Student::setLast_name(string last_name){this->last_name = last_name;}
void Student::setEmail(string email){this->email = email;}
void Student::setAge(int age){ this->age = age;}
void Student::setID(string id){this->id = id;}
void Student::setFirst_name(string first_name) {this->first_name = first_name;}
void Student::setDays(int days[]){
    for (int i = 0; i <SIZE; i++) this ->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram dt) {this ->department = dt;}

void Student::printHeader(){
    cout << "ID" << '\t' << "First" << '\t' <<"Last" << '\t' << "Email Address" << '\t' << "Age" << '\t'<< "Days to Complete" << '\t'<< "Degree" << std::endl;
}

void Student::print(){
    cout << this->getID() << '\t';
    cout << this->getFirst_name() << '\t';
    cout << this->getLast_name() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << degree_program_values[this->getDegreeProgram()] << '\n';
}
