//
//Author: Salah Arjeh
//Date: 21/11/2021
//

#pragma once
#include "Student.hpp"
#ifndef Roster_hpp
#define Roster_hpp
#include <stdio.h>
#include <vector>

class Roster
{
public:
    int lastIndex;
    const static int student_table = 5;
    Student* classRosterArray[student_table];

public:
    void parse(string row);
    void add(string id,
             string first_name,
             string last_name,
             string email,
             int age,
             int day1,
             int day2,
             int day3,
             DegreeProgram dt);
    void displayAll();
    void displayByDep(DegreeProgram dt);
    void displayInvalidEmails();
    void displayAverageDays(string id);
    bool removeStudentByID(string id);
    ~Roster();
	Roster();
};


#endif /* Roster_hpp */
