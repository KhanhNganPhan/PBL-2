#pragma once
#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string.h>
using namespace std;
class menu {
    public:
    void info();
    void mainMenu();
    void subMenu_Display();
    void subMenu_NumOfArticle();
    void subMenu_FindArticle();
    void subMenu_SortArticle();
    void subMenu_Edit();
    void subMenu_Add();
    void subMenu_Delete();
    void subMenu2_AddArticle();
    void subMenu2_editArticle(string);
    void subMenu2_editJournal(string);
    void subMenu2_editAuthor(string);
};
#endif