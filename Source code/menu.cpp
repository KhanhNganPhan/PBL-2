#include <iostream> 
#include "menu.h"
using namespace std;

void menu::info()
{
    int i;
    cout << endl;
    cout << "        " <<char(201);
    for (i = 0; i <= 85; i++)
        cout << char(205);
    cout << char(187) << endl;
    cout << "        " << char(186) << "                                                                                      " <<  char(186) << endl;
    cout << "        " << char(186) << "                              BPL 2: DO AN CO SO                                      " <<  char(186) << endl;
    cout << "        " << char(186) << "                 DE TAI: XAY DUNG CHUONG TRINH QUAN LY BAI BAO KHOA HOC               " <<  char(186) << endl;
    cout << "        " << char(186) << "                                                                                      " <<  char(186) << endl;
    cout << "        " << char(186) << "       Sinh vien thuc hien:                       Giao vien huong dan:                " <<  char(186) << endl;
    cout << "        " << char(186) << "       - Le Van Thinh                             - Do Thi Tuyet Hoa                  " <<  char(186) << endl;
    cout << "        " << char(186) << "       - Phan Khanh Ngan                                                              " <<  char(186) << endl;
    cout << "        " << char(186) << "                                                                                      " <<  char(186) << endl;
    cout << "        " << char(200);
    for (i = 0; i <= 85; i++)
        cout << char(205);
    cout << char(188) << endl;
}

void menu::mainMenu()
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |                      MENU                        |" << endl;
    cout << "                        |      1. Hien thi thong tin                       |" << endl;
    cout << "                        |      2. Chinh sua thong tin                      |" << endl;
    cout << "                        |      3. Them thong tin                           |" << endl;
    cout << "                        |      4. Xoa thong tin                            |" << endl;
    cout << "                        |      5. Thong ke so luong bai bao                |" << endl;
    cout << "                        |      6. Tim kiem bai bao                         |" << endl;
    cout << "                        |      7. Sap xep bai bao                          |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout<<"Vui long nhap lua chon cua ban: ";
}

void menu::subMenu_Display() 
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |                HIEN THI THONG TIN                |" << endl;
    cout << "                        |      1. Bai bao                                  |" << endl;
    cout << "                        |      2. Tac gia                                  |" << endl;
    cout << "                        |      3. Tap chi                                  |" << endl;
    cout << "                        |      4. Nha xuat ban                             |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout<<"Vui long nhap lua chon cua ban: ";
}

void menu::subMenu_NumOfArticle()
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |            THONG KE SO LUONG BAI BAO             |" << endl;
    cout << "                        |      1. Theo tac gia                             |" << endl;
    cout << "                        |      2. Theo tap chi                             |" << endl;
    cout << "                        |      3. Theo nha xuat ban                        |" << endl;
    cout << "                        |      4. Theo nam xuat ban                        |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout<<"Vui long nhap lua chon cua ban: ";
}

void menu::subMenu_FindArticle()
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |                TIM KIEM BAI BAO                  |" << endl;
    cout << "                        |      1. Theo ten bai bao                         |" << endl;
    cout << "                        |      2. Theo ma bai bao                          |" << endl;
    cout << "                        |      3. Theo ten tac gia                         |" << endl;
    cout << "                        |      4. Theo ma tac gia                          |" << endl;
    cout << "                        |      5. Theo ma tap chi                          |" << endl;
    cout << "                        |      6. Theo ma NXB                              |" << endl;
    cout << "                        |      7. Theo nam xuat ban                        |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout<<"Vui long nhap lua chon cua ban: ";
}

void menu::subMenu_SortArticle()
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |                SAP XEP BAI BAO                   |" << endl;
    cout << "                        |      1. Theo ten tac gia                         |" << endl;
    cout << "                        |      2. Theo ten bai bao                         |" << endl;
    cout << "                        |      3. Theo nam                                 |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout<<"Vui long nhap lua chon cua ban: ";
}

void menu::subMenu_Edit()
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |              CHINH SUA THONG TIN                 |" << endl;
    cout << "                        |      1. Bai bao                                  |" << endl;
    cout << "                        |      2. Tac gia                                  |" << endl;
    cout << "                        |      3. Tap chi                                  |" << endl;
    cout << "                        |      4. Nha xuat ban                             |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout<<"Vui long nhap lua chon cua ban: ";
}

void menu::subMenu_Add()
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |                 THEM THONG TIN                   |" << endl;
    cout << "                        |      1. Bai bao                                  |" << endl;
    cout << "                        |      2. Tac gia                                  |" << endl;
    cout << "                        |      3. Tap chi                                  |" << endl;
    cout << "                        |      4. Nha xuat ban                             |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout<<"Vui long nhap lua chon cua ban: ";
}

void menu::subMenu2_AddArticle()
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |                  THEM BAI BAO                    |" << endl;
    cout << "                        |      1. Mac dinh                                 |" << endl;
    cout << "                        |      2. Vao vi tri bat ki                        |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout<<"Vui long nhap lua chon cua ban: ";
}

void menu::subMenu_Delete()
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |                 XOA THONG TIN                    |" << endl;
    cout << "                        |      1. Bai bao theo ma                          |" << endl;
    cout << "                        |      2. Bai bao theo vi tri                      |" << endl;
    cout << "                        |      3. Tac gia theo ma                          |" << endl;
    cout << "                        |      4. Tap chi theo ma                          |" << endl;
    cout << "                        |      5. NXB theo ma                              |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout<<"Vui long nhap lua chon cua ban: ";
}

void menu::subMenu2_editArticle(string artid)
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |           CHINH SUA BAI BAO: "<< artid <<"                |" << endl;
    cout << "                        |      1. Ten bai bao                              |" << endl;
    cout << "                        |      2. Tac gia                                  |" << endl;
    cout << "                        |      3. Tap chi                                  |" << endl;
    cout << "                        |      4. Nam cong bo                              |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
}

void menu::subMenu2_editJournal(string jouid)
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |          CHINH SUA TAP CHI: "<< jouid <<"               |" << endl;
    cout << "                        |      1. Ten tap chi                              |" << endl;
    cout << "                        |      2. Tong bien tap                            |" << endl;
    cout << "                        |      3. Nha xuat ban                             |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
}

void menu::subMenu2_editAuthor(string authid)
{
    cout << endl;
    cout << "                         -------------------------------------------------- " << endl;
    cout << "                        |            CHINH SUA TAC GIA: "<< authid <<"                |" << endl;
    cout << "                        |      1. Ten tac gia                              |" << endl;
    cout << "                        |      2. Noi cong tac                             |" << endl;
    cout << "                        |      3. Linh vuc lam viec                        |" << endl;
    cout << "                        |      4. Trinh do                                 |" << endl;
    cout << "                        |      0. Thoat                                    |" << endl;
    cout << "                         -------------------------------------------------- " << endl;
}