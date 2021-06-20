/*
stack'de statik degiskenler duruyor.
yer ayirma kod compile edilirken yapiliyor ve kod calismasi bitene kadar degistirilemiyor
deger atanmamis dizilere 0 degeri veriliyor

heap'de dinamik degiskenler duruyor
buraya programci erisebiliyor ve degisiklikler yapabiliyor
burdaki degiskenlerin adreslerini pointerlar tutuyor ve bunlar stack'de tutuluyor
*/

#include <iostream>

using namespace std;

int* daralt(int* old, int size, int eksi)
{
    int* neww = new int[size-eksi];
    int i, takip;
    for ( i = 0; i < size-eksi; i++)
    {
        neww[i] = old[i];
        takip = old[i];
    }
    delete [] old;
    return neww;
}

int* genislet(int* old, int size, int arti)
{
    int* neww = new int[size+arti];
    int i;
    for ( i = 0; i < size; i++)
    {
        neww[i] = old[i];
    }
    delete [] old;
    return neww;
}

void yazdir(int* dizi, int size)
{
    int i=0;
    for ( i = 0; i < size; i++)
    {
        cout << dizi[i] << " ";
    }
    cout << endl;
}

void heap_ornegi()
{
    // heap ornegi
    int *p = new int[5];
    int i;
    for ( i = 0; i < 5; i++)
    {
        p[i] = i*i;
    }
    cout<<p[4]<<endl;

    int *y = new int[10];
    for ( i = 0; i < 5; i++)
    {
        y[i] = p[i];
    }
    delete [] p;
    for ( i = 5; i < 10; i++)
    {
        y[i] = i*i;
    }
    for ( i = 0; i < 10; i++)
    {
        cout<<y[i]<<" ";
    }
    cout<<endl;
    for ( i = 0; i < 5; i++)
    {
        cout<<p[i]<<" ";
    }
    p = y;
    cout<<endl;
    for ( i = 0; i < 10; i++)
    {
        cout<<p[i]<<" ";
    }
    cout << endl;
}

int* create_heap_array(int size)
{
    int* a = new int[size];
    for (int i; i<size; i++) {
    cin>>a[i];
    }
    return a;
}

int** create_heap_matris(int array_num)
{
    int size;
    int** matris = new int*[array_num];
    for (int i ; i<array_num; i++) {
    cin>>size;
    matris[i] = create_heap_array(size);
    }
    return matris;
}

int main()
{
    // heap_ornegi();
    int* dinamik_dizi = new int[1];
    int i = 0;
    dinamik_dizi[i] = 0;
    while (dinamik_dizi[i] != -1)
    {
        i++;
        dinamik_dizi = genislet(dinamik_dizi, i, 1);
        cin>>dinamik_dizi[i];
    }
    i++;
    while (i != 0)
    {
        yazdir(dinamik_dizi, i);
        dinamik_dizi = daralt(dinamik_dizi, i, 1);
        i--;
    }
    return 0;
}
