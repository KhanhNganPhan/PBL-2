#ifndef PUBLISHER_H
#define PUBLISHER_H
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Publisher {
    private:
        string Publisher_id;
        string Publisher_name; //Tên nhà xuất bản
        int Article_count; //Biến đếm số bài báo của một NXB
        int Journal_count; //Biến đếm số tạp chí của một NXB


    public:

    void readf_Publisher(ifstream &);
    friend ostream &operator << (ostream &, const Publisher &);

};


#endif