#include <iostream>
#include<fstream> 
#include<iomanip>

using namespace std;

int main()
{
    int i = 0;
    double inc, feet;
    ofstream myfile("UnConT.txt");
    if ( ! myfile.is_open())
        cout<<"\ndosya acilamadi\n";
    myfile << "Lenght in meter\t\t" << "Lenght in inch\t\t" << "in feet\n";
    myfile << "-----------------------------------------------------------------\n";
    myfile << setfill('0');
    for ( i = 1; i <= 100; i++)
    {
        inc = i*2.54e-2;
        feet = i*3.048e-1;
        myfile << setw(3) << i << "\t\t\t\t\t";
        myfile << setw(7) << setprecision(3) << inc << "\t\t\t\t";
        myfile << setw(7) << setprecision(3) << feet << "\n";
    }
    myfile.close();
    cout << "\nBasari ile dosyaya yazilmistir.";

    return 0;
}