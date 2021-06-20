#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct sayi
{
    int data1;
    char data2[20];
}sifir; // struct bilgileri inputa falan bagli degilse burda isimlendirerek olusturabiliriz.
// sifir bu sekilde global oluyor

typedef struct number
{
    int data1;
    char data2[20];
}num;   // number yerine num tanimlayabiliriz.

void yazdir(sayi SAYI)
{
    cout<<SAYI.data1<<" : "<<SAYI.data2<<endl;
}

void yazdir2(num NUMBER)
{
    cout<<NUMBER.data1<<" : "<<NUMBER.data2<<endl;
}

void modify_struct(num* NUMBER)
{
    NUMBER->data1 += 1000;
}

num modify_struct2(num NUMBER)
{
    NUMBER.data1 += 1000;
    return NUMBER;
}

void modify_struct_with_reference(num& NUMBER)
{
    // yapi olarak pointer ile ayni kullanim kolayligi var biraz.
    // heap'de reference kullanilamiyor pointer ile calisiliyor.
    NUMBER.data1 += 1000;
}

void struct_dizisi_yazdir(sayi* pointer, int size)
{
    for (int i = 0; i < size; i++)
        cout<<pointer[i].data1<<" : "<<pointer[i].data2<<endl;
}

sayi* struct_dizisi_genislet(sayi* pointer, int eski, int arttir)
{
    sayi* p = new sayi[eski+arttir];
    /*
    for (int i = 0; i < eski; i++)
    {
        p[i].data1 = pointer[i].data1;
        strcpy(p[i].data2, pointer[i].data2);
    }*/

    memcpy(p, pointer, sizeof(sayi)*(eski+arttir));   // eskisini silmiyor tek basina
    delete pointer;
    return p;
}

int main()
{
    cout<<endl;
    cout<<"Tek struct ile calismalar\n";
    sifir.data1 = 0;
    strcpy(sifir.data2, "sifir");

    // sayi yapisinda baska bir tane daha yapi aciyoruz memoryde
    sayi bir;
    bir.data1 = 1;
    strcpy(bir.data2, "bir");

    sayi iki;
    iki.data1 = 2;
    strcpy(iki.data2, "iki");
//********************
    num zero;
    zero.data1 = 0;
    strcpy(zero.data2, "zero");

    // sayi yapisinda baska bir tane daha yapi aciyoruz memoryde
    num one;
    one.data1 = 1;
    strcpy(one.data2, "one");

    num two;
    two.data1 = 2;
    strcpy(two.data2, "two");

    yazdir(sifir);
    yazdir(bir);
    yazdir(iki);

    cout<<endl;

    yazdir2(zero);
    yazdir2(one);
    yazdir2(two);
    modify_struct(&two);
    yazdir2(two);
    two = modify_struct2(two);
    yazdir2(two);
    // yapi olarak pointer ile ayni kullanim kolayligi var biraz.
    // heap'de reference kullanilamiyor pointer ile calisiliyor.
    modify_struct_with_reference(two);
    yazdir2(two);

    cout<<"\n--------------------------------------\n";
    cout<<"Struct dizisi ile calismalar\n";

    sayi* p = new sayi[5];  // yer aciyoruz.
    char yazi[10][10] = {"bir", "iki", "uc", "dort", "bes", "alti", "yedi", "sekiz", "dokuz", "on"};
    for (int i = 0; i < 5; i++)
    {
        p[i].data1 = i+1;
        strcpy(p[i].data2, yazi[i]);
    }
    struct_dizisi_yazdir(p, 5);

    //sayi* temp = p;
    p = struct_dizisi_genislet(p, 5, 5);
    for (int i = 5; i < 10; i++)
    {
        p[i].data1 = i+1;
        strcpy(p[i].data2, yazi[i]);
    }
    cout<<"\n";
    struct_dizisi_yazdir(p, 10);
    //struct_dizisi_yazdir(temp, 5);
    //temp->data1 = 2;
    //struct_dizisi_yazdir(temp, 5);

    return 0;
}