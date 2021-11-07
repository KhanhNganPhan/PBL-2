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
    : firstName(a.firstName), lastName(a.lastName), work(a.work), field(a.field), degree(a.degree), author_id(a.author_id)
{

}

Author :: ~Author()
{

}
string Author ::getLastName()
{
    return this->lastName;
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
void Author ::readf_author(ifstream &in)
{
    string dummy;
    getline(in,author_id, '|');
    getline(in,firstName,'|');
    getline(in,lastName,'|');
    getline(in,work,'|');
    getline(in,field,'|');
    getline(in,degree,',');
}

ostream &operator << (ostream &out, const Author &a) 
{
    out << left << setw(15) << a.author_id  << left << setw(20) << a.firstName << left << setw(15)<< a.lastName << left << setw(15);
    out << a.work << left << setw(30) << a.field << left << setw(10) << a.degree << endl;
    return out;
}
istream &operator >> (istream &in, Author &a) 
{
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
    return in;
}

void Author::editAuthor_Name()
{
    cout << "Nhap ho va ten dem: ";
    getenter;
    getline(cin,firstName);
    cout << "Nhap ten: ";
    getenter;
    getline(cin,lastName);
}

void Author::editAuthor_Work()
{
    cout << "Nhap moi noi cong tac: ";
    getenter;
    getline(cin,work);
}

void Author::editAuthor_Field()
{
    cout << "Nhap moi linh vuc lam viec: ";
    getenter;
    getline(cin,field);
}

void Author::editAuthor_Degree()
{
    cout << "Nhap moi trinh do: ";
    getenter;
    getline(cin,degree);
}


//////////////////////////////////////////////////////////////////CLASS JOURNAL//////////////////////////////////////////////////////////////////

void Journal ::readf_journal(ifstream &in)
{
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

ostream &operator << (ostream &out, const Journal &j)
{
    out << left << setw(15) << j.J_id << left << setw(50) << j.J_name << left << setw(30) << j.J_editor << left << setw(10);
    out << j.Publisher_id<<endl;
    return out;
}
istream &operator >> (istream &in, Journal &j)
{
    cout << "Nhap ten tap chi: ";
    getenter;
    in >> j.J_name;
    cout << "Nhap tong bien tap: ";
    getenter;
    in >> j.J_editor;
    cout << "Nhap ma NXB: ";
    getenter;
    in >> j.Publisher_id;
    return in;
}


void Journal::editJournal_Name()
{
    cout << "Nhap moi ten tap chi: ";
    getenter;
    getline(cin,J_name);
}

void Journal::editJournal_Editor()
{
    cout << "Nhap moi ten tong bien tap: ";
    getenter;
    getline(cin,J_editor);
}

void Journal::editJournal_Publisher()
{
    string newPubID;
    cout << "Nhap moi ma NXB: ";
    getenter;
    cin >> newPubID;
    transform(newPubID.begin(), newPubID.end(), newPubID.begin(), ::toupper);
    Publisher_id = newPubID;
}


//////////////////////////////////////////////////////////////////CLASS ARTICLE//////////////////////////////////////////////////////////////////
string Article::getArticleName()
{
    return this->Article_name;
}
int Article :: getPublish_Time()
{
    return this->Publish_time;
}
void Article ::readf_Article (ifstream &in) 
{
    string dummy;
    getline(in, Article_id, '|');
    getline(in,Article_name,'|');
    getline(in,Author_id,'|');
    getline(in,Journal_id,'|');
    in >> Publish_time;
    getline(in, dummy, ',');
}

ostream &operator << (ostream &out, const Article &a) 
{
    out << left << setw(15)<<a.Article_id << left << setw(70) << a.Article_name << left << setw(10) <<a.Author_id << left << setw(10);
    out << a.Journal_id << left << setw(10)<< a.Publish_time << endl;
    return out;
}
istream &operator >> (istream &in, Article &a) 
{
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
    cout << "Nhap moi ten: ";
    fflush(stdin);
    getline(cin,Article_name);
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
    transform(newJournalID.begin(), newJournalID.end(), newJournalID.begin(), ::toupper);
    this->Journal_id = newJournalID;
}
void Article :: editArticle_Time()
{   
    cout << "Nhap moi thoi gian cong bo: ";
    cin >> Publish_time;
}



//////////////////////////////////////////////////////////////////CLASS PUBLISHER//////////////////////////////////////////////////////////////////

void Publisher::readf_Publisher(ifstream &in) 
{
    string dum;                         //dum là kí tự |
    getline(in,Publisher_id,'|');       //Lấy kí tự |
    getline(in,Publisher_name,',');
}

ostream &operator << (ostream &out, const Publisher &p) 
{
    out << left << setw (15) << p.Publisher_id << p.Publisher_name << endl;
    return out;
}

istream &operator >> (istream &in, Publisher &p) 
{
    cout << "Nhap ten NXB: ";
    getenter;
    getline(in,p.Publisher_name);
    return in;
}

void Publisher::editPublisher_Name()
{
    cout << "Nhap moi ten NXB: ";
    getenter;
    getline(cin, Publisher_name);
}



//////////////////////////////////////////////////////////////////CLASS LIST//////////////////////////////////////////////////////////////////

int List::Author_count = 0;                 //Biến static đếm tổng số tác giả
int List::Article_count = 0;                //Biến static đếm tổng số bài báo
int List::Journal_count = 0;                //Biến static đếm tổng số tạp chí
int List::Publisher_count = 0;              //Biến static đếm tổng số NXB

List::~List() 
{
    delete []Art;
    delete []Auth;
    delete []Jou;
    delete []Pub;
}
void List::get_initialNum(ifstream &inFile) 
{
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

void List::List_getPublisher(ifstream &inFile) 
{
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

    cout<< left << setw (15) <<"Ma NXB"<< "Ten NXB" << endl;
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
    cout<< left << setw(15)<<"Ma bao"<< left << setw(70)<<"Ten cong bo"<< left << setw(10)<<"Tac gia"<< left << setw(10)<<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
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
    cout << left << setw(15) << "Ma tap chi" << left << setw(50) << "Ten tap chi" << left << setw(30) << "Ten tong bien tap" << left << setw(10) << "Ma NXB"<<endl;
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
    cout << left << setw(15) << "Ma TG"  << left << setw(20) << "Ho dem" << left << setw(15)<< "Ten" << left << setw(15) << "Noi cong tac";
    cout << left << setw(30) << "Linh vuc nghien cuu" << left << setw(10) << "Trinh do" << endl;
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
string List ::List_getAuthorLastNamebyID(string Author_ID)
{
    for(int i =0; i < Author_count; i++)
    {
        if(Auth[i].getID() == Author_ID) return Auth[i].getLastName();
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
    cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45)<<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
        cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
    }
}


/////////////////////////////////////////////////////////////MENU EDIT ARTICLE PROCESS//////////////////////////////////////////////////////////////
void List :: List_editArticle() 
{
    char con = 'C'; //biến kiểm tra có tiếp tục công việc sửa thông tin bài báo (c/k)
    int i = 0; //Biến lấy phần tử bài báo trong list
    while (con == 'C')
    {
        string ArtID;
        cout << "Nhap ma bai bao can sua thong tin: ";
        cin >> ArtID;
        transform(ArtID.begin(), ArtID.end(), ArtID.begin(), ::toupper);
        if (List_isNewArticle(ArtID)) cout << "Nhap sai ma bai bao!" << endl;
        else 
        {
            for (i=0; i<Article_count; i++)
            {
                if (Art[i].Article_id == ArtID) break;
            }
            editArticle_General(Art[i]);
        }
        cout << "Ban co muon tiep tuc khong? (c/k) ";
        cin >> con;
        con = toupper(con);
    }
}


/////////////////////////////////////////////////////////////EDIT ARTICLE GENERAL//////////////////////////////////////////////////////////////
void List :: editArticle_General(Article &Art) 
{
    cout << "1. Chinh sua ten bai bao" << endl << "2. Chinh sua tac gia" << endl;
    cout << "3. Chinh sua tap chi" << endl << "4. Chinh sua thoi gian cong bo" << endl << "5: Thoat" << endl;
    int type=0;
    while (type==0)
    {
        cout << "Nhap lua chon: ";
        cin >> type;
        switch (type)
        {
            case 1: 
                Art.editArticle_Name();
                editArticle_General(Art);
                break;
            case 2:
            { //bỏ trong dấu ngoặc nhọn để có thể khai báo biến tempAuthorID trong case
                string tempAuthorID = Art.Author_id;
                Art.editArticle_Author();
                if (List_isNewAuthor(Art.Author_id))
                {
                    cout << "Tac gia chua ton tai!" << endl;
                    cout << "Them tac gia moi? (c/k) ";
                    char type;
                    cin >> type;
                    type = toupper(type);
                    if (type == 'C') List_AddAuthor(Art.Author_id);
                    else Art.Author_id = tempAuthorID;
                }
                editArticle_General(Art);
                break;
            }
            case 3: 
            { //bỏ trong dấu ngoặc nhọn để có thể khai báo biến tempJournalID trong case
                string tempJournalID = Art.Journal_id;
                Art.editArticle_Journal();
                if (List_isNewJournal(Art.Journal_id))
                {
                    cout << "Tac tap chi ton tai!" << endl;
                    cout << "Them tap chi moi? (c/k) ";
                    char type;
                    cin >> type;
                    type = toupper(type);
                    if (type == 'C') List_AddJournal(Art.Journal_id);
                    else Art.Journal_id = tempJournalID;
                }
                editArticle_General(Art);
                break;
            }
            case 4:
                Art.editArticle_Time();
                editArticle_General(Art);
                break;
            case 5:
                type=1;
                break;
            default:
                type = 0;
        }
    }
}

/////////////////////////////////////////////////////////////MENU EDIT JOURNAL PROCESS//////////////////////////////////////////////////////////////
void List :: List_editJournal() 
{
    char con = 'C'; //biến kiểm tra có tiếp tục công việc sửa thông tin bài báo (c/k)
    int i = 0; //Biến lấy phần tử bài báo trong list
    while (con == 'C')
    {
        string JouID;
        cout << "Nhap ma tap chi can sua thong tin: ";
        cin >> JouID;
        transform(JouID.begin(), JouID.end(), JouID.begin(), ::toupper);
        if (List_isNewJournal(JouID)) cout << "Nhap sai ma tap chi!" << endl;
        else 
        {
            for (i=0; i<Journal_count; i++)
            {
                if (Jou[i].J_id == JouID) break;
            }
            editJournal_General(Jou[i]);
        }
        cout << "Ban co muon tiep tuc khong? (c/k) ";
        cin >> con;
        con = toupper(con);
    }
}


/////////////////////////////////////////////////////////////EDIT JOURNAL GENERAL//////////////////////////////////////////////////////////////
void List :: editJournal_General(Journal &Jou) 
{
    cout << "1. Chinh sua ten tap chi" << endl << "2. Chinh sua tong bien tap" << endl;
    cout << "3. Chinh sua NXB" << endl << "4: Thoat" << endl;
    int type=0;
    while (type==0)
    {
        cout << "Nhap lua chon: ";
        cin >> type;
        switch (type)
        {
            case 1: 
                Jou.editJournal_Name();
                editJournal_General(Jou);
                break;
            case 2:
                Jou.editJournal_Editor();
                editJournal_General(Jou);
            case 3: 
            { //bỏ trong dấu ngoặc nhọn để có thể khai báo biến tempPublisherID trong case
                string tempPublisherID = Jou.Publisher_id;
                Jou.editJournal_Publisher();
                if (List_isNewPublisher(Jou.Publisher_id))
                {
                    cout << "NXB chua ton tai!" << endl;
                    cout << "Them NXB moi? (c/k) ";
                    char type;
                    cin >> type;
                    type = toupper(type);
                    if (type == 'C') List_AddPublisher(Jou.Publisher_id);
                    else Jou.Publisher_id = tempPublisherID;
                }
                editJournal_General(Jou);
                break;
            }
            case 4:
                type=1;
                break;
            default:
                type = 0;
        }
    }
}
//////////////////////////////////////////////////////////////EDIT PUBLISHER PROCESS////////////////////////////////////////////////////////
void List :: List_editPublisher() 
{
    char con = 'C'; //biến kiểm tra có tiếp tục công việc sửa thông tin bài báo (c/k)
    int i = 0; //Biến lấy phần tử bài báo trong list
    while (con == 'C')
    {
        string PubID;
        cout << "Nhap ma NXB can sua thong tin: ";
        cin >> PubID;
        transform(PubID.begin(), PubID.end(), PubID.begin(), ::toupper);
        if (List_isNewPublisher(PubID)) cout << "Nhap sai ma NXB!" << endl;
        else 
        {
            for (i=0; i<Publisher_count; i++)
            {
                if (Pub[i].Publisher_id == PubID) break;
            }
            Pub[i].editPublisher_Name();
        }
        cout << "Ban co muon tiep tuc khong? (c/k) ";
        cin >> con;
        con = toupper(con);
    }
}
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
void List::List_AddAuthor(string AuthorID)
{
    transform(AuthorID.begin(), AuthorID.end(), AuthorID.begin(), ::toupper);
    if (this->List_isNewAuthor(AuthorID)) //Nếu là tác giả mới
    {   
        this->Author_count ++;                                //Tăng số lượng tác giả lên 1
        Author a;                                       //New Author
        a.author_id = AuthorID;
        cin >> a;
        Author newAuthor[this->Author_count-1];                 //Mảng tĩnh sao chép tạm danh sách tác giả khi chưa thêm
        for (int i=0; i<this->Author_count-1; i++)              //Sao chép tác giả từ List sang mảng tĩnh
        {
            newAuthor[i] = this->Auth[i];
        }
        delete []this->Auth;                            //Xóa danh sách tác giả cũ
        this->Auth = new Author[this->Author_count];          //Tạo mảng động danh sách tác giả mới cho list
        this->Auth[this->Author_count-1] = a;                 //Cho tác giả mới thêm vào cuối danh sách
        for (int i=0; i<this->Author_count-1; i++)
        {
            this->Auth[i] = newAuthor[i];               //Chép từ mảng tạm sang danh sách chính
        }
    }
    else cout << "Tac gia da ton tai!";
}
////////////////////////////////////////////////////THÊM NXB//////////////////////////////////////////////////////////////////////////
void List::List_AddPublisher(string PubID)
{
    transform(PubID.begin(), PubID.end(), PubID.begin(), ::toupper);
    if (this->List_isNewPublisher(PubID)) //Nếu là NXB mới
    {   
        this->Publisher_count ++;                                //Tăng số lượng NXB lên 1
        Publisher a;                                       //New Publisher
        a.Publisher_id = PubID;
        cin >> a;
        Publisher newPublisher[this->Publisher_count-1];                 //Mảng tĩnh sao chép tạm danh sách NXB khi chưa thêm
        for (int i=0; i<this->Publisher_count-1; i++)              //Sao chép NXB từ List sang mảng tĩnh
        {
            newPublisher[i] = this->Pub[i];
        }
        delete []this->Pub;                            //Xóa danh sách NXB cũ
        this->Pub = new Publisher[this->Publisher_count];          //Tạo mảng động danh sách NXB mới cho list
        this->Pub[this->Publisher_count-1] = a;                 //Cho NXB mới thêm vào cuối danh sách
        for (int i=0; i<this->Publisher_count-1; i++)
        {
            this->Pub[i] = newPublisher[i];               //Chép từ mảng tạm sang danh sách chính
        }
    }
    else cout << "NXB da ton tai!";
}
/////////////////////////////////////////////////////////////Thêm TẠP CHÍ//////////////////////////////////////////////////////////////
void List::List_AddJournal(string JournalID)
{
    transform(JournalID.begin(), JournalID.end(), JournalID.begin(), ::toupper);
    if (this->List_isNewJournal(JournalID)) //Nếu là tạp chí mới
    {   
        this->Journal_count ++;                                //Tăng số lượng tạp chí lên 1
        Journal a;                                       //New Journal
        a.J_id = JournalID;
        cin >> a;
        if (List_isNewPublisher(a.Publisher_id))
        {
            cout << "Nhap thong tin NXB moi:" << endl;
            List_AddPublisher(a.Publisher_id); //nếu NXB nhập vào là tác giả mới thì thêm thông tin NXB mới vào
        }
        Journal newJournal[this->Journal_count-1];                 //Mảng tĩnh sao chép tạm danh sách tạp chí khi chưa thêm
        for (int i=0; i<this->Journal_count-1; i++)              //Sao chép tạp chí từ List sang mảng tĩnh
        {
            newJournal[i] = this->Jou[i];
        }
        delete []this->Jou;                            //Xóa danh sách tạp chí cũ
        this->Jou = new Journal[this->Journal_count];          //Tạo mảng động danh sách tạp chí mới cho list
        this->Jou[this->Journal_count-1] = a;                 //Cho tạp chí mới thêm vào cuối danh sách
        for (int i=0; i<this->Journal_count-1; i++)
        {
            this->Jou[i] = newJournal[i];               //Chép từ mảng tạm sang danh sách chính
        }
    }
    else cout << "Tap chi da ton tai!";
}


    
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
    cout<< left<< setw(25)<<"Tac gia"<< left<< setw(10)<<"So bai bao"<<endl;
    for(int i=0;i< Author_count;i++)
    {
        cout<< left<< setw(25)<<Auth[i].getName()<< left<< setw(10)<<Auth[i].Article_count<<endl;
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
    cout<< left<< setw(50)<<"Tap chi"<< left<< setw(10)<<"So bai bao"<<endl;
    for(int i=0;i<Journal_count;i++)
    {
        cout<< left<< setw(50)<<Jou[i].getName()<< left<< setw(10)<<Jou[i].Article_count<<endl;
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
    cout<< left<< setw(40)<<"Nha xuat ban"<< left<< setw(10)<<"So bai bao"<<endl;
    for(int i=0;i<Publisher_count;i++)
    {
        cout<< left<< setw(40)<<Pub[i].Publisher_name<< left<< setw(10)<<Pub[i].Article_count<<endl;
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
    cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45)<<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Author_id == temp)
        {
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
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
    cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45)<<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Journal_id == temp)
        {
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
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
    cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45)<<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        if(this->List_getPublisherIDbyJourID(Art[i].Journal_id) == temp)
        {
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
        }
    }
}
// Hiển thị bài báo theo năm
void List::List_displayArtByYear()
{
    int temp;
    cout<<"Nhap nam can tim kiem: ";
    cin>> temp;
    cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45)<<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Publish_time == temp)
        {
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
        }

    }
}
// Hiển thị bài báo theo Art ID
void List::List_displayArtByArtID()
{
    string temp;
    cout<<"Nhap ma bai bao can tim kiem: ";
    cin>> temp;
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45)<<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Article_id == temp)
        {
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
        }

    }

}

bool List::List_isNewArticle(string ArtID) //Kiểm tra article mới/cũ
{
     for(int i=0;i < Article_count; i++)
    {
        if(this->Art[i].Article_id == ArtID) return false;
    }
    return true;
}; 

void List::List_AddArticle(string ArtID) 
{
    transform(ArtID.begin(), ArtID.end(), ArtID.begin(), ::toupper);
    if(this->List_isNewArticle(ArtID))                         //Nếu là bài báo mới
    {   
        this->Article_count ++;                                //Tăng số lượng bài báo lên 1
        Article a;                                             //New Article
        a.Article_id = ArtID;
        cin >> a;
        a.Article_id = ArtID;
        if (List_isNewAuthor(a.Author_id))
        {
            cout << "Nhap thong tin tac gia:" << endl;
            List_AddAuthor(a.Author_id); //nếu tác giả nhập vào là tác giả mới thì thêm thông tin tác giả mới vào
        }
        Article newArticle[this->Article_count-1];             //Mảng tĩnh sao chép tạm danh sách bài báo khi chưa thêm
        for (int i=0; i<this->Article_count-1; i++)            //Sao chép bài báo từ List sang mảng tĩnh
        {
            newArticle[i] = this->Art[i];
        }
        delete []this->Art;                                    //Xóa danh sách bài báo cũ
        this->Art = new Article[this->Article_count];          //Tạo mảng động danh sách bài báo mới cho list
        this->Art[this->Article_count-1] = a;                  //Cho bài báo mới thêm vào cuối danh sách
        for (int i=0; i<this->Article_count-1; i++)
        {
            this->Art[i] = newArticle[i];                      //Chép từ mảng tạm sang danh sách chính
        }
    }
    else cout << "Bai bao da ton tai!" << endl;
}

/////////////////////////////////////////////////////////////MENU EDIT AUTHOR PROCESS//////////////////////////////////////////////////////////////
void List :: List_editAuthor() 
{
    char con = 'C'; //biến kiểm tra có tiếp tục công việc sửa thông tin tác giả (c/k)
    int i = 0; //Biến lấy phần tử tác giả trong list
    while (con == 'C')
    {
        string AuthID;
        cout << "Nhap ma tac gia can sua thong tin: ";
        cin >> AuthID;
        transform(AuthID.begin(), AuthID.end(), AuthID.begin(), ::toupper);
        if (List_isNewAuthor(AuthID)) cout << "Nhap sai ma tac gia!" << endl;
        else 
        {
            for (i=0; i<Author_count; i++)
            {
                if (Auth[i].author_id == AuthID) break;
            }
            editAuthor_General(Auth[i]);
        }
        cout << "Ban co muon tiep tuc khong? (c/k) ";
        cin >> con;
        con = toupper(con);
    }
}


/////////////////////////////////////////////////////////////EDIT AUTHOR GENERAL//////////////////////////////////////////////////////////////
void List :: editAuthor_General(Author &Auth) 
{
    cout << "1. Chinh sua ten tac gia" << endl << "2. Chinh sua noi cong tac" << endl;
    cout << "3. Chinh sua linh vuc lam viec" << endl << "4. Chinh sua trinh do" << endl << "5: Thoat" << endl;
    int type=0;
    while (type==0)
    {
        cout << "Nhap lua chon: ";
        cin >> type;
        switch (type)
        {
            case 1: 
                Auth.editAuthor_Name();
                editAuthor_General(Auth);
                break;
            case 2:
                Auth.editAuthor_Work();
                editAuthor_General(Auth);
                break;
            case 3: 
                Auth.editAuthor_Field();
                editAuthor_General(Auth);
                break;
            case 4:
                Auth.editAuthor_Degree();
                editAuthor_General(Auth);
                break;
            case 5:
                type=1;
                break;
            default:
                type = 0;
        }
    }
}








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
///////////////////////////////////////////////////////////////// SORT ///////////////////////////////////////////////////////////
bool YearAscending(Article x, Article y)
{
    if(x.getPublish_Time() > y.getPublish_Time()) return true;
    else return false;
}
bool YearDescending(Article x, Article y)
{
    if(x.getPublish_Time() < y.getPublish_Time()) return true;
    else return false;
}
// đổi chỗ 2 bài báo
void SWAP(Article &x, Article &y)
{
    Article temp;
    temp = x;
    x = y;
    y = temp;
}
//////////////////////////////////////////////////////////// SORT BY YEAR //////////////////////////////////////////////////////////// 
void List::List_SortArtByYear( bool (*SS)(Article, Article))
{
    for(int i=0;i <Article_count ;i++)
    {
        for(int j=i+1; j< Article_count ;j++)
        {
            if( (*SS) (Art[i], Art[j]))
            {
                SWAP(Art[i], Art[j]);

            }
        }
    }
    List::List_displayAll();
}
//////////////////////////////////////////////////////////// SORT BY AUTHOR NAME //////////////////////////////////////////////////////////// 

void List::List_SortArtByNameAuthor()
{
    for(int i =0;i<Article_count;i++)
    {
        for(int j=i+1;j<Article_count;j++)
        {
            if(this->List_getAuthorLastNamebyID(Art[i].Author_id).compare(this->List_getAuthorLastNamebyID(Art[j].Author_id)) ==1)
            {
                SWAP(Art[i], Art[j]);
            }
        }
    }
    List::List_displayAll();
}
//////////////////////////////////////////////////////////// SORT BY ARTICLE NAME//////////////////////////////////////////////////////////// 
bool ArtNameAscending(Article x, Article y)
{
    if(x.getArticleName().compare(y.getArticleName() ) == 1) return true;
    else return false;
}
bool ArtNameDescending(Article x, Article y)
{
    if(x.getArticleName().compare(y.getArticleName() ) != 1) return true;
    else return false;
}
void List::List_SortArtByNameArticle(bool (*SS)(Article, Article))
{
    for(int i =0;i<Article_count;i++)
    {
        for(int j=i+1;j<Article_count;j++)
        {
            if((*SS) (Art[i], Art[j]) )
            {
                SWAP(Art[i], Art[j]);
            }
        }
    }
    List::List_displayAll();

}


/////////////////////////////////////////////////////////////MAIN//////////////////////////////////////////////////////////////
int main() 
{

    List L;
    // Lay so luong
    ifstream inFileNum("../Data/NumOfData.txt");
    L.get_initialNum(inFileNum);
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

    // L.List_dislayArtByAuthID(); // Hiển thị các bài báo của 1 tác giả theo ID
    // L.List_displayArtByJourID();// Hiển thị các bài báo của 1 tạp chí theo ID
    //L.List_displayArtByPublID(); // Hiển thị các bài báo của 1 NXB theo ID
    // L.List_displayArtByYear(); // Hiển thị các bài báo của 1 năm
    L.List_editArticle();
    L.List_displayAll();
    L.List_displayJournal();
    L.List_displayPublisher();

    inFileArt.close();
    inFileJou.close();
    inFileAuth.close();
    inFilePub.close();

    return 0;
}
////////// - add article, author, publisher, journal xong
////////// - edit article, author, publisher, journal xong
// - check INPUT
// 
/////////  - em Thịnh viết hàm transfrom