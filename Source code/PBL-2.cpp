#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <algorithm>
#include "Author.h"
#include "Journal.h"
#include "Article.h"
#include "Publisher.h"
#include "List.h"
using namespace std;
#define getenter fflush(stdin);
//////////////////////////////////////////////////////////////////CLASS AUTHOR//////////////////////////////////////////////////////////////////
Author ::Author() 
{}
Author ::Author(const Author &a)
    : firstName(a.firstName), lastName(a.lastName), work(a.work), field(a.field), degree(a.degree), author_id(a.author_id), cmnd(a.cmnd)
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
    getline(in,degree,'|');
    getline(in,cmnd,',');
}

ostream &operator << (ostream &out, const Author &a) {
    out << left << setw(15) << a.author_id  << left << setw(20) << a.firstName <<left << setw(15)<< a.lastName << left << setw(15);
    out << a.work << left << setw(30) << a.field << left << setw(10) << a.degree << left << setw(10) << a.cmnd << endl;
    return out;
}
istream &operator >> (istream &in, Author &a) {
    cout << "Nhap ho dem: "; 
    getenter;
    getline(cin, a.firstName);
    cout << "Nhap ten: ";
    cin >> a.lastName;
    cout << "Nhap noi cong tac: (DH__) ";
    cin >> a.work;
    cout << "Nhap linh vuc nghien cuu: ";
    getenter;
    getline(cin, a.field);
    cout << "Nhap trinh do: ";
    getenter;
    getline(cin,a.degree);
    cout << "Nhap so CMND/CCCD: ";
    getenter;
    getline(cin, a.cmnd);
    a.setAuthorID();
    return in;
}
void Author::setAuthorID()
{
    this->author_id = "AU" + to_string(List::Author_count);
}


//////////////////////////////////////////////////////////////////CLASS JOURNAL//////////////////////////////////////////////////////////////////

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
    out << left << setw(15) << j.J_id << left << setw(50) << j.J_name << left << setw(30) << j.J_editor << left << setw(10);
    out << j.Publisher_id<<endl;
    return out;
}




//////////////////////////////////////////////////////////////////CLASS ARTICLE//////////////////////////////////////////////////////////////////

void Article ::readf_Article (ifstream &in) {
    string dummy;
    getline(in, Article_id, '|');
    getline(in,Article_name,'|');
    getline(in,Author_id,'|');
    getline(in,Journal_id,'|');
    in >> Publish_time;
    getline(in, dummy, ',');
}

ostream &operator << (ostream &out, const Article &a) {
    out << left <<setw(15)<<a.Article_id << left <<setw(70) << a.Article_name << left <<setw(10) <<a.Author_id << left <<setw(10);
    out << a.Journal_id << left <<setw(10)<< a.Publish_time << endl;
    return out;
}
istream &operator >> (istream &in, Article &a) {
    cout << "Nhap ma bai bao: ";
    cin >> a.Article_id;
    cout << "Nhap ten bai bao: ";
    getenter;
    getline(cin, a.Article_name);
    cout << "Nhap ma tac gia: ";
    cin >> a.Author_id;
    cout << "Nhap ma tap chi: ";
    cin >> a.Journal_id;
    cout << "Nhap thoi gian cong bo: ";
    cin >> a.Publish_time;
    return in;
}


void Article :: editArticle_Name()
{   
    string newArtName;
    cout << "Nhap moi ten: ";
    fflush(stdin);
    getline(cin,newArtName);
    this->Article_name = newArtName;
}
void Article :: editArticle_Author()
{   
    string newAuthorID;
    cout << "Nhap moi ma tac gia: ";
    cin >> newAuthorID;
    transform(newAuthorID.begin(), newAuthorID.end(), newAuthorID.begin(), ::toupper);
    this->Author_id = newAuthorID;
}
void Article :: editArticle_Journal()
{   
    string newJournalID;
    cout << "Nhap moi ma tap chi: ";
    cin >> newJournalID;
    this->Journal_id = newJournalID;
}
void Article :: editArticle_Time()
{   
    int newPublishTime;
    cout << "Nhap moi thoi gian cong bo: ";
    cin >> newPublishTime;
    this->Publish_time = newPublishTime;
}



//////////////////////////////////////////////////////////////////CLASS PUBLISHER//////////////////////////////////////////////////////////////////

void Publisher::readf_Publisher(ifstream &in) {
    string dum;                         //dum là kí tự |
    getline(in,Publisher_id,'|');       //Lấy kí tự |
    getline(in,Publisher_name,',');
}

ostream &operator << (ostream &out, const Publisher &p) {
    out <<left << setw (15) << p.Publisher_id << p.Publisher_name << endl;
    return out;
}






//////////////////////////////////////////////////////////////////CLASS LIST//////////////////////////////////////////////////////////////////

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
void List::get_initialNum(ifstream &inFile) {
    string dummyName, dummychar;
    getline(inFile,dummyName,'|');
    inFile >> Article_count;                    //Lấy số lượng bài báo hiện tại
    getline(inFile,dummychar,'\n');                
    getline(inFile,dummyName,'|');
    inFile >> Author_count;                     //Lấy số lượng tác giả hiện tại
    getline(inFile,dummychar,'\n');                
    getline(inFile,dummyName,'|');
    inFile >> Journal_count;                    //Lấy số lượng tạp chí hiện tại
    getline(inFile,dummychar,'\n');                
    getline(inFile,dummyName,'|');
    inFile >> Publisher_count;                  //Lấy số lượng NXB hiện tại
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
    cout << left << setw(15) << "Ma TG"  << left << setw(20) << "Ho dem" <<left << setw(15)<< "Ten" << left << setw(15) << "Noi cong tac";
    cout << left << setw(30) << "Linh vuc nghien cuu" << left << setw(10) << "Trinh do" << left << setw(10) << "CMND/CCCD" << endl;
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

/////////////////////////////////////////////////////////////DISPLAY ARTICLE WITH FULL AUTHOR NAME///////////////////////////////////////////////

void List::List_displayAll()
{
    cout<<left <<setw(15)<<"Ma bao"<<left <<setw(65)<<"Ten cong bo"<<left <<setw(25)<<"Tac gia"<<left <<setw(45)<<"Tap chi"<<left <<setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        cout <<left <<setw(15)<< Art[i].Article_id << left <<setw(65) << Art[i].Article_name <<left <<setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
        cout << left <<setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) <<left <<setw(10)<< Art[i].Publish_time << endl;
    }
}


/////////////////////////////////////////////////////////////MENU EDIT ARTICLE PROCESS//////////////////////////////////////////////////////////////
// void List :: List_editArticle() 
// {
//     char con = 'C';                         //biến kiểm tra có tiếp tục công việc sửa thông tin bài báo (c/k)
//     int i = 0; //Biến lấy phần tử bài báo trong list
//     while (con == 'C')
//     {
//         string ArtID;
//         cout << "Nhap ma bai bao can sua thong tin: ";
//         cin >> ArtID;
//         transform(ArtID.begin(), ArtID.end(), ArtID.begin(), ::toupper);
//         if (List_isNewArticle(ArtID)) cout << "Nhap sai ma bai bao!" << endl;
//         else 
//         {
//             for (i=0; i<Article_count; i++)
//             {
//                 if (Art[i].Article_id == ArtID) break;
//             }
//             editArticle_General(Art[i]);
//         }
//         cout << "Ban co muon tiep tuc khong? (c/k) ";
//         cin >> con;
//         con = toupper(con);
//     }
// }


/////////////////////////////////////////////////////////////EDIT ARTICLE GENERAL//////////////////////////////////////////////////////////////
// void List :: editArticle_General(Article &Art) {
//     cout << "1. Chinh sua ten bai bao" << endl << "2. Chinh sua tac gia" << endl;
//     cout << "3. Chinh sua tap chi" << endl << "4. Chinh sua thoi gian cong bo" << endl << "5: Thoat" << endl;
//     int type=0;
//     while (type==0)
//     {
//         cout << "Nhap lua chon: ";
//         cin >> type;
//         switch (type)
//         {
//             case 1: 
//                 Art.editArticle_Name();
//                 editArticle_General(Art);
//                 break;
//             case 2:
//                 Art.editArticle_Author();
//                 if (List_isNewAuthor(Art.Author_id))
//                 {
//                     cout << "Tac gia chua ton tai!" << endl;
//                     cout << "Them tac gia moi? (c/k) ";
//                     char type;
//                     cin >> type;
//                     toupper(type);
//                     if (type == 'C') List_AddAuthor();
//                 }
//                 else break;
//                 editArticle_General(Art);
//                 break;
//             case 3: 
//                 Art.editArticle_Journal();
//                 editArticle_General(Art);
//                 break;
//             case 4:
//                 Art.editArticle_Time();
//                 editArticle_General(Art);
//                 break;
//             case 5:
//                 type=1;
//                 break;
//             default:
//                 type = 0;
//         }
//     }
// }
/////////////////////////////////////////////////////////////Check new Author or not//////////////////////////////////////////////////////////////
bool List::List_isNewAuthor(string AuthorID) 
{
    int check = 1;                                  //Biến kiểm tra isNewAuthor trong List
    for (int i=0; i<Author_count; i++)
    {
        if (this->Auth[i].author_id == AuthorID) 
        {   
            check = 0;
            return check;
        }
    }
    return check;
}
////////////////////////////////////////////////////////////Check new Journal or not///////////////////////////////////////////
bool List::List_isNewJournal(string JournalID)
{
    for(int i=0;i < Journal_count; i++)
    {
        if(this->Jou[i].J_id == JournalID) return false;
    }
    return true;
}
////////////////////////////////////////////////////////////Check new Publisher or not//////////////////////////////////////////////
bool List::List_isNewPublisher(string PublisherID)
{
    for(int i=0;i < Publisher_count;i++)
    {
        if(this->Pub[i].Publisher_id == PublisherID) return false;;
    }
    return true;
}
/////////////////////////////////////////////////////////////Thêm tác giả//////////////////////////////////////////////////////////////
// void List::List_AddAuthor(string AuthorID)
// {
//     if(this->List_isNewAuthor(AuthorID))                //Nếu là tác giả mới
//     {   
//         this->Author_count ++;                                //Tăng số lượng tác giả lên 1
//         Author a;                                       //New Author
//         cin >> a;
//         Author newAuthor[this->Author_count-1];                 //Mảng tĩnh sao chép tạm danh sách tác giả khi chưa thêm
//         for (int i=0; i<this->Author_count-1; i++)              //Sao chép tác giả từ List sang mảng tĩnh
//         {
//             newAuthor[i] = this->Auth[i];
//         }
//         delete []this->Auth;                            //Xóa danh sách tác giả cũ
//         this->Auth = new Author[this->Author_count];          //Tạo mảng động danh sách tác giả mới cho list
//         this->Auth[this->Author_count-1] = a;                 //Cho tác giả mới thêm vào cuối danh sách
//         for (int i=0; i<this->Author_count-1; i++)
//         {
//             this->Auth[i] = newAuthor[i];               //Chép từ mảng tạm sang danh sách chính
//         }
//     }
//     else cout << "Tac gia da ton tai!";
// }




    
/////////////////////////////////////////////////THỐNG KÊ//////////////////////////////////////////////////////////////////////////////
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
void List::List_dislayArtByAuthID()
{
    string temp;
    do
    {
        cout<<"Nhap ma tac gia can tim kiem: ";
        cin>>temp;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    }
    while(this->List_isNewAuthor(temp));
    cout<<left <<setw(15)<<"Ma bao"<<left <<setw(65)<<"Ten cong bo"<<left <<setw(25)<<"Tac gia"<<left <<setw(45)<<"Tap chi"<<left <<setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Author_id == temp)
        {
            cout <<left <<setw(15)<< Art[i].Article_id << left <<setw(65) << Art[i].Article_name <<left <<setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left <<setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) <<left <<setw(10)<< Art[i].Publish_time << endl;
        }
    }
}
// Hiển thị bài báo theo ID của tạp chí
void List::List_displayArtByJourID()
{
    string temp;
    do
    {
        cout<<"Nhap ma tap chi can tim kiem: ";
        cin>>temp;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        
    }
    while(this->List_isNewJournal(temp));
    cout<<left <<setw(15)<<"Ma bao"<<left <<setw(65)<<"Ten cong bo"<<left <<setw(25)<<"Tac gia"<<left <<setw(45)<<"Tap chi"<<left <<setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Journal_id == temp)
        {
            cout <<left <<setw(15)<< Art[i].Article_id << left <<setw(65) << Art[i].Article_name <<left <<setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left <<setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) <<left <<setw(10)<< Art[i].Publish_time << endl;
        }
    }
}
// Hiển thị bài báo theo ID của nhà xuất bản
void List::List_displayArtByPublID()
{
    string temp;
    do
    {
        cout<<"Nhap ma NXB can tim kiem: ";
        cin>>temp;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        
    }
    while(this->List_isNewPublisher(temp));
    cout<<left <<setw(15)<<"Ma bao"<<left <<setw(65)<<"Ten cong bo"<<left <<setw(25)<<"Tac gia"<<left <<setw(45)<<"Tap chi"<<left <<setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        if(this->List_getPublisherIDbyJourID(Art[i].Journal_id) == temp)
        {
            cout <<left <<setw(15)<< Art[i].Article_id << left <<setw(65) << Art[i].Article_name <<left <<setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left <<setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) <<left <<setw(10)<< Art[i].Publish_time << endl;
        }
    }
}
// Hiển thị bài báo theo năm
void List::List_displayArtByYear()
{
    int temp;
    cout<<"Nhap nam can tim kiem: ";
    cin>> temp;
    cout<<left <<setw(15)<<"Ma bao"<<left <<setw(65)<<"Ten cong bo"<<left <<setw(25)<<"Tac gia"<<left <<setw(45)<<"Tap chi"<<left <<setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Publish_time == temp)
        {
            cout <<left <<setw(15)<< Art[i].Article_id << left <<setw(65) << Art[i].Article_name <<left <<setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left <<setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) <<left <<setw(10)<< Art[i].Publish_time << endl;
        }

    }
}



























































































































































































///////////////////////////Bat dau//////////////////////////////////////
bool List::List_isNewArticle(string ArtID) //Kiểm tra article mới/cũ
{
     for(int i=0;i < Article_count; i++)
    {
        if(this->Art[i].Article_id == ArtID) return false;
    }
    return true;
}; 

// void List::List_addArticle() {
//     if(this->List_isNewArticle(ArtID))                         //Nếu là bài báo mới
//     {   
//         this->Article_count ++;                                //Tăng số lượng bài báo lên 1
//         Article a;                                             //New Article
//         cin >> a;
//         if (List_isNewAuthor(a.Author_id)) List_AddAuthor(a.Author_id); //nếu tác giả nhập vào là tác giả mới thì thêm thông tin tác giả mới vào
//         Article newArticle[this->Article_count-1];             //Mảng tĩnh sao chép tạm danh sách bài báo khi chưa thêm
//         for (int i=0; i<this->Article_count-1; i++)            //Sao chép bài báo từ List sang mảng tĩnh
//         {
//             newArticle[i] = this->Art[i];
//         }
//         delete []this->Art;                                    //Xóa danh sách bài báo cũ
//         this->Art = new Article[this->Article_count];          //Tạo mảng động danh sách bài báo mới cho list
//         this->Art[this->Article_count-1] = a;                  //Cho bài báo mới thêm vào cuối danh sách
//         for (int i=0; i<this->Article_count-1; i++)
//         {
//             this->Art[i] = newArticle[i];                      //Chép từ mảng tạm sang danh sách chính
//         }
//     }
//     else cout << "Bai bao da ton tai!";
// }



////////////////////////////ketthuc/////////////////////////////






//////////////////////////////////////////////////////////////Ghi mới vào file Author.txt////////////////////////////////////////////////
void List::List_overwriteNewAuthor() 
{
    ofstream outFile("../Data/Author.txt", ofstream::trunc);
    outFile << "Ma TG |Ho dem	|Ten  |Noi cong tac|Linh vuc nghien cuu|Trinh do\n";
    for (int i=0; i<Author_count; i++)
    {
        outFile <<  Auth[i].author_id << "|";
        outFile <<  Auth[i].firstName << "|";
        outFile <<  Auth[i].lastName << "|";
        outFile <<  Auth[i].work << "|";
        outFile <<  Auth[i].field << "|";
        outFile <<  Auth[i].degree << ",\n";

    }
    outFile.close();
}
//////////////////////////////////////////////////////////////Ghi mới vào file Article.txt/////////////////////////////////////////////////
void List::List_overwriteNewArticle()
{
    ofstream outFile("../Data/Article.txt", ofstream::trunc);
    outFile << "Ma bao	 |Ten cong bo							|Tac gia|Tap chi|Thoi gian\n";
    for (int i=0; i<Article_count; i++)
    {
        outFile <<  Art[i].Article_id << "|";
        outFile <<  Art[i].Article_name << "|";
        outFile <<  Art[i].Author_id << "|";
        outFile <<  Art[i].Journal_id << "|";
        outFile <<  Art[i].Publish_time << ",\n";
    }
    outFile.close();

}
//////////////////////////////////////////////////////////////// Ghi mới vào file Journal.txt////////////////////////////////////////
void List::List_overwriteNewJournal()
{
    ofstream outFile("../Data/Journal.txt", ofstream::trunc);
    outFile << "Ma tap chi|Ten tap chi				    |Ten tong bien tap	    |Ma NXB\n";
    for (int i=0; i< Journal_count ; i++)
    {
        outFile <<  Pub[i].Publisher_id << "|";
        outFile <<  Pub[i].Publisher_name << ",\n";
    }
    outFile.close();
    
}
/////////////////////////////////////////////////////////////////Ghi mới vào file Publiser.txt////////////////////////////////////////
void List:: List_overwriteNewPublisher()
{
    ofstream outFile("../Data/Publisher.txt", ofstream::trunc);
    outFile << "Ma NXB|Ten NXB	\n";
    for (int i=0; i< Publisher_count ; i++)
    {
        outFile <<  Jou[i].J_id << "|";
        outFile <<  Jou[i].J_name << "|";
        outFile <<  Jou[i].J_editor << "|";
        outFile <<  Jou[i].Publisher_id << ",\n";
    }
    outFile.close();

}



/////////////////////////////////////////////////////////////MAIN//////////////////////////////////////////////////////////////
int main() {

    List L;
    // Lay so luong
    ifstream inFileNum("../Data/NumOfData.txt");
    L.get_initialNum(inFileNum);
    cout << L.Article_count << L.Author_count << L.Journal_count << L.Publisher_count << endl;
    // Get data Publisher
    ifstream inFilePub("../Data/Publisher.txt");
    if (inFilePub.fail()) cout << "Failed to open file";
    L.List_getPublisher(inFilePub);
    //L.List_displayPublisher(); 

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
    
    //L.List_displayAll(); // Hiển thị thông tin đầy đủ của tất cả bài báo
    // L.List_displayNumofArtPerAuth(); // Thống kê số lượng bài báo của tất cả tác giả
    // L.List_displayNumofArtPerJour(); // Thống kê số lượng bài báo của tất cả tạp chí
    //L.List_displayNumofArtPerPubl();  // Thống kê số lượng bài báo của tất cả NXB
    // L.List_displayAuthor();
    //L.List_displayAll();

    //L.List_editArticle();
    L.List_displayArticle();
    // L.List_displayAuthor();
    // L.List_dislayArtByAuthID(); // Hiển thị các bài báo của 1 tác giả theo ID
    // L.List_displayArtByJourID();// Hiển thị các bài báo của 1 tạp chí theo ID
    //L.List_displayArtByPublID(); // Hiển thị các bài báo của 1 NXB theo ID
    // L.List_displayArtByYear(); // Hiển thị các bài báo của 1 năm
    // L.List_addArticle("")

    inFileArt.close();
    inFileJou.close();
    inFileAuth.close();
    inFilePub.close();

    return 0;
}
////////// - add article chưa xong
/////////  - em Thịnh viết hàm transfrom