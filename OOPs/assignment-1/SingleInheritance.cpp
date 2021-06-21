#include <iostream>

using namespace std;

class Vehicle
{

public:
    void refuel()
    {
        cout << "Refueling.....100%" << endl;
    }
};

class Car : public Vehicle
{
public:
    Car()
    {
        cout << "A car is deployed." << endl;
    }

    void start()
    {
        cout << "Engine started." << endl;
    }
};

int main()
{
    Car audi;

    audi.refuel();
    audi.start();

    return 0;
}