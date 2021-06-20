#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    string str = "Hello World";
    string str1 = "Replace";

    cout<<str<<endl;
    //cin>>str;
    cout<<str.back()<<endl;
    cout<<str.compare("Hello World")<<endl;
    str.append(" !");
    cout<<str.find('l')<<endl;
    cout<<str.find_first_not_of("Hello")<<endl;
    cout<<str.find_last_of("ld")<<endl;
    str.replace(0, str1.length(), str1);
    cout<<str<<endl;
    string c = str.substr(3,4);
    cout<<c;
    c.clear();
    str.clear();
    cout<<str<<endl;
    return 0;
}