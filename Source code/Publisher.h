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
        //static int publisher_count; // Đếm số NXB
    public:

    void readf_Publisher(ifstream &);
    friend ostream &operator << (ostream &, const Publisher &);

};


#endif