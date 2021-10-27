#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include "Author.h"
#include "Journal.h"
#include "Article.h"
#include "Publisher.h"
#include "List.h"
using namespace std;

//class author
Author ::Author() 
{}
Author ::Author(string fn, string ln, string w, string f, string d, string id)
    : firstName(fn), lastName(ln), work(w), field(f), degree(d), author_id(id) 
{

}

Author :: ~Author()
{

}

void Author ::readf_author(ifstream &in){
    string dummy;
    getline(in,dummy,'\n');         //lấy dòng đầu
    getline(in, author_id, '|');
    getline(in,firstName,'|');
    getline(in,lastName,'|');
    getline(in,work,'|');
    getline(in,field,'|');
    getline(in,degree);
    getline(in,dummy,'\n');         //xuống dòng
}

ostream &operator << (ostream &out, const Author &a) {
    out << a.author_id  << setw(20) << a.firstName << setw(5) << a.lastName << setw(5) << a.work;
    out << a.field << setw(5) << a.degree << endl;
    return out;
}

//class journal
void Journal ::readf_journal(ifstream &in){
    string dummy;
    getline(in,dummy,'\n');          //lấy dòng đầu
    getline(in, J_id, '|');
    getline(in,J_name,'|');
    getline(in,J_editor,'|');
    getline(in,Publisher_id);
    getline(in,dummy,'\n');          //xuống dòng
}

ostream &operator << (ostream &out, const Journal &j){
    out << j.J_id << setw(10) << j.J_name << setw(5) << j.J_editor << setw(5) << j.Publisher_id;
    out << endl;
    return out;
}

//class Article
void Article ::readf_Article (ifstream &in) {
    string dummy;
    getline(in,dummy,'\n');          //lấy dòng đầu
    getline(in, Article_id, '|');
    getline(in,Article_name,'|');
    getline(in,Author_id,'|');
    getline(in,Journal_id,'|');
    getline(in,Publish_time);
    getline(in,dummy,'\n');          //xuống dòng
}

ostream &operator << (ostream &out, const Article &a) {
    out << a.Article_id << setw(60) << a.Article_name << a.Author_id << a.Journal_id;
    out << a.Publish_time << endl;
    return out;
}

//class Publisher
void Publisher::readf_Publisher(ifstream &in) {
    string dum;                         //dum là kí tự |
    getline(in, Publisher_id,' ');
    getline(in,dum,'|');                //Lấy kí tự |
    getline(in,Publisher_name,',');
}

ostream &operator << (ostream &out, const Publisher &p) {
    out << p.Publisher_id << setprecision(15) << p.Publisher_name << endl;
    return out;
}

//class List
int List::Author_count = 0;                 //Biến static đếm tổng số tác giả
int List::Article_count = 0;                //Biến static đếm tổng số bài báo
int List::Journal_count = 0;                //Biến static đếm tổng số tạp chí
int List::Publisher_count = 0;              //Biến static đếm tổng số NXB

List::~List() {
    delete []Art;
    delete []Auth;
    delete []Jou;
    delete []Pub;
}
//được rồi chạy thử đi xong bỏ dòng cout
void List::get_initialNum(ifstream &inFile) {
    string ArtNum, AuthNum, JouNum, PubNum;
    string dummyName;
    getline(inFile,dummyName,'|');
    getline(inFile,ArtNum,'\n');                //Lấy số lượng bài báo hiện tại
    getline(inFile,dummyName,'|');
    getline(inFile,AuthNum,'\n');               //Lấy số lượng tác giả hiện tại
    getline(inFile,dummyName,'|');
    getline(inFile,JouNum,'\n');                //Lấy số lượng tạp chí hiện tại
    getline(inFile,dummyName,'|');
    getline(inFile,PubNum);                     //Lấy số lượng NXB hiện tại
    Article_count = atoi(ArtNum.c_str());
    Author_count = atoi(AuthNum.c_str());
    Journal_count = atoi(JouNum.c_str());
    Publisher_count = atoi(PubNum.c_str());
    cout << Article_count << Author_count << Journal_count << Publisher_count;
}

void List::List_getPublisher(ifstream &inFile) {
    string dummy;
    getline(inFile,dummy,'\n');
    this->Pub= new Publisher[4];
    for (int i=0; i<3; i++) 
    {
        string dummy2;
        Pub[i].readf_Publisher(inFile);
        getline(inFile,dummy2,'\n');            //xuống dòng
    }
}
ostream &operator << (ostream &out, const List &L) {
    for (int i=0; i<3; i++)
    out<< L.Pub[i];
    return out;
}

