#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
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
string Author ::getName()
{
    string fullname = firstName + " " + lastName;
    return (fullname);
}
string Author ::getID()
{
    return this->author_id;
}
void Author ::readf_author(ifstream &in){
    string dummy;
    getline(in,author_id, '|');
    getline(in,firstName,'|');
    getline(in,lastName,'|');
    getline(in,work,'|');
    getline(in,field,'|');
    getline(in,degree,',');
}

ostream &operator << (ostream &out, const Author &a) {
    out << left << setw(15) << a.author_id  << left << setw(20) << a.firstName <<left << setw(15)<< a.lastName << left << setw(15) << a.work <<left << setw(30)<< a.field << left << setw(10) << a.degree << endl;
    return out;
}

//class journal
void Journal ::readf_journal(ifstream &in){
    string dummy;
    getline(in, J_id, '|');
    getline(in,J_name,'|');
    getline(in,J_editor,'|');
    getline(in,Publisher_id,',');

}
string Journal ::getID()
{
    return this->J_id;
}
string Journal ::getName() {
    return this->J_name;
}

ostream &operator << (ostream &out, const Journal &j){
    out <<left << setw(15) << j.J_id <<left << setw(50) << j.J_name << left << setw(30) << j.J_editor << left << setw(10) << j.Publisher_id<<endl;

    return out;
}

//class Article
void Article ::readf_Article (ifstream &in) {
    string dummy;
    getline(in, Article_id, '|');
    getline(in,Article_name,'|');
    getline(in,Author_id,'|');
    getline(in,Journal_id,'|');
    getline(in,Publish_time,',');
}

ostream &operator << (ostream &out, const Article &a) {
    out <<left <<setw(15)<<a.Article_id << left <<setw(70) << a.Article_name <<left <<setw(10) <<a.Author_id << left <<setw(10) << a.Journal_id <<left <<setw(10)<< a.Publish_time << endl;
    return out;
}


//class Publisher
void Publisher::readf_Publisher(ifstream &in) {
    string dum;                         //dum là kí tự |
    getline(in,Publisher_id,'|');       //Lấy kí tự |
    getline(in,Publisher_name,',');
}

ostream &operator << (ostream &out, const Publisher &p) {
    out <<left << setw (15) << p.Publisher_id << p.Publisher_name << endl;
    return out;
}

//class List
int List::Author_count = 0;                 //Biến static đếm tổng số tác giả
int List::Article_count = 0;                //Biến static đếm tổng số bài báo
int List::Journal_count = 0;                //Biến static đếm tổng số tạp chí
int List::Publisher_count = 0;              //Biến static đếm tổng số NXB

List::~List() {
    delete []Art;
    delete []Auth;
    delete []Jou;
    delete []Pub;
}
//được rồi chạy thử đi xong bỏ dòng cout
void List::get_initialNum(ifstream &inFile) {
    string ArtNum, AuthNum, JouNum, PubNum;
    string dummyName;
    getline(inFile,dummyName,'|');
    getline(inFile,ArtNum,'\n');                //Lấy số lượng bài báo hiện tại
    getline(inFile,dummyName,'|');
    getline(inFile,AuthNum,'\n');               //Lấy số lượng tác giả hiện tại
    getline(inFile,dummyName,'|');
    getline(inFile,JouNum,'\n');                //Lấy số lượng tạp chí hiện tại
    getline(inFile,dummyName,'|');
    getline(inFile,PubNum);                     //Lấy số lượng NXB hiện tại
    Article_count = atoi(ArtNum.c_str());
    Author_count = atoi(AuthNum.c_str());
    Journal_count = atoi(JouNum.c_str());
    Publisher_count = atoi(PubNum.c_str());
}

void List::List_getPublisher(ifstream &inFile) {
    string dummy;
    getline(inFile,dummy,'\n');
    this->Pub= new Publisher[Publisher_count];
    for (int i=0; i<Publisher_count; i++) 
    {
        string dummy2;
        Pub[i].readf_Publisher(inFile);
        getline(inFile,dummy2,'\n');            //xuống dòng
    }
}
void List::List_displayPublisher()
{

    cout<<left << setw (15) <<"Ma NXB"<< "Ten NXB" << endl;
    for(int i =0;i < Publisher_count;i++)
    {
        cout<< Pub[i];
    }
}
void List::List_getArticle(ifstream &inFile)
{
    string dummy;
    getline(inFile,dummy,'\n');
    this->Art= new Article[Article_count];
    for (int i=0; i<Article_count; i++) 
    {
        string dummy2;
        Art[i].readf_Article(inFile);
        getline(inFile,dummy2,'\n');            
    }
}
void List::List_displayArticle()
{
    cout<<left <<setw(15)<<"Ma bao"<<left <<setw(70)<<"Ten cong bo"<<left <<setw(10)<<"Tac gia"<<left <<setw(10)<<"Tap chi"<<left <<setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        cout<<Art[i];
    }
}
void List::List_getJournal(ifstream &inFile)
{
    string dummy;
    getline(inFile,dummy,'\n');
    this->Jou = new Journal[Journal_count];
    for(int i =0; i< Journal_count;i++)
    {
        string dummy2;
        Jou[i].readf_journal(inFile);
        getline(inFile,dummy2,'\n');
    }
}
void List::List_displayJournal()
{
    cout <<left << setw(15) << "Ma tap chi" <<left << setw(50) << "Ten tap chi" << left << setw(30) << "Ten tong bien tap" << left << setw(10) << "Ma NXB"<<endl;
    for(int i=0;i<Journal_count;i++)
    {
        cout<<Jou[i];
    }
}
void List::List_getAuthor(ifstream &inFile)
{
    string dummy;
    getline(inFile,dummy,'\n');
    this->Auth = new Author[Author_count];
    for(int i=0;i< Author_count;i++)
    {
        string dummy2;
        Auth[i].readf_author(inFile);
        getline(inFile,dummy2,'\n');
    }
}
void List::List_displayAuthor()
{
    cout << left << setw(15) << "Ma TG"  << left << setw(20) << "Ho dem" <<left << setw(15)<< "Ten" << left << setw(15) << "Noi cong tac" <<left << setw(30)<< "Linh vuc nghien cuu" << left << setw(10) << "Trinh do" << endl;
    for(int i=0;i<Author_count;i++)
    {
        cout<<Auth[i];
    }
}
string List ::List_getAuthorNamebyID(string Author_ID)
{
    for(int i =0; i < Author_count; i++)
    {
        if(Auth[i].getID() == Author_ID) return Auth[i].getName();
    }
    return "NULL";
}
string List ::List_getJournalNamebyID(string Journal_ID)
{
    for(int i =0; i < Journal_count; i++)
    {
        if(Jou[i].getID() == Journal_ID) return Jou[i].getName();
    }
    return "NULL";
}
void List::List_displayAll()
{
    cout<<left <<setw(15)<<"Ma bao"<<left <<setw(65)<<"Ten cong bo"<<left <<setw(25)<<"Tac gia"<<left <<setw(45)<<"Tap chi"<<left <<setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        cout <<left <<setw(15)<< Art[i].Article_id << left <<setw(65) << Art[i].Article_name <<left <<setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
        cout << left <<setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) <<left <<setw(10)<< Art[i].Publish_time << endl;
    }
}
void List::List_displayNumofArtPerAuth()
{
    for(int i=0;i<Author_count;i++)
    {
        {
            for(int j =0; j< Article_count;j++)
            {
                if(Auth[i].author_id == Art[j].Author_id) Auth[i].Article_count+=1;
            }
        }
    }
    cout<<left<<setw(25)<<"Tac gia"<<left<<setw(10)<<"So bai bao"<<endl;
    for(int i=0;i< Author_count;i++)
    {
        cout<<left<<setw(25)<<Auth[i].getName()<<left<<setw(10)<<Auth[i].Article_count<<endl;

    }
}
void List::List_displayNumofArtPerJour()
{
    for(int i=0;i<Journal_count;i++)
    {
        for(int j=0;j<Article_count;j++)
        {
            if(Jou[i].J_id == Art[j].Journal_id) Jou[i].Article_count +=1;
        }
    }
    cout<<left<<setw(50)<<"Tap chi"<<left<<setw(10)<<"So bai bao"<<endl;
    for(int i=0;i<Journal_count;i++)
    {
        cout<<left<<setw(50)<<Jou[i].getName()<<left<<setw(10)<<Jou[i].Article_count<<endl;
    }
}
// Thống kê số lượng bài báo của mỗi NXB 
string List::List_getPublisherIDbyJourID(string Journal_ID)
{
    for(int i=0;i<Journal_count;i++)
    {
        if(Jou[i].J_id == Journal_ID ) return Jou[i].Publisher_id;
    }
    return "NULL";
}
void List:: List_displayNumofArtPerPubl()
{
    for(int i=0;i<Publisher_count;i++)
    {
        for(int j =0;j < Article_count;j++)
        {
            if(Pub[i].Publisher_id == this->List_getPublisherIDbyJourID(Art[j].Journal_id ) ) Pub[i].Article_count+=1;
        }
    }
    cout<<left<<setw(40)<<"Nha xuat ban"<<left<<setw(10)<<"So bai bao"<<endl;
    for(int i=0;i<Publisher_count;i++)
    {
        cout<<left<<setw(40)<<Pub[i].Publisher_name<<left<<setw(10)<<Pub[i].Article_count<<endl;
    }
}
void List ::List_displayNumofArtPerYear()
{
    
}

int main() {

    List L;
    // Lay so luong
    ifstream inFileNum("../Data/NumOfData.txt");
    L.get_initialNum(inFileNum);

    // Get data Publisher
    ifstream inFile("../Data/Publisher.txt");
    if (inFile.fail()) cout << "Failed to open file";
    L.List_getPublisher(inFile);
    L.List_displayPublisher(); 

    // Get data Article
    ifstream inFileArt("../Data/Article.txt");
    if (inFileArt.fail()) cout << "Failed to open file";
    L.List_getArticle(inFileArt);
    //L.List_displayArticle();

    // Get data Journal
    ifstream inFileJou("../Data/Journal.txt");
    if (inFileJou.fail()) cout << "Failed to open file";
    L.List_getJournal(inFileJou);
    //L.List_displayJournal();

    //Get data Author
    ifstream inFileAuth("../Data/Author.txt");
    if (inFileAuth.fail()) cout << "Failed to open file";
    L.List_getAuthor(inFileAuth);
    //L.List_displayAuthor();

    //L.List_displayAll();
    // L.List_displayNumofArtPerAuth();
    // L.List_displayNumofArtPerJour();
    //L.List_displayNumofArtPerPubl();

    return 0;
}