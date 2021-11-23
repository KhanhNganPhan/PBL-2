#include <iostream>
#include <string.h>
using namespace std;
#include "extraFunction.h"

void removeSpaces(string &str)
{
    string nstr;
    int i=0;
    while (i<str.length())
    {
        if (str[i]==' ') i++;
        else break;
    }
    for(; i<str.length();  ){
        if(str[i] == ' '){
            while(str[i+1] == ' ')
                i++;
        }
        nstr += str[i++];
    }
    str = nstr;
}

bool ArtNameAscending(Article x, Article y)
{
    if(x.getArticleName().compare(y.getArticleName() ) == 1) return true;
    else return false;
}
bool ArtNameDescending(Article x, Article y)
{
    if(x.getArticleName().compare(y.getArticleName() ) != 1) return true;
    else return false;
}
bool YearAscending(Article x, Article y)
{
    if(x.getPublish_Time() > y.getPublish_Time()) return true;
    else return false;
}
bool YearDescending(Article x, Article y)
{
    if(x.getPublish_Time() < y.getPublish_Time()) return true;
    else return false;
}