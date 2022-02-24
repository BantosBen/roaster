//
//Author: Salah Arjeh
//Date: 21/11/2021
//

#include <iostream>
#include "Roster.hpp"

using namespace std;
void printMeFirst();
int main()
{
	printMeFirst();
    const string student_data[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Salah,Arjeh,salaharjeh@gmail.com,18,20,30,20,SOFTWARE"
        };
    const int student_table = 5;
    Roster roster;

    for (int i = 0; i < student_table; i++) roster.parse(student_data[i]);
    cout << "All students:" <<  endl;
    roster.displayAll();
    cout <<  endl;

    cout << "All SOFTWARE students:" <<  endl;
    roster.displayByDep(SOFTWARE);
    cout <<  endl;

    cout << "All NETWORK students:" <<  endl;
    roster.displayByDep(NETWORK);
    cout <<  endl;

    cout << "All SECURITY students:" <<  endl;
    roster.displayByDep(SECURITY);
    cout <<  endl;

    cout << "Invalid email address: " <<  endl;
    roster.displayInvalidEmails();
    cout <<  endl;

    cout << "Average days per class:" <<  endl;
    for (int i = 0; i < student_table; i++){
        roster.displayAverageDays(roster.classRosterArray[i]->getID());
    }
    cout <<  endl;

    cout << "Remove student with ID A3." <<  endl;
    roster.removeStudentByID("A3");
    cout <<  endl;

    cout << "Remove student A3." <<  endl;
    roster.removeStudentByID("A3");
    cout <<  endl <<  endl;
	string userInput;
	cin>>userInput;
	return 0;

}

void printMeFirst(){
	cout<<"WGU Student ID: #006852527"<<endl;
	cout<<"Student Name: Salah Arjeh"<<endl;
	cout<<"Course Title: C867"<<endl;
	cout<<"Programming Language: C++\n"<<endl;

}

