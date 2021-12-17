#include "Article.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "extraFunction.h"
using namespace std;
#define getenter fflush(stdin);

string Article::getArticleName()
{
    return this->Article_name;
}
int Article :: getPublish_Time()
{
    return this->Publish_time;
}
void Article ::readf_Article (ifstream &in) 
{
    string dummy;
    getline(in, Article_id, '|');
    getline(in,Article_name,'|');
    getline(in,Author_id,'|');
    getline(in,Journal_id,'|');
    in >> Publish_time;
    getline(in, dummy, ',');
}
ostream &operator << (ostream &out, const Article &a) 
{
    out << left << setw(15)<<a.Article_id << left << setw(70) << a.Article_name << left << setw(10) <<a.Author_id << left << setw(10);
    out << a.Journal_id << left << setw(10)<< a.Publish_time << endl;
    return out;
}
istream &operator >> (istream &in, Article &a) 
{
    string auth, jou;
    cout << endl  << "- Nhap ten bai bao: ";
    getenter;
    getline(cin, a.Article_name);
    removeSpaces(a.Article_name);
    cout << "- Nhap ma tac gia: ";
    cin >> auth;
    transform(auth.begin(), auth.end(), auth.begin(), ::toupper);
    a.Author_id = auth;
    cout << "- Nhap ma tap chi: ";
    cin >> jou;
    transform(jou.begin(), jou.end(), jou.begin(), ::toupper);
    a.Journal_id = jou;
    cout << "- Nhap thoi gian cong bo: ";
    cin >> a.Publish_time;
    return in;
}
void Article :: editArticle_Name()
{   
    cout << endl << "- Nhap moi ten: ";
    fflush(stdin);
    getline(cin,Article_name);
    removeSpaces(Article_name);
}
void Article :: editArticle_Author()
{   
    string newAuthorID;
    cout << endl << "- Nhap moi ma tac gia: ";
    cin >> newAuthorID;
    transform(newAuthorID.begin(), newAuthorID.end(), newAuthorID.begin(), ::toupper);
    this->Author_id = newAuthorID;
}
void Article :: editArticle_Journal()
{   
    string newJournalID;
    cout << endl << "- Nhap moi ma tap chi: ";
    cin >> newJournalID;
    transform(newJournalID.begin(), newJournalID.end(), newJournalID.begin(), ::toupper);
    this->Journal_id = newJournalID;
}
void Article :: editArticle_Time()
{   
    cout << endl << "- Nhap moi thoi gian cong bo: ";
    cin >> Publish_time;
}
