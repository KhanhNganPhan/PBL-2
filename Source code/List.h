#ifndef LIST_H
#define LIST_H
#include "Author.h"
#include "Article.h"
#include "Journal.h"
#include "Publisher.h"
#include "menu.h"
#include "extraFunction.h"

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
        
    public:
        friend class Article;
        friend class Author;
        friend class Journal;
        int static Author_count;             //Biến đếm tổng số tác giả
        int static Article_count;            //Biến đếm tổng số bài báo
        int static Journal_count;            //Biến đếm tổng số tạp chí
        int static Publisher_count;          //Biến đếm tổng số NXB

        ~List();
        void get_initialNum(ifstream &);                             //Lấy số lượng từ file
        
        void List_getArticle(ifstream &);                            // Lấy dữ liệu từ file Article.txt
        void List_getJournal(ifstream &);                            // Lấy dữ liệu từ file Journal.txt
        void List_getAuthor(ifstream &);                             // Lấy dữ liệu từ file Author.txt
        void List_getPublisher(ifstream &);                          // Lấy dữ liệu từ file Publisher.txt
        
        void List_displayJournal();                                  // In dữ liệu từ file Journal.txt
        void List_displayAuthor();                                   // In dữ liệu ra từ file Author.txt
        void List_displayAll();                                      // In thông tin của tất cả bài báo
        void List_displayPublisher();                                // In dữ liệu từ file Publisher.txt
        
        void List_displayNumofArtPerAuth();                          // Thống kê số lượng bài báo của mỗi tác giả
        void List_displayNumofArtPerJour();                          // Thống kê số lượng bài báo của mỗi tạp chí
        void List_displayNumofArtPerPubl();                          // Thống kê số lượng bài báo của mỗi nhà xuất bản
        void List_displayNumofArtPerYear();                          // Thống kê số lượng bài báo của mỗi năm
        
        bool List_FindArtByAuthID();                               // Tìm kiếm bài của 1 tác giả theo Author ID
        bool List_FindArtByJourID();                              // Tìm kiếm bài của 1 tác giả theo Journal ID
        bool List_FindArtByPublID();                              // Tìm kiếm bài của 1 tác giả theo Publiser ID
        bool List_FindArtByYear();                                // Tìm kiếm bài của 1 tác giả theo năms
        bool List_FindArtByArtID();                               // Tim kiem bai bao theo Article ID
        bool List_FindArticleByName(string);                        //Tìm kiếm bài báo theo tên
        bool List_FindArticleByAuthorName();                        //Tìm kiếm bài báo theo tên tác giả
        
        void List_SortArtByNameAuthor();                             // Sắp xếp bài báo theo tên tác giả
        void List_SortArtByYear(bool (*SS)(Article, Article));       // Sắp xếp bài báo theo theo năm
        void List_SortArtByNameArticle(bool (*SS)(Article, Article));
        string List_getAuthorNamebyID(string);
        string List_getAuthorLastNamebyID(string);
        string List_getJournalNamebyID(string);
        string List_getPublisherIDbyJourID(string);
        
        void List_editArticle(menu);
        void editArticle_General(menu, Article &);
        void List_editAuthor(menu);
        void editAuthor_General(menu, Author &);
        void List_editPublisher();
        void List_editJournal(menu);
        void editJournal_General(menu, Journal &);

        bool List_isNewAuthor(string);
        bool List_isNewJournal(string);
        bool List_isNewPublisher(string); // Khong can thiet vi neu khong co thi cung chang in ra :)
        bool List_isNewArticle(string); //Kiểm tra article mới/cũ
        friend int getAuthorCountfromList();        //Hàm lấy số lượng author cho mỗi đối tượng lớp author

        void List_AddAuthor(string);
        void List_AddArticle(string);
        void List_AddPublisher(string);
        void List_AddJournal(string);

        void List_InsertAuthor(string);
        void List_InsertArticle(string);
        void List_InsertPublisher(string);
        void List_InsertJournal(string);

        void List_overwriteNewAuthor();
        void List_overwriteNewArticle();
        void List_overwriteNewPublisher();
        void List_overwriteNewJournal();
        void List_overwriteInitialNumber();

        void List_DeleteArticleByArtID(string);
        void List_DeleteArticleByPos(int);
        void List_DeleteAuthorByAuthID(string);
        void List_DeleteJournalByJouID(string);
        void List_DeletePublisherByPubID(string);

        void List_UpdateNumArtOfAllList(); //Hàm update số lượng bài báo của List Author, Journal, Publisher
};


#endif