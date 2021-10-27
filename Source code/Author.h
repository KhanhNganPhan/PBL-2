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
        string firstName;   //Họ và tên đệm
        string lastName;    //Tên
        string work;    //Nơi công tác
        string field;   //Lĩnh vực làm việc
        string degree;  //trình độ
        string author_id;   //Mã tác giả
        int Article_count; //Biến đếm số bài báo của một tác giả
        float ranking;
    public:
    friend class List;
    Author();
    Author(string, string, string, string, string, string);
    ~Author();
    void readf_author(ifstream &in);
    string getName();
    string getID();
    friend istream &operator >> (istream &, Author &);
    friend ostream &operator << (ostream &, const Author &);

};

#endif