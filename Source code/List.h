#ifndef LIST_H
#define LIST_H
#include "Author.h"
#include "Article.h"
#include "Journal.h"
#include "Publisher.h"

class List {
    private:
        Author *Author;
        Article *Article;
        Journal *Journal;
        Publisher *Publisher;
        int static Author_count;             //Biến đếm tổng số tác giả
        int static Article_count;            //Biến đếm tổng số bài báo
        int static Journal_count;            //Biến đếm tổng số tạp chí
        int static Publisher_count;          //Biến đếm tổng số NXB
    public:
        List();
        ~List();
        void List_getdata(ifstream &, ifstream &, ifstream &, ifstream &);
        

};


#endif