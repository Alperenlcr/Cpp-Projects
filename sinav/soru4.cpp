#include <iostream>

using namespace std;

int main()
{
    int matris[9][9];
    int i, j;
    for ( i = 0; i < 9; i++)
    {
        for ( j = 0; j < 9; j++)
        {
            if (i <= j)
                matris[i][j] = 1;
            else
                matris[i][j] = 0;
        }
    }
    cout << "\n";
    for ( i = 0; i < 9; i++)
    {
        for ( j = 0; j < 9; j++)
            cout << matris[i][j] << " ";
        cout << "\n";
    }

    return 0;
}