#ifndef LIST_H
#define LIST_H
#include "Author.h"
#include "Article.h"
#include "Journal.h"
#include "Publisher.h"

class Publisher;                            // Forward declaration class Publisher
class Article;                              // Forward declaration class Article
class Author;                               // Forward declaration class Author
class Journal;                              // Forward declaration class Journal

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
        // friend class Publisher;
        // friend class Article;
        // friend class Author;
        // friend class Journal;

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
        string List_getAuthorNamebyID(string);
        string List_getJournalNamebyID(string);

};


#endif