//
//Author: Salah Arjeh
//Date: 21/11/2021
//

#ifndef Student_hpp
#define Student_hpp
#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "Degree.h"

using namespace std;

class Student
{
public:
    const static int SIZE = 3;
    const static int COLUMN_SIZE=15;
private:
    string id;
    string first_name;
    string last_name;
    string email;
    int age;
    int days[SIZE];
    DegreeProgram department;
public:
    Student();
    Student(string id, string first_name, string last_name, string email, int age, int days[], DegreeProgram department);
    ~Student();
    string getID();
    string getTitle();
    string getFirst_name();
    string getLast_name();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();
    void setID(string id);
    void setFirst_name(string first_name);
    void setLast_name(string last_name);
    void setEmail(string email);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeProgram(DegreeProgram dt);
    static void printHeader();
    void print();
};



#endif /* Student_hpp */

/*1. Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
 •  student ID
 •  first name
 •  last name
 •  email address
 •  age
 •  array of number of days to complete each course
 •  degree program*/
