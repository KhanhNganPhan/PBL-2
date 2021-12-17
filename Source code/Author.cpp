#include "Author.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.h"
using namespace std;
#define getenter fflush(stdin);

//////////////////////////////////////////////////////////////////CLASS AUTHOR//////////////////////////////////////////////////////////////////
Author ::Author() 
{}
Author ::Author(const Author &a)
    : firstName(a.firstName), lastName(a.lastName), work(a.work), field(a.field), degree(a.degree), author_id(a.author_id)
{

}

Author :: ~Author()
{

}
string Author ::getLastName()
{
    return this->lastName;
}

string Author ::getName()
{
    string fullname = firstName + " " + lastName;
    return (fullname);
}

string Author ::getID()
{
    return this->author_id;
}

void Author ::readf_author(ifstream &in)
{
    string dummy;
    getline(in,author_id, '|');
    getline(in,firstName,'|');
    getline(in,lastName,'|');
    getline(in,work,'|');
    getline(in,field,'|');
    getline(in,degree,',');
}

ostream &operator << (ostream &out, const Author &a) 
{
    out << left << setw(15) << a.author_id  << left << setw(20) << a.firstName << left << setw(15)<< a.lastName << left << setw(15);
    out << a.work << left << setw(30) << a.field << left << setw(10) << a.degree << endl;
    return out;
}

istream &operator >> (istream &in, Author &a) 
{
    cout << endl << "- Nhap ho dem: "; 
    getenter;
    getline(cin, a.firstName);
    removeSpaces(a.firstName);
    cout << "- Nhap ten: ";
    cin >> a.lastName;
    removeSpaces(a.lastName);
    cout << "- Nhap noi cong tac: (DH__) ";
    cin >> a.work;
    cout << "- Nhap linh vuc nghien cuu: ";
    getenter;
    getline(cin, a.field);
    cout << "- Nhap trinh do: ";
    getenter;
    getline(cin,a.degree);
    return in;
}

void Author::editAuthor_Name()
{
    cout << endl <<"- Nhap ho va ten dem: ";
    getenter;
    getline(cin,firstName);
    removeSpaces(firstName);
    cout << "- Nhap ten: ";
    getenter;
    getline(cin,lastName);
    removeSpaces(lastName);
}

void Author::editAuthor_Work()
{
    cout << endl << "- Nhap moi noi cong tac: ";
    getenter;
    getline(cin,work);
}

void Author::editAuthor_Field()
{
    cout << endl << "- Nhap moi linh vuc lam viec: ";
    getenter;
    getline(cin,field);
}

void Author::editAuthor_Degree()
{
    cout << endl << "- Nhap moi trinh do: ";
    getenter;
    getline(cin,degree);
}