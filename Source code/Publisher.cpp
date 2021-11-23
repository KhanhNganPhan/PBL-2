#include "Publisher.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#define getenter fflush(stdin);


using namespace std;
//////////////////////////////////////////////////////////////////CLASS PUBLISHER//////////////////////////////////////////////////////////////////

void Publisher::readf_Publisher(ifstream &in) 
{
    string dum;                         //dum là kí tự |
    getline(in,Publisher_id,'|');       //Lấy kí tự |
    getline(in,Publisher_name,',');
}

ostream &operator << (ostream &out, const Publisher &p) 
{
    out << left << setw (15) << p.Publisher_id << p.Publisher_name << endl;
    return out;
}

istream &operator >> (istream &in, Publisher &p) 
{
    cout << "Nhap ten NXB: ";
    getenter;
    getline(in,p.Publisher_name);
    return in;
}

void Publisher::editPublisher_Name()
{
    cout << "Nhap moi ten NXB: ";
    getenter;
    getline(cin, Publisher_name);
}