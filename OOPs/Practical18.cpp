#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>

using namespace std;

void filter_blank_spaces(ifstream &in_stream, ofstream &out_stream);

int main()
{
    ifstream fin;
    ofstream fout;

    fin.open("input.txt");

    if (fin.fail())
    {
        cout << "Input file could not be opened.\n";
        exit(1);
    }

    fout.open("output.txt");

    if (fout.fail())
    {
        cout << "Output file could not be opened.\n";
        exit(1);
    }

    string s;
    while (fin >> s)
    {
        fout << s;
    }

    fin.close();
    fout.close();
    cout << "Done.\n";

    return 0;
}