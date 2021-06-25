#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

class Student
{
private:
    int id, age;
    float weight, height;
    char gender;
    string name;

public:
    Student()
    {
    }
    Student(string name, int age, float height, char gender, float weight)
    {
        id = rand();
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->height = height;
        this->weight = weight;
    }
    void info()
    {
        cout << "ID: " << this->id << endl;
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Gender: " << this->gender << endl;
        cout << "Height: " << this->height << endl;
        cout << "Weight: " << this->weight << endl;
        cout << "\n --------------------------------- \n";
    }
};

int main()
{
    Student st("Amaan", 23, 170.4, 'M', 75.6);
    ofstream outfile;
    ifstream infile;

    outfile.open("file.dat", ios::app | ios::out | ios::ate);

    if (!outfile)
    {
        cout << "\'file.dat\' not found";
        return -1;
    }

    outfile.write((char *)&st, sizeof(st));
    outfile.close();

    infile.open("file.dat", ios::in);

    Student tmp;
    while (!infile.eof())
    {
        infile.read((char *)&tmp, sizeof(tmp));
        tmp.info();
    }

    infile.close();

    return 0;
}