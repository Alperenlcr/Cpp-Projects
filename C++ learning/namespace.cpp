#include <iostream>

using namespace std;
// std icindeki cin, cout gibi fonksiyonlari kullanirken
// her seferinde std::cout<<"output" gibisinden bir kullanim yapmamamizi sagliyor.

// namespace ler kendi degiskenlerini sakliyor class veya struct mantigi ile benziyor

// global degisken mantigi std namespace e ait degiken
unsigned int value = 9;
int fonk()
{
    return 0;
}

namespace A
{
    int value = 10;

    int fonk()
    {
        return 1;
    }
}

namespace B
{
    float value = 11.1;

    int fonk()
    {
        return 2;
    }
}

namespace C
{
    double value = 12.12;

    int fonk()
    {
        return 3;
    }
}

int main()
{
    cout<<"namespace std : "<<value<<endl;
    cout<<"namespace A : "<<A::value<<endl;
    cout<<"namespace B : "<<B::value<<endl;
    cout<<"namespace C : "<<C::value<<endl<<endl;

    cout<<"namespace std : "<<fonk()<<endl;
    cout<<"namespace A : "<<A::fonk()<<endl;
    cout<<"namespace B : "<<B::fonk()<<endl;
    cout<<"namespace C : "<<C::fonk()<<endl;



    return 0;
}