#ifndef JOURNAL_H
#define JOURNAL_H
#include <iostream>
#include <string.h>
#include "Article.h"
using namespace std;

class Journal {
    private:
        string J_name; //Tên tạp chí
        string J_id; //Mã tạp chí
        string J_editor; //Tên tổng biên tập
        string Publisher_id; //Mã NXB
        int Article_count; //Biến đếm số bài báo của một tạp chí

    public:
    void readf_journal(ifstream &in);
    friend istream &operator >> (istream &, Journal &);
    friend ostream &operator << (ostream &, const Journal &);

};


#endif