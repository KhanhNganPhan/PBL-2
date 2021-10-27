#include <iostream>
#include <string.h>
#include <fstream>
#include "PBL-2.cpp"

using namespace std;

int main() {
    List L;
    ifstream inFile("../Data/Publisher.txt");
    if (inFile.fail()) cout << "Failed to open file";
    ifstream inFileNum("../Data/NumOfData.txt");
    L.get_initialNum(inFileNum);
    L.List_getPublisher(inFile);
    cout << L;
    return 0;
}