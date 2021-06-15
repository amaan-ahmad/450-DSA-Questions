#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>

using namespace std;

class Str
{
private:
    string value;

public:
    Str(string input_string)
    {
        value = input_string;
    }

    Str()
    {
        value = "";
    }

    friend Str operator+(Str const &, Str const &);
    friend Str operator&=(Str &, Str const &);
    friend void printStr(Str const &);
    friend bool operator<=(Str const &, Str const &);
    int length();
    void toLower();
    void toUpper();
};

Str operator+(Str const &s1, Str const &s2)
{
    return Str(s1.value + s2.value);
}

Str operator&=(Str &a, Str const &b)
{
    a.value = b.value;
    return a;
}

void printStr(Str const &s)
{
    cout << s.value;
}

bool operator<=(Str const &a, Str const &b)
{
    return a.value <= b.value;
}

int Str::length()
{
    return value.length();
}

void Str::toLower()
{
    transform(value.begin(), value.end(), value.begin(), ::tolower);
}

void Str::toUpper()
{
    transform(value.begin(), value.end(), value.begin(), ::toupper);
}

int main()
{

    Str a("abc");
    Str b("xyz");
    Str c(a + b);

    cout << "value of c: ";
    printStr(c);
    cout << endl;

    cout << "value of a: ";
    printStr(a);
    cout << endl;

    cout << "value of b: ";
    printStr(b);
    cout << endl;

    a &= b;

    cout << "value of \'a\' after operation: ";
    printStr(a);
    cout << endl;

    cout << "Comparision of a <= b: ";
    cout << (a <= b);
    cout << endl;

    cout << "Length of a: ";
    cout << a.length();
    cout << endl;

    cout << "uppercase of a: ";
    a.toUpper();
    printStr(a);
    cout << endl;

    cout << "turning back to lowercase of a: ";
    a.toLower();
    printStr(a);
    cout << endl;

    return 0;
}
