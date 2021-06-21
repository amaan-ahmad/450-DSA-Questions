#include <iostream>
#include <stdlib.h>

using namespace std;

class User
{
private:
    int id;

public:
    User()
    {
        id = rand(); // any random id
    }

    void getID()
    {
        cout << "My ID is: " << id << endl;
    }
};

class Admin : public User
{
public:
    void addStudent()
    {
        cout << "Added a student. " << endl;
    }

    Admin()
    {
        cout << "I am an Admin." << endl;
    }
};

class Teacher : public Admin
{
public:
    Teacher()
    {
        cout << "I am a teacher." << endl;
    }
};

class Student : public User
{
public:
    void submitAssignment()
    {
        cout << "Assignment submitted, kindly award full marks :) " << endl;
    }
    Student()
    {
        cout << "I am a student." << endl;
    }
};

int main()
{
    Teacher mam;
    Student kid;

    mam.getID();
    mam.addStudent();

    kid.getID();
    kid.submitAssignment();

    return 0;
}