#include <iostream>
#include <string.h>
#include <fstream>
#include "Author.h"
#include "PBL-2.cpp"
#include "Article.h"
using namespace std;

int main() {
    ifstream inFile1("../Author.txt");
    if (inFile1.fail()) cout << "Failed to open file";
    Author a;
    a.readf_author(inFile1);
    cout << a;
    ifstream inFile2("../Journal.txt");
    if (inFile2.fail()) cout << "Failed to open file";
    Journal j;
    j.readf_journal(inFile2);
    cout <<  j;
    Article art;
    ifstream inFile3("../Article.txt");
    if (inFile3.fail()) cout << "Failed to open file";
    art.readf_Article(inFile3);
    cout << art;
    Publisher p;
    ifstream inFile4("../Publisher.txt");
    if (inFile4.fail()) cout << "Failed to open file";
    p.readf_Publisher(inFile4);
    cout << p;
    cout << "thinh";
    return 0;
}