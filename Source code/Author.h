#ifndef AUTHOR_H
#define AUTHOR_H
#include <iostream>
#include <string.h>
#include <fstream>
#include "Article.h"
using namespace std;
class List;
class Author
{
    private:
        string author_id;   //Mã tác giả
        string firstName;   //Họ và tên đệm
        string lastName;    //Tên
        string work;    //Nơi công tác
        string field;   //Lĩnh vực làm việc
        string degree;  //trình độ
        int Article_count = 0; //Biến đếm số bài báo của một tác giả
        float ranking;
    public:
    friend class List;
    Author();
    Author(const Author &);
    ~Author();
    void readf_author(ifstream &in);
    string getLastName();
    string getName();
    string getID();
    friend istream &operator >> (istream &, Author &);
    friend ostream &operator << (ostream &, const Author &);
    void editAuthor_Name();
    void editAuthor_Work();
    void editAuthor_Field();
    void editAuthor_Degree();

};

#endif