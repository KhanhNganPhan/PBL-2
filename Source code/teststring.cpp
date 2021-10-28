#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int x(){
    return 7;
}
int main() {

    string a="au" + to_string(x());
    cout << a;
return 0;
}