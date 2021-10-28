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
        void List_getPublisher(ifstream &); // Lấy dữ liệu từ file Publisher.txt
        void List_displayPublisher(); // In dữ liệu từ file Publisher.txt
        void List_getArticle(ifstream &); // Lấy dữ liệu từ file Article.txt
        void List_displayArticle(); // In dữ liệu từ file Article.txt
        void List_getJournal(ifstream &); // Lấy dữ liệu từ file Journal.txt
        void List_displayJournal(); // In dữ liệu từ file Journal.txt
        void List_getAuthor(ifstream &); // Lấy dữ liệu từ file Author.txt
        void List_displayAuthor(); // In dữ liệu ra từ file Author.txt
        void List_displayAll(); // In thông tin của tất cả bài báo
        void List_displayNumofArtPerAuth(); // Thống kê số lượng bài báo của mỗi tác giả
        void List_displayNumofArtPerJour(); // Thống kê số lượng bài báo của mỗi tạp chí
        void List_displayNumofArtPerPubl(); // Thống kê số lượng bài báo của mỗi nhà xuất bản
        void List_displayNumofArtPerYear(); // Thống kê số lượng bài báo của mỗi năm
        string List_getAuthorNamebyID(string);
        string List_getJournalNamebyID(string);
        string List_getPublisherIDbyJourID(string);

};


#endif