#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "Author.h"
#include "Journal.h"
#include "Article.h"
#include "Publisher.h"
#include "List.h"
using namespace std;
#define getenter fflush(stdin);
void removeSpaces(string &str)
{
    string nstr;
    int i=0;
    while (i<str.length())
    {
        if (str[i]==' ') i++;
        else break;
    }
    for(; i<str.length();  ){
        if(str[i] == ' '){
            while(str[i+1] == ' ')
                i++;
        }
        nstr += str[i++];
    }
    str = nstr;
}

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
    removeSpaces(a.firstName);
    cout << "Nhap ten: ";
    cin >> a.lastName;
    removeSpaces(a.lastName);
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
    removeSpaces(firstName);
    cout << "Nhap ten: ";
    getenter;
    getline(cin,lastName);
    removeSpaces(lastName);
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
    string pub;
    cout << "Nhap ten tap chi: ";
    getenter;
    getline(in,j.J_name);
    removeSpaces(j.J_name);
    cout << "Nhap tong bien tap: ";
    getenter;
    getline(in,j.J_editor);
    cout << "Nhap ma NXB: ";
    in >> pub;
    transform(pub.begin(), pub.end(), pub.begin(), ::toupper);
    j.Publisher_id = pub;
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
    string auth, jou;
    cout << "Nhap ten bai bao: ";
    getenter;
    getline(cin, a.Article_name);
    removeSpaces(a.Article_name);
    cout << "Nhap ma tac gia: ";
    cin >> auth;
    transform(auth.begin(), auth.end(), auth.begin(), ::toupper);
    a.Author_id = auth;
    cout << "Nhap ma tap chi: ";
    cin >> jou;
    transform(jou.begin(), jou.end(), jou.begin(), ::toupper);
    a.Journal_id = jou;
    cout << "Nhap thoi gian cong bo: ";
    cin >> a.Publish_time;
    return in;
}


void Article :: editArticle_Name()
{   
    cout << "Nhap moi ten: ";
    fflush(stdin);
    getline(cin,Article_name);
    removeSpaces(Article_name);
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
////////////////////////////////////////////////////GET DATA///////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////DISPLAY CÁC LIST/////////////////////////////////////////////////////////////////////////
void List::List_displayPublisher()
{

    cout<< left << setw (15) <<"Ma NXB"<< "Ten NXB" << endl;
    for(int i =0;i < Publisher_count;i++)
    {
        cout<< Pub[i];
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

void List::List_displayJournal()
{
    cout << left << setw(15) << "Ma tap chi" << left << setw(50) << "Ten tap chi" << left << setw(30) << "Ten tong bien tap" << left << setw(10) << "Ma NXB"<<endl;
    for(int i=0;i<Journal_count;i++)
    {
        cout<<Jou[i];
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

/////////////////////////////////////////////////GET PRIVATE MEMBER OF AUTHOR CLASS///////////////////////////////////////////////////////////
string List ::List_getAuthorNamebyID(string Author_ID)
{
    for(int i = 0; i < Author_count; i++)
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


////////////////////////////////////////////////////////////EDIT////////////////////////////////////////////////////////////////////

//////////////////MENU EDIT ARTICLE PROCESS//////////////////////////////////
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


/////////////////////////////EDIT ARTICLE GENERAL//////////////////////////////
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

////////////////MENU EDIT JOURNAL PROCESS/////////////////
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


//////////////////////////////EDIT JOURNAL GENERAL///////////////////////////////
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
////////////////////////////////EDIT PUBLISHER PROCESS//////////////////////////
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
///////////////////////////MENU EDIT AUTHOR PROCESS////////////////////////////
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

////////////////////////////EDIT AUTHOR GENERAL/////////////////////////////
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
//////////////////////////////////////////////////////////CHECK NEWWWWWWWWWWWWW//////////////////////////////////////////////////////

//////////////////////////Check new Author///////////////////////////
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
/////////////////////////Check new Journal/////////////////////////
bool List::List_isNewJournal(string JournalID)
{
    for(int i=0;i < Journal_count; i++)
    {
        if(this->Jou[i].J_id == JournalID) return false;
    }
    return true;
}
/////////////////////////////Check new Publisher///////////////
bool List::List_isNewPublisher(string PublisherID)
{
    for(int i=0;i < Publisher_count;i++)
    {
        if(this->Pub[i].Publisher_id == PublisherID) return false;;
    }
    return true;
}
//////////////////////////check new article////////////////////////
bool List::List_isNewArticle(string ArtID) 
{
     for(int i=0;i < Article_count; i++)
    {
        if(this->Art[i].Article_id == ArtID) return false;
    }
    return true;
}; 

/////////////////////////////////////////////////////////////ADD OBJECT//////////////////////////////////////////////////////////////

//////////////////////////////////////Thêm tác giả///////////////////////////////////////
void List::List_AddAuthor(string AuthorID)
{
    transform(AuthorID.begin(), AuthorID.end(), AuthorID.begin(), ::toupper);
    if (this->List_isNewAuthor(AuthorID))                     //Nếu là tác giả mới
    {   
        this->Author_count ++;                                //Tăng số lượng tác giả lên 1
        Author a;                                             //New Author
        a.author_id = AuthorID;
        cin >> a;
        Author newAuthor[this->Author_count-1];               //Mảng tĩnh sao chép tạm danh sách tác giả khi chưa thêm
        for (int i=0; i<this->Author_count-1; i++)            //Sao chép tác giả từ List sang mảng tĩnh
        {
            newAuthor[i] = this->Auth[i];
        }
        delete []this->Auth;                                   //Xóa danh sách tác giả cũ
        this->Auth = new Author[this->Author_count];           //Tạo mảng động danh sách tác giả mới cho list
        this->Auth[this->Author_count-1] = a;                  //Cho tác giả mới thêm vào cuối danh sách
        for (int i=0; i<this->Author_count-1; i++)
        {
            this->Auth[i] = newAuthor[i];                      //Chép từ mảng tạm sang danh sách chính
        }
        //this->List_overwriteNewAuthor();                       //Update vào file dữ liệu tác giả
        //this->List_overwriteInitialNumber();                   //Update file số lượng
    }
    else cout << "Tac gia da ton tai!" << endl;
}

//////////////////////THÊM NXB////////////////////////////////////////////
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
        //this->List_overwriteNewPublisher();                       //Update vào file dữ liệu NXB
        //this->List_overwriteInitialNumber();                        //Update vào file số lượng
    }
    else cout << "NXB da ton tai!";
}

////////////////////////////////////////Thêm TẠP CHÍ/////////////////////////////////////////
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
        //this->List_overwriteNewJournal();                      //Update vào file dữ liệu tạp chí
        //this->List_overwriteInitialNumber();                   //Update file số lượng
    }
    else cout << "Tap chi da ton tai!";
}

////////////////////////////////THÊM BÀI BÁO VÀO CUỐI///////////////////////////////////
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
        if (List_isNewJournal(a.Journal_id))
        {
            cout << "Nhap thong tin tap chi:" << endl;
            List_AddJournal(a.Journal_id); //nếu tạp chí nhập vào là tạp chí mới thì thêm thông tin tạp chí mới vào
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
        //this->List_overwriteNewArticle();                      //Update vào file dữ liệu bài báo
        //this->List_overwriteInitialNumber();                   //Update file số lượng
    }
    else cout << "Bai bao da ton tai!" << endl;
}
////////////////////////////////THÊM BÀI BÁO VÀO VỊ TRÍ BẤT KÌ///////////////////////////////////
void List::List_InsertArticle(string ArtID) 
{
    transform(ArtID.begin(), ArtID.end(), ArtID.begin(), ::toupper);
    if(this->List_isNewArticle(ArtID))                         //Nếu là bài báo mới
    {   
        this->Article_count ++;                                //Tăng số lượng bài báo lên 1
        int pos; //Vị trí thêm bài báo
        cout << "Nhap vi tri muon them: ";
        cin >> pos;
        Article a;                                             //New Article
        a.Article_id = ArtID;
        cin >> a;
        if (List_isNewAuthor(a.Author_id))
        {
            cout << "Nhap thong tin tac gia:" << endl;
            List_AddAuthor(a.Author_id); //nếu tác giả nhập vào là tác giả mới thì thêm thông tin tác giả mới vào
        }
        if (List_isNewJournal(a.Journal_id))
        {
            cout << "Nhap thong tin tap chi:" << endl;
            List_AddJournal(a.Journal_id); //nếu tạp chí nhập vào là tạp chí mới thì thêm thông tin tạp chí mới vào
        }
        Article newArticle[this->Article_count-1];             //Mảng tĩnh sao chép tạm danh sách bài báo khi chưa thêm
        for (int i=0; i<this->Article_count-1; i++)            //Sao chép bài báo từ List sang mảng tĩnh
        {
            newArticle[i] = this->Art[i];
        }
        delete []this->Art;                                    //Xóa danh sách bài báo cũ
        this->Art = new Article[this->Article_count];          //Tạo mảng động danh sách bài báo mới cho list
        for (int i=0; i<pos-1; i++)
        {
            this->Art[i] = newArticle[i];                      //Chép bài báo từ vị trí 0->pos-2 từ mảng tạm sang danh sách chính
        }
        for (int i=pos; i<Article_count; i++)
        {
            this->Art[i] = newArticle[i-1];                      //Chép bài báo từ vị trí pos->Artcount-1 từ mảng tạm sang danh sách chính
        }
        Art[pos-1] = a;
        //this->List_overwriteNewArticle();                      //Update vào file dữ liệu bài báo
        //this->List_overwriteInitialNumber();                   //Update file số lượng
    }
    else cout << "Bai bao da ton tai!" << endl;
}
////////////////////////////////////////Hàm update số lượng bài báo của List Author, Journal, Publisher///////////////////////////////////////
void List::List_UpdateNumArtOfAllList()
{
    for(int i=0;i<Author_count;i++) //Update SL bài báo cho list Author
    {
        Auth[i].Article_count = 0; //reset SL bài báo của list Author
        {
            for(int j =0; j< Article_count;j++)
            {
                if(Auth[i].author_id == Art[j].Author_id) Auth[i].Article_count+=1;
            }
        }
    }
    for(int i=0;i<Journal_count;i++) //Update SL bài báo cho list Journal
    {
        Jou[i].Article_count = 0; //reset SL bài báo của list Journal
        for(int j=0;j<Article_count;j++)
        {
            if(Jou[i].J_id == Art[j].Journal_id) Jou[i].Article_count +=1;
        }
    }
    for(int i=0;i<Publisher_count;i++) //Update SL bài báo cho list Journal
    {
        Pub[i].Article_count = 0; //reset SL bài báo của list Publisher
        for(int j =0;j < Article_count;j++)
        {
            if(Pub[i].Publisher_id == this->List_getPublisherIDbyJourID(Art[j].Journal_id ) ) Pub[i].Article_count+=1;
        }
    }
}

    
/////////////////////////////////////////////////THỐNG KÊ//////////////////////////////////////////////////////////////////////////////
void List::List_displayNumofArtPerAuth()
{
    cout<< left<< setw(25)<<"Tac gia"<< left<< setw(10)<<"So bai bao"<<endl;
    for(int i=0;i< Author_count;i++)
    {
        cout<< left<< setw(25)<<Auth[i].getName()<< left<< setw(10)<<Auth[i].Article_count<<endl;
    }
}


void List::List_displayNumofArtPerJour()
{
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
    cout<< left<< setw(40)<<"Nha xuat ban"<< left<< setw(10)<<"So bai bao"<<endl;
    for(int i=0;i<Publisher_count;i++)
    {
        cout<< left<< setw(40)<<Pub[i].Publisher_name<< left<< setw(10)<<Pub[i].Article_count<<endl;
    }
}

void List ::List_displayNumofArtPerYear()
{    
}


///////////////////////////////////////////////////////DELETE/////////////////////////////////////////////////////////////////////

///////////////////////////////XÓA BÀI BÁO THEO MÃ/////////////////////////////////
void List::List_DeleteArticleByArtID(string ArtID) 
{
    transform(ArtID.begin(), ArtID.end(), ArtID.begin(), ::toupper);
    if(this->List_isNewArticle(ArtID)) cout << "Bai bao chua ton tai!" << endl;
    else
    {   
        int pos;
        for (int i=0; i<Article_count; i++)
        {
            if (Art[i].Article_id == ArtID) 
            {
                pos = i;
                break;
            }
        }
        Article newArticle[this->Article_count];             //Mảng tĩnh sao chép tạm danh sách bài báo khi chưa xóa
        for (int i=0; i<this->Article_count; i++)            //Sao chép bài báo từ List sang mảng tĩnh
        {
            newArticle[i] = this->Art[i];
        }
        delete []this->Art;                                    //Xóa danh sách bài báo cũ
        this->Article_count --;                             //Giảm SL bài báo đi 1
        this->Art = new Article[this->Article_count];          //Tạo mảng động danh sách bài báo mới cho list
        for (int i=0; i<pos; i++)
        {
            this->Art[i] = newArticle[i];                      //Chép bài báo từ vị trí 0->pos-1 từ mảng tạm sang danh sách chính
        }
        for (int i=pos; i<Article_count; i++)
        {
            this->Art[i] = newArticle[i+1];                      //Chép bài báo từ vị trí pos->Artcount-1 từ mảng tạm sang danh sách chính
        }
        cout << "Xoa thanh cong!"<<endl;
        //this->List_overwriteNewArticle();                      //Update vào file dữ liệu bài báo
        //this->List_overwriteInitialNumber();                   //Update file số lượng
    }
}
///////////////////////////////XÓA BÀI BÁO THEO VỊ TRÍ/////////////////////////////////
void List::List_DeleteArticleByPos(int pos) 
{
    if (pos <0 || pos > Article_count -1) 
    {
        cout << "Xoa khong thanh cong!"<<endl;
        return;
    }
    else
    {
    Article newArticle[this->Article_count];             //Mảng tĩnh sao chép tạm danh sách bài báo khi chưa xóa
    for (int i=0; i<this->Article_count; i++)            //Sao chép bài báo từ List sang mảng tĩnh
    {
        newArticle[i] = this->Art[i];
    }
    delete []this->Art;                                    //Xóa danh sách bài báo cũ
    this->Article_count --;                             //Giảm SL bài báo đi 1
    this->Art = new Article[this->Article_count];          //Tạo mảng động danh sách bài báo mới cho list
    for (int i=0; i<pos; i++)
    {
        this->Art[i] = newArticle[i];                      //Chép bài báo từ vị trí 0->pos-1 từ mảng tạm sang danh sách chính
    }
    for (int i=pos; i<Article_count; i++)
    {
        this->Art[i] = newArticle[i+1];                      //Chép bài báo từ vị trí pos->Artcount-1 từ mảng tạm sang danh sách chính
    }
    cout << "Xoa thanh cong!"<<endl;
    //this->List_overwriteNewArticle();                      //Update vào file dữ liệu bài báo
    //this->List_overwriteInitialNumber();                   //Update file số lượng  
    }
}
///////////////////////////////XÓA TÁC GIẢ THEO MÃ/////////////////////////////////
void List::List_DeleteAuthorByAuthID(string AuthID) 
{
    transform(AuthID.begin(), AuthID.end(), AuthID.begin(), ::toupper);
    if(this->List_isNewAuthor(AuthID)) cout << "Tac gia chua ton tai!" << endl;
    else
    {   
        int pos; char c='C';
        for (int i=0; i<Author_count; i++)
        {
            if (Auth[i].author_id == AuthID) 
            {
                pos = i;
                break;
            }
        }
        if (Auth[pos].Article_count > 0)
        {
            cout << "Tac gia da co " << Auth[pos].Article_count << " bai bao. Ban co muon xoa tac gia? (c/k) ";
            cin >> c;
            c = toupper(c);
        } 
        if (c == 'C')
        {
            Author newAuthor[this->Author_count];             //Mảng tĩnh sao chép tạm danh sách tác giả khi chưa xóa
            for (int i=0; i<this->Author_count; i++)            //Sao chép tác giả từ List sang mảng tĩnh
            {
                newAuthor[i] = this->Auth[i];
            }
            delete []this->Auth;                                    //Xóa danh sách tác giả cũ
            this->Author_count --;                             //Giảm SL tác giả đi 1
            this->Auth = new Author[this->Author_count];          //Tạo mảng động danh sách tác giả mới cho list
            for (int i=0; i<pos; i++)
            {
                this->Auth[i] = newAuthor[i];                      //Chép tác giả từ vị trí 0->pos-1 từ mảng tạm sang danh sách chính
            }
            for (int i=pos; i<Author_count; i++)
            {
                this->Auth[i] = newAuthor[i+1];                      //Chép tác giả từ vị trí pos->Artcount-1 từ mảng tạm sang danh sách chính
            }
            cout << "Xoa thanh cong!"<<endl;
            //this->List_overwriteNewAuthor();                      //Update vào file dữ liệu tác giả
            //this->List_overwriteInitialNumber();                   //Update file số lượng
        }
        
    }
}
///////////////////////////////XÓA TẠP CHÍ THEO MÃ/////////////////////////////////
void List::List_DeleteJournalByJouID(string JouID) 
{
    transform(JouID.begin(), JouID.end(), JouID.begin(), ::toupper);
    if(this->List_isNewJournal(JouID)) cout << "Tap chi chua ton tai!" << endl;
    else
    {   
        int pos; char c='C';
        for (int i=0; i<Journal_count; i++)
        {
            if (Jou[i].J_id == JouID) 
            {
                pos = i;
                break;
            }
        }
        if (Jou[pos].Article_count > 0)
        {
            cout << "Tap chi da co " << Jou[pos].Article_count << " bai bao. Ban co muon xoa tap chi? (c/k) ";
            cin >> c;
            c = toupper(c);
        } 
        if (c == 'C')
        {
            Journal newJournal[this->Journal_count];             //Mảng tĩnh sao chép tạm danh sách TẠP CHÍ khi chưa xóa
            for (int i=0; i<this->Journal_count; i++)            //Sao chép TẠP CHÍ từ List sang mảng tĩnh
            {
                newJournal[i] = this->Jou[i];
            }
            delete []this->Jou;                                    //Xóa danh sách TẠP CHÍ cũ
            this->Journal_count --;                             //Giảm SL TẠP CHÍ đi 1
            this->Jou = new Journal[this->Journal_count];          //Tạo mảng động danh sách TẠP CHÍ mới cho list
            for (int i=0; i<pos; i++)
            {
                this->Jou[i] = newJournal[i];                      //Chép TẠP CHÍ từ vị trí 0->pos-1 từ mảng tạm sang danh sách chính
            }
            for (int i=pos; i<Journal_count; i++)
            {
                this->Jou[i] = newJournal[i+1];                      //Chép TẠP CHÍ từ vị trí pos->Artcount-1 từ mảng tạm sang danh sách chính
            }
            cout << "Xoa thanh cong!"<<endl;
            //this->List_overwriteNewJournal();                      //Update vào file dữ liệu TẠP CHÍ
            //this->List_overwriteInitialNumber();                   //Update file số lượng
        }
        
    }
}
///////////////////////////////XÓA NXB THEO MÃ/////////////////////////////////
void List::List_DeletePublisherByPubID(string PubID) 
{
    transform(PubID.begin(), PubID.end(), PubID.begin(), ::toupper);
    if(this->List_isNewPublisher(PubID)) cout << "NXB chua ton tai!" << endl;
    else
    {   
        int pos; char c='C';
        for (int i=0; i<Publisher_count; i++)
        {
            if (Pub[i].Publisher_id == PubID) 
            {
                pos = i;
                break;
            }
        }
        if (Pub[pos].Article_count > 0)
        {
            cout << "NXB da co " << Pub[pos].Article_count << " bai bao. Ban co muon xoa NXB? (c/k) ";
            cin >> c;
            c = toupper(c);
        } 
        if (c == 'C')
        {
            Publisher newPublisher[this->Publisher_count];             //Mảng tĩnh sao chép tạm danh sách NXB khi chưa xóa
            for (int i=0; i<this->Publisher_count; i++)            //Sao chép NXB từ List sang mảng tĩnh
            {
                newPublisher[i] = this->Pub[i];
            }
            delete []this->Pub;                                    //Xóa danh sách NXB cũ
            this->Publisher_count --;                             //Giảm SL NXB đi 1
            this->Pub = new Publisher[this->Publisher_count];          //Tạo mảng động danh sách NXB mới cho list
            for (int i=0; i<pos; i++)
            {
                this->Pub[i] = newPublisher[i];                      //Chép NXB từ vị trí 0->pos-1 từ mảng tạm sang danh sách chính
            }
            for (int i=pos; i<Publisher_count; i++)
            {
                this->Pub[i] = newPublisher[i+1];                      //Chép NXB từ vị trí pos->Artcount-1 từ mảng tạm sang danh sách chính
            }
            cout << "Xoa thanh cong!"<<endl;
            //this->List_overwriteNewPublisher();                      //Update vào file dữ liệu NXB
            //this->List_overwriteInitialNumber();                   //Update file số lượng
        }
        
    }
}


///////////////////////////////////////////////////////////////OVERWRITE///////////////////////////////////////////////////////////////////

/////////////////////////////Ghi mới vào file Author.txt///////////////
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
/////////////////////////////Ghi mới vào file Article.txt////////////////
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
/////////////////////////////// Ghi mới vào file Journal.txt///////
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
////////////////////////////////Ghi mới vào file Publiser.txt///////
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
/////////////////////////////Ghi mới vào file InitialNum////////////////
void List::List_overwriteInitialNumber()
{
    ofstream outFile("../Data/InitialNum.txt", ofstream::trunc);
    outFile << "Article|";
    outFile <<  Article_count << "\n";
    outFile << "Author|";
    outFile <<  Author_count << "\n";
    outFile << "Journal|";
    outFile <<  Journal_count << "\n";
    outFile << "Publisher|";
    outFile <<  Publisher_count;
    outFile.close();
}

///////////////////////////////////////////////////////////////// SORT ///////////////////////////////////////////////////////////

//////////////////////////
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
//////////////////////////// SORT BY YEAR //////////////////////////// 
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
/////////////////////////////////////SORT BY AUTHOR NAME /////////////////////////////////////

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
/////////////////////////////////////SORT BY ARTICLE NAME/////////////////////////////////////
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
///////////////////////////////////////////////////////////FIND ARTICLE///////////////////////////////////////////////////////
bool List::List_FindArticleByName(string name)
{   
    bool flag = false;
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    for (int i=0; i<Article_count; i++)
    {
        string temp = Art[i].Article_name;
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if (temp.find(name) != string::npos)
        {
            if (flag==false) 
            {
                cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                flag=true;;
            }
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25);
            cout << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl; 
        }
    }
    return flag;
}
bool List::List_FindArticleByAuthorName()
{
    bool flag = false;
    cout<<"Nhap ten tac gia can tim kiem: ";
    string Ten;
    getenter;
    getline(cin,Ten);
    removeSpaces(Ten);
    transform(Ten.begin(), Ten.end(),Ten.begin(), ::toupper);
    for(int i=0;i<Article_count;i++)
    {
        string temp = this->List_getAuthorNamebyID(Art[i].Author_id);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        if(temp.find(Ten) != string::npos)
        {
            if (flag==false) 
            {
                cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                flag=true;;
            }
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25);
            cout << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
        }
    }    
    return flag;
}
bool List::List_FindArtByAuthID()
{
    string temp; bool flag = false;
    do
    {
        cout<<"Nhap ma tac gia can tim kiem: ";
        cin>>temp;
        removeSpaces(temp);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    }
    while(this->List_isNewAuthor(temp));
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Author_id == temp)
        {
            if (flag==false) 
            {
                cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                flag=true;
            }
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
        }
    }
    return flag;
}
// Hiển thị bài báo theo ID của tạp chí
bool List::List_FindArtByJourID()
{
    string temp; bool flag = false;
    do
    {
        cout<<"Nhap ma tap chi can tim kiem: ";
        cin>>temp;
        removeSpaces(temp);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        
    }
    while(this->List_isNewJournal(temp));
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Journal_id == temp)
        {
            if (flag==false) 
            {
                cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                flag=true;;
            }
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
        }
    }
    return flag;
}
// Hiển thị bài báo theo ID của nhà xuất bản
bool List::List_FindArtByPublID()
{
    string temp; bool flag = false;
    do
    {
        cout<<"Nhap ma NXB can tim kiem: ";
        cin>>temp;
        removeSpaces(temp);
        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
        
    }
    while(this->List_isNewPublisher(temp));
    for(int i=0;i< Article_count;i++)
    {
        if(this->List_getPublisherIDbyJourID(Art[i].Journal_id) == temp)
        {
            if (flag==false) 
            {
                cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                flag=true;;
            }
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
        }
    }
    return flag;
}
// Hiển thị bài báo theo năm
bool List::List_FindArtByYear()
{
    int temp; bool flag = false;
    cout<<"Nhap nam can tim kiem: ";
    cin>> temp;
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Publish_time == temp)
        {
            if (flag==false) 
            {
                cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                flag=true;;
            }
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
        }
    }
    return flag;
}
// Hiển thị bài báo theo Art ID
bool List::List_FindArtByArtID()
{
    string temp; bool flag = false;
    cout<<"Nhap ma bai bao can tim kiem: ";
    cin>> temp;
    removeSpaces(temp);
    transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
    for(int i=0;i< Article_count;i++)
    {
        if(Art[i].Article_id == temp)
        {
            if (flag==false) 
            {
                cout<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                flag=true;;
            }
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
        }
    }
    return flag;
}
void MENU(List L)
{
    string Tenbaibao;
    string chon;
    string Mabaibao;
    string Matacgia;
    string Matapchi;
    string MaNXB;
    int pos;
    int temp;
    do
    {
        cout<<endl<<endl<<"===== QUAN LY CAC BAI BAO KHOA HOC ====="<<endl<<endl<<endl;
        cout<<"1. Hien thi thong tin"<<endl;
        cout<<"2. Thong ke"<<endl;
        cout<<"3. Tim kiem"<<endl;
        cout<<"4. Sap xep"<<endl;
        cout<<"5. Chinh sua"<<endl;
        cout<<"6. Chen"<<endl;
        cout<<"7. Xoa"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon cua ban: ";
        cin>>temp;
        switch (temp)
        {
        case 0:
            temp =0;
            cout<<"Chuc ban mot ngay moi tot lanh!"<<endl;
            break;
        case 1:
            int temp1;
            system("cls");
            do
            {
            cout<<"==== HIEN THI THONG TIN ===="<<endl<<endl;
            cout<<"1. Theo bai bao"<<endl; 
            cout<<"2. Theo tac gia"<<endl;
            cout<<"3. Theo tap chi"<<endl;
            cout<<"4. Theo nha xuat ban"<<endl;
            cout<<"0. Thoat"<<endl;
            cout<<"Vui long nhap lua chon cua ban: ";
            cin>>temp1;
            switch (temp1)
                {
                case 0:
                    temp1 =0;
                    system("cls");
                    break;
                case 1:
                    L.List_displayAll();
                    system("pause");
                    system("cls");
                    temp1 =0;
                    break;
                case 2:
                    L.List_displayAuthor();
                    system("pause");
                    system("cls");
                    temp1 =0;
                    break;
                case 3:
                    L.List_displayJournal();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    L.List_displayPublisher();
                    system("pause");
                    system("cls");
                    temp1 =0;
                    break;
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
            } 
            while(temp1);
            break;
        case 2:
            int temp2;
            system("cls");
            do
            {
                cout<<"==== THONG KE ===="<<endl<<endl;
                cout<<"1. So luong bai bao theo tac gia"<<endl;
                cout<<"2. So luong bai bao theo tap chi"<<endl;
                cout<<"3. So luong bai bao theo nha xuat ban"<<endl;
                cout<<"4. So luong bai bao theo nam"<<endl;
                cout<<"0. Thoat"<<endl;
                cout<<"Vui long nhap lua chon cua ban: ";
                cin>>temp2;
                switch (temp2)
                {
                case 0:
                    temp2 = 0;
                    system("cls");
                    break;
                case 1:
                    L.List_displayNumofArtPerAuth();
                    system("pause");
                    system("cls");
                    temp2 = 0;
                    break;
                case 2:
                    L.List_displayNumofArtPerJour();
                    system("pause");
                    system("cls");
                    temp2 = 0;
                    break;
                case 3:
                    L.List_displayNumofArtPerPubl();
                    system("pause");
                    system("cls");
                    temp2 = 0;
                    break;
                case 4:
                    // chua co
                    system("pause");
                    system("cls");
                    temp2 = 0;
                    break;
                
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
            }
            while(temp2);
        break;
        case 3:
        
            system("cls");
            int temp3;
            do
            {
                cout<<"==== TIM KIEM ===="<<endl<<endl;
                cout<<"1. Theo ten bai bao"<<endl;
                cout<<"2. Theo ma bai bao"<<endl;
                cout<<"3. Theo ten tac gia"<<endl;
                cout<<"4. Theo ma tac gia"<<endl;
                cout<<"5. Theo ma tap chi"<<endl;
                cout<<"6. Theo ma NXB"<<endl;
                cout<<"7. Theo nam xuat ban"<<endl;
                cout<<"0. Thoat"<<endl;
                cout<<"Vui long nhap lua chon cua ban: ";
                cin>>temp3;
                switch (temp3)
                {
                case 0:
                    temp3 =0;
                    system("cls");
                    break;
                case 1:
                cout<<"Nhap ten bai bao can tim kiem: ";
                getenter;
                getline(cin,Tenbaibao);
                removeSpaces(Tenbaibao);
                if(L.List_FindArticleByName(Tenbaibao)==false) cout << "Khong tim thay bai bao!"<<endl;
                system("pause");
                system("cls");
                temp3 =0;
                break;
                case 2:
                if(L.List_FindArtByArtID()==false) cout << "Khong tim thay bai bao!"<<endl;
                system("pause");
                system("cls");
                temp3 =0;
                break;
                case 3:
                if(L.List_FindArticleByAuthorName()==false) cout << "Khong tim thay bai bao!"<<endl;
                system("pause");
                system("cls");
                temp3 =0;
                break;
                case 4:
                if(L.List_FindArtByAuthID()==false) cout << "Khong tim thay bai bao!"<<endl;
                system("pause");
                system("cls");
                temp3 =0;
                break;
                case 5:
                if(L.List_FindArtByJourID()==false) cout << "Khong tim thay bai bao!"<<endl;
                system("pause");
                system("cls");
                temp3 =0;
                break;
                case 6:
                if(L.List_FindArtByPublID()==false) cout << "Khong tim thay bai bao!"<<endl;
                system("pause");
                system("cls");
                temp3 =0;
                break;
                case 7:
                if(L.List_FindArtByYear()==false) cout << "Khong tim thay bai bao!"<<endl;
                system("pause");
                system("cls");
                temp3 =0;
                break;
                default:
                cout<<"Ban da nhap sai!!!"<<endl;
                system("cls");
                break;
                }       
                
            } while (temp3);
        break;
        case 4:
            system("cls");
            int temp4;
            do
            {   
                cout<<"==== SAP XEP ===="<<endl<<endl;
                cout<<"1. Theo tac gia"<<endl;
                cout<<"2. Theo ten bai bao"<<endl;
                cout<<"3. Theo nam"<<endl;
                cout<<"0. Thoat"<<endl;
                cout<<"Vui long nhap lua chon cua ban: ";
                cin>>temp4;
                switch (temp4)
                {
                case 0:
                    temp4 =0;
                    system("cls");
                    break;
                case 1:
                    L.List_SortArtByNameAuthor();
                    system("pause");
                    system("cls");
                    temp4 =0;
                    break;
                case 2:
                    cout<<"Ban muon sap xep tang dan hay giam dan?(T/G): ";
                    cin>>chon;
                    transform(chon.begin(), chon.end(), chon.begin(), ::toupper);
                    if(chon == "T")
                    {
                        L.List_SortArtByNameArticle(ArtNameAscending);
                    }
                    else if (chon == "G") 
                    {
                        L.List_SortArtByNameArticle(ArtNameDescending);
                    }
                    system("pause");
                    system("cls");
                    temp4 =0;
                    break;
                case 3:
                    cout<<"Ban muon sap xep tang dan hay giam dan?(T/G): ";
                    cin>>chon;
                    transform(chon.begin(), chon.end(), chon.begin(), ::toupper);
                    if(chon == "T")
                    {
                        L.List_SortArtByYear(YearAscending);
                    }
                    else if(chon == "G" ) 
                    {
                        L.List_SortArtByYear(YearDescending);
                    }
                    system("pause");
                    system("cls");
                    temp4 =0;
                    break;

                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
                
            } 
            while (temp4);
        break;
        case 5: 
            system("cls");
            int temp5;
            do
            {
                cout<<"==== CHINH SUA THONG TIN ===="<<endl<<endl;
                cout<<"1. Bai bao"<<endl;
                cout<<"2. Tac gia"<<endl;
                cout<<"3. Tap chi"<<endl;
                cout<<"4. Nha xuat ban"<<endl;
                cout <<"0. Thoat"<<endl;
                cout<<"Vui long nhap lua chon cua ban: ";
                cin>>temp5;
                switch (temp5)
                {
                case 0:
                    temp5 =0; 
                    system("cls");
                    break;
                case 1:
                    L.List_editArticle();
                    //L.List_overwriteNewArticle();
                    system("pause");
                    system("cls");
                    temp5 =0;
                    break;
                case 2:
                    L.List_editAuthor();
                    //L.List_overwriteNewAuthor();
                    system("pause");
                    system("cls");
                    temp5 =0;
                    break;
                case 3:
                    L.List_editJournal();
                    //L.List_overwriteNewJournal();
                    system("pause");
                    system("cls");
                    temp5 =0;
                    break;
                case 4:
                    L.List_editPublisher();
                    //L.List_overwriteNewPublisher();
                    system("pause");
                    system("cls");
                    temp5 =0;
                    break;
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
            } while (temp5);
            break;
        case 6:
            system("cls");
            int temp6;
            do
            {
                cout<<"==== THEM ===="<<endl<<endl;
                cout<<"1. Bai bao"<<endl;
                cout<<"2. Tac gia"<<endl;
                cout<<"3. Tap chi"<<endl;
                cout<<"4. Nha xuat ban"<<endl;
                cout<<"0. Thoat"<<endl;
                cout<<"Vui long nhap lua chon cua ban: ";
                cin>>temp6;
                switch (temp6)
                {
                case 0:
                    temp6 =0;
                    system("cls");
                    break;
                case 1:
                    system("cls");
                    int case1;
                    do 
                    {   
                        cout<<"==== THEM BAI BAO ===="<<endl<<endl;
                        cout << "1. Mac dinh"<<endl;
                        cout << "2. Vi tri bat ki"<<endl;
                        cout << "0. Thoat"<<endl;
                        cout <<"Vui long nhap lua chon cua ban: ";
                        cin >> case1;
                        switch (case1)
                        {
                            case 1:
                                cout << "Nhap ma bai bao: ";
                                cin >> Mabaibao;
                                removeSpaces(Mabaibao);
                                L.List_AddArticle(Mabaibao);
                                //L.List_UpdateNumArtOfAllList();
                                system("pause");
                                system("cls");
                                case1 = 0;
                                break;
                            case 2:
                                cout << "Nhap ma bai bao: ";
                                cin >> Mabaibao;
                                removeSpaces(Mabaibao);
                                L.List_InsertArticle(Mabaibao);
                                //L.List_UpdateNumArtOfAllList();
                                system("pause");
                                system("cls");
                                case1 = 0;
                                break;
                            case 0:
                                case1 = 0;
                                system("pause");
                                system("cls");
                                break;
                        }
                    } while(case1);
                    system("cls");
                    temp6 =0;
                    break;
                case 2:
                    cout << "Nhap ma tac gia: ";
                    cin >> Matacgia;
                    removeSpaces(Mabaibao);
                    L.List_AddAuthor(Matacgia);
                    system("pause");
                    system("cls");
                    temp6 =0;
                    break;
                case 3:
                    cout << "Nhap ma tap chi: ";
                    cin >> Matapchi;
                    removeSpaces(Mabaibao);
                    L.List_AddJournal(Matapchi);
                    system("pause");
                    system("cls");
                    temp6 =0;
                    break;
                case 4:
                    cout << "Nhap ma NXB: ";
                    cin >> MaNXB;
                    removeSpaces(Mabaibao);
                    L.List_AddPublisher(MaNXB);
                    system("pause");
                    system("cls");
                    temp6 =0;
                    break;
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
            } while (temp6);
            break;
        case 7:
            system("cls");
            int temp7;
            do
            {
                cout<<"==== XOA ===="<<endl<<endl;
                cout<<"1.Theo ma bai bao"<<endl;
                cout<<"2.Theo vi tri bai bao"<<endl;
                cout<<"3.Theo ma tac gia"<<endl;
                cout<<"4.Theo ma tap chi"<<endl;
                cout<<"5.Theo ma NXB"<<endl;
                cout<<"0. Thoat"<<endl;
                cout<<"Vui long nhap lua chon cua ban: ";
                cin>>temp7;
                switch (temp7)
                {
                case 0:
                    temp7 =0;
                    system("cls");
                    break;
                case 1:
                    cout<<"Nhap ma bai bao can xoa: ";
                    cin>>Mabaibao;
                    removeSpaces(Mabaibao);
                    L.List_DeleteArticleByArtID(Mabaibao);
                    //L.List_UpdateNumArtOfAllList();
                    system("pause");
                    system("cls");
                    temp7 =0;
                    break;
                case 2:
                    cout << "Nhap vi tri bai bao can xoa: ";
                    cin >> pos;
                    L.List_DeleteArticleByPos(pos-1);
                    system("pause");
                    system("cls");
                    temp7 =0;
                    break;
                case 3:
                    cout <<"Nhap ma tac gia can xoa: ";
                    cin >>Matacgia;
                    removeSpaces(Mabaibao);
                    L.List_DeleteAuthorByAuthID(Matacgia);
                    system("pause");
                    system("cls");
                    temp7 =0;
                    break;
                case 4:
                    cout <<"Nhap ma tap chi can xoa: ";
                    cin >>Matapchi;
                    removeSpaces(Mabaibao);
                    L.List_DeleteJournalByJouID(Matacgia);
                    system("pause");
                    system("cls");
                    temp7 =0;
                    break;
                case 5:
                    cout <<"Nhap ma NXB can xoa: ";
                    cin >>MaNXB;
                    removeSpaces(Mabaibao);
                    L.List_DeletePublisherByPubID(Matacgia);
                    system("pause");
                    system("cls");
                    temp7 =0;
                    break;
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    system("pause");
                    system("cls");
                    break;
                }
            } while (temp7);
            break;

        default:
            cout<<"Ban da nhap sai!!!"<<endl;
            system("pause");
            system("cls");
            break;
        }
    } while (temp);
    
}

/////////////////////////////////////////////////////////////MAIN//////////////////////////////////////////////////////////////
int main() 
{

    List L;
    // Lay so luong
    ifstream inFileNum("../Data/InitialNum.txt");
    L.get_initialNum(inFileNum);
    // Get data Publisher
    ifstream inFilePub("../Data/Publisher.txt");
    if (inFilePub.fail()) cout << "Failed to open file";
    L.List_getPublisher(inFilePub);

    // Get data Article
    ifstream inFileArt("../Data/Article.txt");
    if (inFileArt.fail()) cout << "Failed to open file";
    L.List_getArticle(inFileArt);

    // Get data Journal
    ifstream inFileJou("../Data/Journal.txt");
    if (inFileJou.fail()) cout << "Failed to open file";
    L.List_getJournal(inFileJou);

    //Get data Author
    ifstream inFileAuth("../Data/Author.txt");
    if (inFileAuth.fail()) cout << "Failed to open file";
    L.List_getAuthor(inFileAuth);

    L.List_UpdateNumArtOfAllList();
    MENU(L);
   
    inFileArt.close();
    inFileJou.close();
    inFileAuth.close();
    inFilePub.close();

    return 0;
}
////////// - add article, author, publisher, journal xong
////////// - edit article, author, publisher, journal xong
///////// - delete xong
//////// - overwrite số lượng xong
// - check INPUT
// 
/////////  - em Thịnh viết hàm transfrom