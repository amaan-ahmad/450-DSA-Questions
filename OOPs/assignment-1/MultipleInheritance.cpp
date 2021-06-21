#include <iostream>

using namespace std;

class User
{
private:
    int id;

public:
    User()
    {
        id = 100; // any random id
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

int main()
{
    Teacher mam;

    mam.getID();
    mam.addStudent();

    return 0;
}