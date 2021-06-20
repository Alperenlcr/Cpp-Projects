#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    // int , 32-bit , -2^31 . . . -2^31-1 , -2x10^9 . . . 2x10^9
// long long , 64-bit , -2^64 . . . -2^64-1 , -9x10^18 . . . 9x10^18
long long x = 123456789123456789;
cout<<x<<endl;
// __int128_t , 128-bit , -2^128 . . . -2^128-1 , -9x10^38 . . . 9x10^38
// __int128_t y = 123456789123456789123456789123456789;
// cout<<y<<endl;

/*
( a + b ) mod m = ( a mod m + b mod m ) mod m
( a − b ) mod m = ( a mod m − b mod m ) mod m
( a · b ) mod m = ( a mod m · b mod m ) mod m
*/

// 64-bit double
// 80-bit long double

// It is risky to compare floating point numbers with the == operator, because it
// is possible that the values should be equal but they are not because of precision errors.
    double z = 0.3*3+0.1;
    printf("%.20f\n", z);

// Using the command typedef it is possible to give a shorter name to a datatype.
    typedef long long ll;
    ll a = 123456789123456789;
    cout<<a<<endl;
    return 0;

// Math in pdf page 10
// There is also a closed-form formula for calculating Fibonacci numbers,
// which is sometimes called Binet’s formula

/*      Estimating efficiency
input size      required time complexity
n ≤ 10          O( n !)
n ≤ 20          O( 2*n )
n ≤ 500         O( n^3 )
n ≤ 5000        O( n^2 )
n ≤ 10 6        O( n log n ) or O( n )
n is large      O(1) or O(log n )
*/
}