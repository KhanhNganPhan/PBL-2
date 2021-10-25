#include <iostream>
#include <fstream>
#include <iomanip>
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
    string dummy;
    getline(in,dummy,'\n');            //lấy dòng đầu
    getline(in, Publisher_id, '|');
    getline(in,Publisher_name);
    getline(in,dummy,'\n');            //xuống dòng
}

ostream &operator << (ostream &out, const Publisher &p) {
    out <<p.Publisher_id << setw(5) << p.Publisher_name << endl;
    return out;
}

//class List
int List::Author_count = 0;                 //Biến static đếm tổng số tác giả
int List::Article_count = 0;                //Biến static đếm tổng số bài báo
int List::Journal_count = 0;                //Biến static đếm tổng số tạp chí
int List::Publisher_count = 0;              //Biến static đếm tổng số NXB

List::~List() {

}

void List::List_getdata(ifstream &AuInFile, ifstream &ArtInFile, ifstream &JouInFile, ifstream &PubInFile) {
    
}
