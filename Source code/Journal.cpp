#include "Journal.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "extraFunction.h"

using namespace std;
#define getenter fflush(stdin);

//////////////////////////////////////////////////////////////////CLASS JOURNAL//////////////////////////////////////////////////////////////////

void Journal ::readf_journal(ifstream &in)
{
    string dummy;
    getline(in, J_id, '|');
    getline(in,J_name,'|');
    getline(in,J_editor,'|');
    getline(in,Publisher_id,',');

}
string Journal ::getID()
{
    return this->J_id;
}
string Journal ::getName() {
    return this->J_name;
}

ostream &operator << (ostream &out, const Journal &j)
{
    out << left << setw(15) << j.J_id << left << setw(50) << j.J_name << left << setw(30) << j.J_editor << left << setw(10);
    out << j.Publisher_id<<endl;
    return out;
}
istream &operator >> (istream &in, Journal &j)
{
    string pub;
    cout << "Nhap ten tap chi: ";
    getenter;
    getline(in,j.J_name);
    removeSpaces(j.J_name);
    cout << "Nhap tong bien tap: ";
    getenter;
    getline(in,j.J_editor);
    cout << "Nhap ma NXB: ";
    in >> pub;
    transform(pub.begin(), pub.end(), pub.begin(), ::toupper);
    j.Publisher_id = pub;
    return in;
}


void Journal::editJournal_Name()
{
    cout << "Nhap moi ten tap chi: ";
    getenter;
    getline(cin,J_name);
}

void Journal::editJournal_Editor()
{
    cout << "Nhap moi ten tong bien tap: ";
    getenter;
    getline(cin,J_editor);
}

void Journal::editJournal_Publisher()
{
    string newPubID;
    cout << "Nhap moi ma NXB: ";
    getenter;
    cin >> newPubID;
    transform(newPubID.begin(), newPubID.end(), newPubID.begin(), ::toupper);
    Publisher_id = newPubID;
}
