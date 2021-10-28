#ifndef PUBLISHER_H
#define PUBLISHER_H
#include <iostream>
#include <string.h>
#include <fstream>
#include "List.h"

using namespace std;

class List;                     // Forward declaration class List
class Publisher {
    private:
        string Publisher_id;
        string Publisher_name; //Tên nhà xuất bản
        int Article_count =0; //Biến đếm số bài báo của một NXB
        int Journal_count =0; //Biến đếm số tạp chí của một NXB

    public:
    friend class List;
    void readf_Publisher(ifstream &);
    friend ostream &operator << (ostream &, const Publisher &);
    friend ostream &operator << (ostream &, const List &);

};


#endif