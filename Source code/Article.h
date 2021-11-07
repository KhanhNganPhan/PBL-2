#ifndef ARTICLE_H
#define ARTICLE_H
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
class List;
class Article {
    private:
        string Article_id;
        string Article_name; //Tên bài báo
        string Author_id; //Mã tác giả
        string Journal_id; //Mã tạp chí
        int Publish_time; //Thời gian công bố
        int Time_count =0;    
    public:
    friend class List;
    void readf_Article(ifstream &);
    friend ostream &operator << (ostream &, const Article &);
    friend istream &operator >> (istream &, Article &);
    void editArticle_Name();
    void editArticle_Author();
    void editArticle_Journal();
    void editArticle_Time();
    int getPublish_Time();
    string getArticleName();
    
};


#endif