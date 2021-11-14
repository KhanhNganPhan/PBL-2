// C++ program to implement custom trim() function
#include <iostream>
using namespace std;
 
// Function to in-place trim all spaces in the
// string such that all words should contain only
// a single space between them.
void removeSpaces(string &str)
{
    string nstr;
    int i=0;
    while (i<str.length())
    {
        if (str[i]==' ') i++;
        else break;
    }
    //loop through the characters of the input string
    for(; i<str.length();  ){
        //check if character is white space
        if(str[i] == ' '){

            while(str[i+1] == ' ')
                i++;
        }
        
        //concatenate the character to the new string
        nstr += str[i++];
    }
    str = nstr;
}
 
// Driver Code
int main()
{
    string str;
    getline(cin,str);
 
    removeSpaces(str);
 
    cout << "1:"<<str;
 
    return 0;
}