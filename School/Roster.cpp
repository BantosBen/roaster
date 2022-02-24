//
//Author: Salah Arjeh
//Date: 21/11/2021
//

#include <string>
#include <sstream>
#include "Roster.hpp"

using namespace std;

void Roster::parse(string studentdata){
    string id, first_name, last_name, email, dep;
    int age, day1, day2, day3;
    DegreeProgram dt=SOFTWARE;
    stringstream ss (studentdata);
    string item;
    vector<string> processed_data;
    while (getline (ss, item, ',')) {
        processed_data.push_back (item);
    }
    id=processed_data[0];
    first_name=processed_data[1];
    last_name=processed_data[2];
    email=processed_data[3];
    age = stod(processed_data[4]);
    day1 = stod(processed_data[5]);
    day2 = stod(processed_data[6]);
    day3 = stod(processed_data[7]);
    dep=processed_data[8];
    if(dep=="SECURITY"){
        dt=SECURITY;
    }else if(dep=="NETWORK"){
        dt=NETWORK;
    }
    add(id, first_name, last_name, email, age, day1, day2, day3, dt);

}
void Roster::add(string id, string fName, string lName, string email, int age, int day1, int day2, int day3, DegreeProgram dt){
    int day_array[3] = {day1, day2, day3};
    classRosterArray[++lastIndex] = new Student(id, fName, lName, email, age, day_array, dt);
}
void Roster::displayAll(){
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) Roster::classRosterArray[i]->print();
}

void Roster::displayInvalidEmails(){
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = (classRosterArray[i]->getEmail());
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)){
            any = true;
            cout << email << ":" << classRosterArray[i]->getFirst_name() <<  endl;
        }
    }
    if (!any) cout << "NONE" <<  endl;
}


void Roster::displayAverageDays(string id){
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if (classRosterArray[i]->getID()==id)
        {
            int sum=classRosterArray[i]->getDays()[0]+
                     classRosterArray[i]->getDays()[1]+
                     classRosterArray[i]->getDays()[2];
            cout << id << ":";
            cout << sum/3 <<  endl;
        }
    }
}
void Roster::displayByDep(DegreeProgram dt){
    Student::printHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->getDegreeProgram() == dt) classRosterArray[i]->print();
    }
    cout <<  endl;
}

bool Roster::removeStudentByID(string id){
    bool success = false;
    for (int i=0; i <= Roster::lastIndex; i++){
        if (classRosterArray[i]->getID() == id)
        {
            success = true;
            if (i < student_table - 1)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[student_table - 1];
                classRosterArray[student_table - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    if (success)
    {
        cout << id << " removed from records." <<  endl <<  endl;
        this->displayAll();
    }
    else cout << id << " not found." <<  endl <<  endl;;
    return 0;
}

Roster::~Roster(){
    cout << "Destructor executed!" <<  endl <<  endl;
    for (int i=0; i < student_table; i++){
        cout << "Removed student #" << i + 1 <<  endl;
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
Roster::Roster(){
	lastIndex=-1;
}
