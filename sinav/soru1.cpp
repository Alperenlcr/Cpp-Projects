#include <iostream>
#include<fstream> 

using namespace std;

int main()
{
    int matris[6][6];
    int i, j;
    for ( i = 0; i < 6; i++)
    {
        for ( j = 0; j < 6; j++)
        {
            if (i == j)
                matris[i][j] = 1;
            else
                matris[i][j] = 0;
        }
    }
    ofstream myfile("matris.txt");
    if ( ! myfile.is_open())
        cout<<"\ndosya acilamadi\n";
    for ( i = 0; i < 6; i++)
    {
        for ( j = 0; j < 6; j++)
        {
            myfile << matris[i][j];
        }
        myfile << "\n";
    }
    myfile.close();
    cout << "\nBasari ile dosyaya yazilmistir.";

    return 0;
}