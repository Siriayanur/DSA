#include<iostream>
using namespace std;


bool solve(string a,string b,string c){
    if(a.length() == 0 && b.length() == 0 && c.length() == 0){
        return  true;
    }
    
    if(!c.length())
        return false;
    
    bool ans1 = (a.length() && a[0] == c[0] &&  solve(a.substr(1), b,c.substr(1)));
    bool ans2 = b.length() && b[0] == c[0] &&  solve(a, b.substr(1),c.substr(1));
    return  ans1 || ans2;
}