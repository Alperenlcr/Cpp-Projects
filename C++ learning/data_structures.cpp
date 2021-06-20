#include <bits/stdc++.h>

using namespace std;

void d_s_vector()
{
// The most popular dynamic array in C++ is the vector structure, which can be used almost like an ordinary array.

    vector<int> v;
    v.push_back(3); // [3]
    v.push_back(2); // [3,2]
    v.push_back(5); // [3,2,5]
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    // A shorter way to iterate through a vector is as follows:
    cout<<endl;
    for (auto x : v)
        cout << x << " ";
    cout<<endl;
    // pop_back removes the last element
    cout << v.back() << "\n"; // 5
    v.pop_back();
    cout << v.back() << "\n"; // 2

    vector<int> v2 = {2,4,2,5,1};
    // size 10, initial value 5
    vector<int> v3(10, 5); // 5 in default degeri 0
}

void d_s_set()
{
// A set can be used mostly like a vector, but it is not possible to access the elements using the [] notation
    set<int> s;
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(2);
    s.insert(5);
    cout << s.count(3)<<" ";
    cout << s.count(4)<<" ";
    s.insert(4);
    s.erase(3);
    cout << s.count(3)<<" ";
    cout << s.count(4)<<" ";
    cout<<endl;

    set<int> s2 = {2,5,6,8,2,2,2,2,2,2,2,2};
    cout << s2.size() << "\n"; // 4
    for (auto x : s2)
        cout << x << " ";

    cout<<endl;

    /*C++ also contains the structures multiset and unordered_multiset that other-
    wise work like set and unordered_set but they can contain multiple instances of
    an element. For example, in the following code all three instances of the number
    5 are added to a multiset:*/
    multiset<int> s3;
    s3.insert(5);
    s3.insert(5);
    s3.insert(5);
    s3.insert(5);
    cout << s3.count(5) << "\n"; // 4
    //Often, only one instance should be removed, which can be done as follows:
    s3.erase(s3.find(5));
    cout << s3.count(5) << "\n"; // 3
    //The function erase removes all instances of an element from a multiset:
    s3.erase(5);
    cout << s3.count(5) << "\n"; // 0
}

void d_s_map()
{
    // dictionary gibi pythondaki
    map<string,int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    m["harpsichord"] = 9;
    cout << m["banana"] << "\n"; // 3
    cout << m["aybabtu"] << "\n"; // 0
    if (m.count("aybabtu"))
        cout<<"key exists\n";

    for (auto x : m)
        cout << x.first << " " << x.second << "\n";
}

void iterators()
{
    vector <int> v = {4,3,2,5,6,6,12,2,3};
    cout<<endl;
    for (auto x : v)
        cout << x << " ";
    sort(v.begin(), v.end());
    cout<<endl;
    for (auto x : v)
        cout << x << " ";
    reverse(v.begin(), v.end());
    cout<<endl;
    for (auto x : v)
        cout << x << " ";
    random_shuffle(v.begin(), v.end());
    cout<<endl;
    for (auto x : v)
        cout << x << " ";

    //These functions can also be used with an ordinary array. In this case, the 
    //functions are given pointers to the array instead of iterators:
    int a[10] = {4,3,2,5,6,6,12,2,3,-9};
    cout<<endl;
    for (auto x : a)
        cout << x << " ";
    sort(a, a+10);
    cout<<endl;
    for (auto x : a)
        cout << x << " ";
    reverse(a, a+10);
    cout<<endl;
    for (auto x : a)
        cout << x << " ";
    random_shuffle(a, a+10);
    cout<<endl;
    for (auto x : a)
        cout << x << " ";
    cout<<endl;
}

void set_iterators()
{
    set <int> s = {3,5,2,1,4,6,9,8,7,0,-1,10} ;
    //set<int>::iterator it = s.begin();
    auto it = s.begin();
    cout << *it << "\n";
    auto it2 = s.end(); // } i gosterdigi icin son eleman icin bir azaltmamiz lazim
    cout << *--it2 << "\n";

    for (auto it = s.begin(); it != s.end(); it++)
        cout << *it << "\n";
    auto it3 = s.find(11);  // sonuna kadar gitti bulamazsa } degeri aldi daha dogrusu:
    // if the set does not contain x , the iterator will be end .
    if (it3 == s.end())
        cout<<"11 is not found\n";

    // The following code finds the element nearest to 6 :
    auto it4 = s.lower_bound(6);
    if (it4 == s.begin())
        cout << *it4 << "\n";
    else if (it4 == s.end())
    {
        it4--;
        cout << *it4 << "\n";   // (it4 - s.begin()) alternatif syntax
    }
    else
    {
        int a = *it4;
        it4--;
        int b = *it4;
        if (6-b < a-6)
            cout << b << "\n";
        else
            cout << a << "\n";
    }
}

void d_s_bitset()
{
    bitset<10> s;
    s[1] = 1;
    s[3] = 1;
    s[4] = 1;
    s[7] = 1;
    cout << s[4] << "\n"; // 1
    cout << s[5] << "\n"; // 0

    bitset<10> s2(string("0010011010")); // from right to left
    cout << s2[4] << "\n"; // 1
    cout << s2[5] << "\n"; // 0
    cout << s.count() << "\n"; // 4 number of ones

    bitset<10> a(string("0010110110"));
    bitset<10> b(string("1011011000"));
    cout << (a&b) << "\n"; // 0010010000
    cout << (a|b) << "\n"; // 1011111110
    cout << (a^b) << "\n"; // 1001101110
}

void d_s_deque()
{
// push_front and pop_front functions can be used in this datatype
    deque<int> d;
    d.push_back(5); // [5]
    d.push_back(2); // [5,2]
    d.push_front(3); // [3,5,2]
    d.pop_back(); // [3,5]
    d.pop_front(); // [5]
// The internal implementation of a deque is more complex than that of a vector, 
// and for this reason, a deque is slower than a vector.
}

void d_s_stack()
{
    // Last In First Out
    // It is only possible to access the top element of a stack.
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(5);
    cout << s.top(); // 5
    s.pop();
    cout << s.top(); // 2
}

void d_s_queue()
{
    // First In First Out
    // adding an element to the end of the queue, and removing the first element in the queue.
    queue<int> q;
    q.push(3);
    q.push(2);
    q.push(5);
    cout << q.front(); // 3
    q.pop();
    cout << q.front(); // 2
}

void d_s_priority_queue()
{
    // By default, the elements in a C++ priority queue are sorted in decreasing order
    priority_queue<int> q;
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(2);
    cout << q.top() << "\n"; // 7
    q.pop();
    cout << q.top() << "\n"; // 5
    q.pop();
    q.push(6);
    cout << q.top() << "\n"; // 6
    q.pop();
}

// Policy-based data structures
/*
The g++ compiler also supports some data structures that are not part of the C++
standard library. Such structures are called policy-based data structures. To use
these structures, the following lines must be added to the code:
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
After this, we can define a data structure indexed_set that is like set but can be
indexed like an array. The definition for int values is as follows:
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
Now we can create a set as follows:
indexed_set s;
s.insert(2);
s.insert(3);
s.insert(7);
s.insert(9);
The speciality of this set is that we have access to the indices that the elements
would have in a sorted array. The function find_by_order returns an iterator to
the element at a given position:
auto x = s.find_by_order(2);
cout << *x << "\n"; // 7
*/

int main()
{
    // d_s_vector();
    // d_s_set();
    // d_s_map();
    // iterators();
    // set_iterators();
    // d_s_bitset();
    // d_s_deque();
    // d_s_stack();
    // d_s_queue();
    return 0;
}