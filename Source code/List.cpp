#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "List.h"

using namespace std;
#define getenter fflush(stdin);

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

    cout << endl << left << setw (15) <<"Ma NXB"<< "Ten NXB" << endl;
    cout << "--------------------------------------------------" << endl;
    for(int i =0;i < Publisher_count;i++)
    {
        cout<< Pub[i];
    }
}

void List::List_displayJournal()
{
    cout << endl << left << setw(15) << "Ma tap chi" << left << setw(50) << "Ten tap chi" << left << setw(30) << "Ten tong bien tap" << left << setw(10) << "Ma NXB"<<endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    for(int i=0;i<Journal_count;i++)
    {
        cout<<Jou[i];
    }
}

void List::List_displayAuthor()
{
    cout << endl << left << setw(15) << "Ma TG"  << left << setw(20) << "Ho dem" << left << setw(15)<< "Ten" << left << setw(15) << "Noi cong tac";
    cout  << left << setw(30) << "Linh vuc nghien cuu" << left << setw(10) << "Trinh do" << endl ;
    cout << "----------------------------------------------------------------------------------------------------------" << endl;
    for(int i=0;i<Author_count;i++)
    {
        cout<<Auth[i];
    }
}

/////////////////////////////////////////////////////////////DISPLAY ARTICLE WITH FULL AUTHOR NAME///////////////////////////////////////////////

void List::List_displayAll()
{
    cout<< endl << left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45)<<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl ;
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
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
void List :: List_editArticle(menu m) 
{
    int i = 0; //Biến lấy phần tử bài báo trong list
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
        m.subMenu2_editArticle(Art[i].Article_id);
        editArticle_General(m,Art[i]);
    }
}


/////////////////////////////EDIT ARTICLE GENERAL//////////////////////////////
void List :: editArticle_General(menu m, Article &Art) 
{
    int type=0;
    while (type==0)
    {
        cout << "Nhap lua chon: ";
        cin >> type;
        switch (type)
        {
            case 1: 
                Art.editArticle_Name();
                editArticle_General(m,Art);
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
                editArticle_General(m,Art);
                break;
            }
            case 3: 
            { //bỏ trong dấu ngoặc nhọn để có thể khai báo biến tempJournalID trong case
                string tempJournalID = Art.Journal_id;
                Art.editArticle_Journal();
                if (List_isNewJournal(Art.Journal_id))
                {
                    cout << "Tap chi chua ton tai!" << endl;
                    cout << "Them tap chi moi? (c/k) ";
                    char type;
                    cin >> type;
                    type = toupper(type);
                    if (type == 'C') List_AddJournal(Art.Journal_id);
                    else Art.Journal_id = tempJournalID;
                }
                editArticle_General(m,Art);
                break;
            }
            case 4:
                Art.editArticle_Time();
                editArticle_General(m,Art);
                break;
            case 0:
                type=1;
                break;
            default:
                type = 0;
        }
    }
}

////////////////MENU EDIT JOURNAL PROCESS/////////////////
void List :: List_editJournal(menu m) 
{
    int i = 0; //Biến lấy phần tử bài báo trong list
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
        m.subMenu2_editJournal(Jou[i].J_id);
        editJournal_General(m, Jou[i]);
    }
}


//////////////////////////////EDIT JOURNAL GENERAL///////////////////////////////
void List :: editJournal_General(menu m, Journal &Jou) 
{
    int type=0;
    while (type==0)
    {
        cout << "Nhap lua chon: ";
        cin >> type;
        switch (type)
        {
            case 1: 
                Jou.editJournal_Name();
                editJournal_General(m, Jou);
                break;
            case 2:
                Jou.editJournal_Editor();
                editJournal_General(m, Jou);
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
                editJournal_General(m, Jou);
                break;
            }
            case 0:
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
    int i = 0; //Biến lấy phần tử bài báo trong list
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
        cout << endl << "=== CHINH SUA NHA XUAT BAN : " << Pub[i].Publisher_id << " ===" << endl;
        Pub[i].editPublisher_Name();
    }
}
///////////////////////////MENU EDIT AUTHOR PROCESS////////////////////////////
void List :: List_editAuthor(menu m) 
{
    int i = 0; //Biến lấy phần tử tác giả trong list
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
        m.subMenu2_editAuthor(Auth[i].author_id);
        editAuthor_General(m, Auth[i]);
    }
}

////////////////////////////EDIT AUTHOR GENERAL/////////////////////////////
void List :: editAuthor_General(menu m, Author &Auth) 
{
    int type=0;
    while (type==0)
    {
        cout << "Nhap lua chon: ";
        cin >> type;
        switch (type)
        {
            case 1: 
                Auth.editAuthor_Name();
                editAuthor_General(m, Auth);
                break;
            case 2:
                Auth.editAuthor_Work();
                editAuthor_General(m, Auth);
                break;
            case 3: 
                Auth.editAuthor_Field();
                editAuthor_General(m, Auth);
                break;
            case 4:
                Auth.editAuthor_Degree();
                editAuthor_General(m, Auth);
                break;
            case 0:
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
        this->List_overwriteNewAuthor();                       //Update vào file dữ liệu tác giả
        this->List_overwriteInitialNumber();                   //Update file số lượng
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
        this->List_overwriteNewPublisher();                       //Update vào file dữ liệu NXB
        this->List_overwriteInitialNumber();                        //Update vào file số lượng
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
        this->List_overwriteNewJournal();                      //Update vào file dữ liệu tạp chí
        this->List_overwriteInitialNumber();                   //Update file số lượng
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
        this->List_overwriteNewArticle();                      //Update vào file dữ liệu bài báo
        this->List_overwriteInitialNumber();                   //Update file số lượng
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
        this->List_overwriteNewArticle();                      //Update vào file dữ liệu bài báo
        this->List_overwriteInitialNumber();                   //Update file số lượng
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
    cout << "-----------------------------------" << endl;
    for(int i=0;i< Author_count;i++)
    {
        cout<< left<< setw(25)<<Auth[i].getName()<< left<< setw(10)<<Auth[i].Article_count<<endl;
    }
}


void List::List_displayNumofArtPerJour()
{
    cout<< left<< setw(50)<<"Tap chi"<< left<< setw(10)<<"So bai bao"<<endl;
    cout << "------------------------------------------------------------" << endl;
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
    cout << "---------------------------------------------------" << endl;
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
        this->List_overwriteNewArticle();                      //Update vào file dữ liệu bài báo
        this->List_overwriteInitialNumber();                   //Update file số lượng
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
    this->List_overwriteNewArticle();                      //Update vào file dữ liệu bài báo
    this->List_overwriteInitialNumber();                   //Update file số lượng  
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
            this->List_overwriteNewAuthor();                      //Update vào file dữ liệu tác giả
            this->List_overwriteInitialNumber();                   //Update file số lượng
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
            this->List_overwriteNewJournal();                      //Update vào file dữ liệu TẠP CHÍ
            this->List_overwriteInitialNumber();                   //Update file số lượng
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
            this->List_overwriteNewPublisher();                      //Update vào file dữ liệu NXB
            this->List_overwriteInitialNumber();                   //Update file số lượng
        }
        
    }
}


///////////////////////////////////////////////////////////////OVERWRITE///////////////////////////////////////////////////////////////////

/////////////////////////////Ghi mới vào file Author.txt///////////////
void List::List_overwriteNewAuthor() 
{
    ofstream outFile("../Data/Author.txt", ofstream::trunc);
    outFile << "Ma TG|Ho dem|Ten|Noi cong tac|Linh vuc nghien cuu|Trinh do\n";
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
    outFile << "Ma bao|Ten cong bo|Tac gia|Tap chi|Thoi gian\n";
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
    outFile << "Ma tap chi|Ten tap chi|Ten tong bien tap|Ma NXB\n";
    for (int i=0; i< Journal_count ; i++)
    {
        outFile <<  Jou[i].J_id << "|";
        outFile <<  Jou[i].J_name << "|";
        outFile <<  Jou[i].J_editor << "|";
        outFile <<  Jou[i].Publisher_id << ",\n";
    }
    outFile.close();
}
////////////////////////////////Ghi mới vào file Publiser.txt///////
void List:: List_overwriteNewPublisher()
{
    ofstream outFile("../Data/Publisher.txt", ofstream::trunc);
    outFile << "Ma NXB|Ten NXB\n";
    for (int i=0; i< Publisher_count ; i++)
    {
        outFile <<  Pub[i].Publisher_id << "|";
        outFile <<  Pub[i].Publisher_name << ",\n";
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
    for(int i=0;i <Article_count -1 ;i++)
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
    for(int i =0;i<Article_count-1;i++)
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

void List::List_SortArtByNameArticle(bool (*SS)(Article, Article))
{
    for(int i =0;i<Article_count-1;i++)
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
bool List::List_FindArtByName(string name)
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
                cout <<endl<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                flag=true;;
            }
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25);
            cout << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl; 
        }
    }
    return flag;
}
bool List::List_FindArtByAuthorName()
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
                cout <<endl<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout  <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                flag=true;
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
                cout <<endl<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
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
                cout <<endl<< left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                flag=true;
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
                cout <<endl << left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout  <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                flag=true;
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
                cout  <<endl << left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                flag=true;
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
                cout <<endl << left << setw(15)<<"Ma bao"<< left << setw(65)<<"Ten cong bo"<< left << setw(25)<<"Tac gia"<< left << setw(45);
                cout <<"Tap chi"<< left << setw(10)<<"Thoi gian"<<endl;
                cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                flag=true;
            }
            cout << left << setw(15)<< Art[i].Article_id << left << setw(65) << Art[i].Article_name << left << setw(25) << this->List_getAuthorNamebyID(Art[i].Author_id);
            cout << left << setw(45) << this->List_getJournalNamebyID(Art[i].Journal_id) << left << setw(10)<< Art[i].Publish_time << endl;
        }
    }
    return flag;
}