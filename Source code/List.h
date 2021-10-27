#ifndef LIST_H
#define LIST_H
#include "Author.h"
#include "Article.h"
#include "Journal.h"
#include "Publisher.h"
// Forward declaration class Publisher
class Publisher;
class List {
    private:
        Author *Auth;
        Article *Art;
        Journal *Jou;
        Publisher *Pub;
        int static Author_count;             //Biến đếm tổng số tác giả
        int static Article_count;            //Biến đếm tổng số bài báo
        int static Journal_count;            //Biến đếm tổng số tạp chí
        int static Publisher_count;          //Biến đếm tổng số NXB
    public:
        friend class Publisher;
        //List();
        ~List();
        void get_initialNum(ifstream &);
        void List_getPublisher(ifstream &);
        void List_displayPublisher();
        void List_getArticle(ifstream &);
        void List_displayArticle();
        void List_getJournal(ifstream &);
        void List_displayJournal();
        void List_getAuthor(ifstream &);
        void List_displayAuthor();
        void List_displayAll();
        string List_getAuthorNamebyID(string );

};


#endif