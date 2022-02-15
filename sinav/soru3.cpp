#include <iostream>

using namespace std;
float denklem(float x);
float denklemin_turevi(float x);

int main()
{
    float x;
    cout << "f(x) = 2 + 5*x + 3*x*x + 7*x*x*x\n";
    cout << "Turevine bakilacak x degerini giriniz : ";
    cin >> x;
    cout << "f(" << x << ") = " << denklem(x) << " ve f'(" << x << ") = " << denklemin_turevi(x) << endl;

    return 0;
}

float denklem(float x)
{
    return 2 + 5*x + 3*x*x + 7*x*x*x;
}

float denklemin_turevi(float x)
{
    float h = 0.000001;
    return ( denklem(x) - denklem(x-h) ) / (h);
}