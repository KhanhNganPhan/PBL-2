#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "List.h"
#include "extraFunction.h"
using namespace std;
#define getenter fflush(stdin);
menu m;

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
        m.mainMenu();
        cin>>temp;
        switch (temp)
        {
        case 0:
            temp =0;
            cout<<"Chuc ban mot ngay moi tot lanh!"<<endl;
            break;
        case 1:
            int temp1;
            //system("cls");
            do
            {
                m.subMenu_Display();
                cin>>temp1;
                switch (temp1)
                    {
                    case 0:
                        temp1 =0;
                        //system("cls");
                        break;
                    case 1:
                        L.List_displayAll();
                        cout << endl;
                        system("pause");
                        //system("cls");
                        temp1 =0;
                        break;
                    case 2:
                        L.List_displayAuthor();
                        cout << endl;
                        system("pause");
                        //system("cls");
                        temp1 =0;
                        break;
                    case 3:
                        L.List_displayJournal();
                        cout << endl;
                        system("pause");
                        //system("cls");
                        temp1 =0;
                        break;
                    case 4:
                        L.List_displayPublisher();
                        cout << endl;
                        system("pause");
                        //system("cls");
                        temp1 =0;
                        break;
                    default:
                        cout<<"Ban da nhap sai!!!"<<endl;
                        cout << endl;
                        system("pause");
                        //system("cls");
                        break;
                    }
            } 
            while(temp1);
            break;
        case 2: 
            //system("cls");
            int temp2;
            do
            {
                m.subMenu_Edit();
                cin>>temp2;
                switch (temp2)
                {
                case 0:
                    temp2 =0; 
                    //system("cls");
                    break;
                case 1:
                    L.List_editArticle(m);
                    L.List_overwriteNewArticle();
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp2 =0;
                    break;
                case 2:
                    L.List_editAuthor(m);
                    L.List_overwriteNewAuthor();
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp2 =0;
                    break;
                case 3:
                    L.List_editJournal(m);
                    L.List_overwriteNewJournal();
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp2 =0;
                    break;
                case 4:
                    L.List_editPublisher();
                    L.List_overwriteNewPublisher();
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp2 =0;
                    break;
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    break;
                }
            } while (temp2);
            break;
        case 3:
            //system("cls");
            int temp3;
            do
            {
                m.subMenu_Add();
                cin>>temp3;
                switch (temp3)
                {
                case 0:
                    temp3 =0;
                    //system("cls");
                    break;
                case 1:
                    //system("cls");
                    int case1;
                    do 
                    {   
                        m.subMenu2_AddArticle();
                        cin >> case1;
                        switch (case1)
                        {
                            case 1:
                                cout << "Nhap ma bai bao: ";
                                cin >> Mabaibao;
                                removeSpaces(Mabaibao);
                                L.List_AddArticle(Mabaibao);
                                L.List_UpdateNumArtOfAllList();
                                cout << endl;
                                system("pause");
                                //system("cls");
                                case1 = 0;
                                break;
                            case 2:
                                cout << "Nhap ma bai bao: ";
                                cin >> Mabaibao;
                                removeSpaces(Mabaibao);
                                L.List_InsertArticle(Mabaibao);
                                L.List_UpdateNumArtOfAllList();
                                cout << endl;
                                system("pause");
                                //system("cls");
                                case1 = 0;
                                break;
                            case 0:
                                case1 = 0;
                                cout << endl;
                                system("pause");
                                //system("cls");
                                break;
                        }
                    } while(case1);
                    //system("cls");
                    temp3 =0;
                    break;
                case 2:
                    cout << "Nhap ma tac gia: ";
                    cin >> Matacgia;
                    removeSpaces(Matacgia);
                    L.List_AddAuthor(Matacgia);
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp3 =0;
                    break;
                case 3:
                    cout << "Nhap ma tap chi: ";
                    cin >> Matapchi;
                    removeSpaces(Matapchi);
                    L.List_AddJournal(Matapchi);
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp3 =0;
                    break;
                case 4:
                    cout << "Nhap ma NXB: ";
                    cin >> MaNXB;
                    removeSpaces(MaNXB);
                    L.List_AddPublisher(MaNXB);
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp3 =0;
                    break;
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    break;
                }
            } while (temp3);
            break;
        case 4:
            //system("cls");
            int temp4;
            do
            {
                m.subMenu_Delete();
                cin>>temp4;
                switch (temp4)
                {
                case 0:
                    temp4 =0;
                    //system("cls");
                    break;
                case 1:
                    cout<<"Nhap ma bai bao can xoa: ";
                    cin>>Mabaibao;
                    removeSpaces(Mabaibao);
                    L.List_DeleteArticleByArtID(Mabaibao);
                    L.List_UpdateNumArtOfAllList();
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp4 =0;
                    break;
                case 2:
                    cout << "Nhap vi tri bai bao can xoa: ";
                    cin >> pos;
                    L.List_DeleteArticleByPos(pos-1);
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp4 =0;
                    break;
                case 3:
                    cout <<"Nhap ma tac gia can xoa: ";
                    cin >>Matacgia;
                    removeSpaces(Matacgia);
                    L.List_DeleteAuthorByAuthID(Matacgia);
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp4 =0;
                    break;
                case 4:
                    cout <<"Nhap ma tap chi can xoa: ";
                    cin >>Matapchi;
                    removeSpaces(Matapchi);
                    L.List_DeleteJournalByJouID(Matapchi);
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp4 =0;
                    break;
                case 5:
                    cout <<"Nhap ma NXB can xoa: ";
                    cin >>MaNXB;
                    removeSpaces(MaNXB);
                    L.List_DeletePublisherByPubID(MaNXB);
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp4 =0;
                    break;
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    break;
                }
            } while (temp4);
            break;
        case 5:
            int temp5;
            //system("cls");
            do
            {
                m.subMenu_NumOfArticle();
                cin>>temp5;
                switch (temp5)
                {
                case 0:
                    temp5 = 0;
                    //system("cls");
                    break;
                case 1:
                    L.List_displayNumofArtPerAuth();
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp5 = 0;
                    break;
                case 2:
                    L.List_displayNumofArtPerJour();
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp5 = 0;
                    break;
                case 3:
                    L.List_displayNumofArtPerPubl();
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp5 = 0;
                    break;
                case 4:
                    L.List_displayNumofArtPerYear();
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp5 = 0;
                    break;
                
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    break;
                }
            }
            while(temp5);
            break;   
        case 6:
            //system("cls");
            int temp6;
            do
            {
                m.subMenu_FindArticle();
                cin>>temp6;
                switch (temp6)
                {
                case 0:
                    temp6 =0;
                    //system("cls");
                    break;
                case 1:
                    cout<<"Nhap ten bai bao can tim kiem: ";
                    getenter;
                    getline(cin,Tenbaibao);
                    removeSpaces(Tenbaibao);
                    if(L.List_FindArtByName(Tenbaibao)==false) cout << "Khong tim thay bai bao!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp6 =0;
                    break;
                case 2:
                    if(L.List_FindArtByArtID()==false) cout << "Khong tim thay bai bao!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp6 =0;
                    break;
                case 3:
                    if(L.List_FindArtByAuthorName()==false) cout << "Khong tim thay bai bao!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp6 =0;
                    break;
                case 4:
                    if(L.List_FindArtByAuthID()==false) cout << "Khong tim thay bai bao!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp6 =0;
                    break;
                case 5:
                    if(L.List_FindArtByJourID()==false) cout << "Khong tim thay bai bao!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp6 =0;
                    break;
                case 6:
                    if(L.List_FindArtByPublID()==false) cout << "Khong tim thay bai bao!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp6 =0;
                    break;
                case 7:
                    if(L.List_FindArtByYear()==false) cout << "Khong tim thay bai bao!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp6 =0;
                    break;
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    //system("cls");
                    break;
                }       
            } while (temp6);
            break;
        case 7:
            //system("cls");
            int temp7;
            do
            {   
                m.subMenu_SortArticle();
                cin>>temp7;
                switch (temp7)
                {
                case 0:
                    temp7 =0;
                    //system("cls");
                    break;
                case 1:
                    L.List_SortArtByNameAuthor();
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp7 =0;
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
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp7 =0;
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
                    cout << endl;
                    system("pause");
                    //system("cls");
                    temp7 =0;
                    break;
                default:
                    cout<<"Ban da nhap sai!!!"<<endl;
                    cout << endl;
                    system("pause");
                    //system("cls");
                    break;
                }
            } 
            while (temp7);
            break;
        default:
            cout<<"Ban da nhap sai!!!"<<endl;
            cout << endl;
            system("pause");
            //system("cls");
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

    //Get number of article for author/journal/publisher list
    L.List_UpdateNumArtOfAllList();

    //PBL2 Information
    m.info();

    //Main menu
    MENU(L);
   
    //Close file, end program
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