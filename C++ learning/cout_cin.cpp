#include <iostream>

using namespace std;

int main()
{
    int f = 10;
    cout<<"Hello World\n"<<f<<endl<<"end line"<<endl;
    cin>>f;
    cout<<f<<endl;

    char str[100];
    cin>>str;
    cout<<str<<endl;

    cout<<"sayi gir sonra yazilisini gir"<<endl;
    cin >> f >> str;
    cout << f << " yazilisi :" << str<<endl;

    int x;
    cout<<"-1 girene kadar sayi gir:\n";
    while (cin>>x && x != -1)
    {
        cout<<x<<" ";
    }

    string s;
    getline(cin, s);

    cout<<s<<endl;

/*
In some contest systems, files are used for input and output. An easy solution
for this is to write the code as usual using standard streams, but add the following
lines to the beginning of the code:
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
After this, the program reads the input from the file ”input.txt” and writes the
output to the file ”output.txt”.
*/

/*
Input and output is sometimes a bottleneck in the program. The following
lines at the beginning of the code make input and output more efficient:
ios::sync_with_stdio(0);
cin.tie(0);
*/

    return 0;
}