#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v = {4,2,5,3,5,8,3};
    for (int i = 0; i < 7; i++)
        cout<<v[i];
    cout<<endl;

    sort(v.begin(),v.end());
    for (int i = 0; i < 7; i++)
        cout<<v[i];
    cout<<endl;

    sort(v.rbegin(),v.rend());
    for (int i = 0; i < 7; i++)
        cout<<v[i];
    cout<<endl;

    int n = 7; // array size
    int a[] = {4,2,5,3,5,8,3};
    for (int i = 0; i < 7; i++)
        cout<<a[i];
    cout<<endl;

    sort(a,a+n);
    for (int i = 0; i < 7; i++)
        cout<<a[i];
    cout<<endl;

    string s = "monkey";
    cout<<s;
    sort(s.begin(), s.end());
    cout<<endl<<s<<endl;

    vector<pair<int,int>> ve;
    ve.push_back({1,5});
    ve.push_back({2,3});
    ve.push_back({1,2});
    cout<<ve[0].first<<" "<<ve[0].second<<", ";
    cout<<ve[1].first<<" "<<ve[1].second<<", ";
    cout<<ve[2].first<<" "<<ve[2].second<<endl;
    sort(ve.begin(), ve.end());
    cout<<ve[0].first<<" "<<ve[0].second<<", ";
    cout<<ve[1].first<<" "<<ve[1].second<<", ";
    cout<<ve[2].first<<" "<<ve[2].second<<endl;

    vector<tuple<int,int,int>> vec;
    vec.push_back({2,1,4});
    vec.push_back({1,5,3});
    vec.push_back({2,1,3});
    for (int i = 0; i < vec.size(); i++) 
        cout << get<0>(vec[i]) << " " 
             << get<1>(vec[i]) << " " 
             << get<2>(vec[i]) << ", ";
    sort(vec.begin(), vec.end());
    cout<<endl;
    for (int i = 0; i < vec.size(); i++) 
        cout << get<0>(vec[i]) << " " 
             << get<1>(vec[i]) << " " 
             << get<2>(vec[i]) << ", ";
    return 0;
    /*  ?
struct P {
int x, y;
bool operator<(const P &p) {
if (x != p.x) return x < p.x;
else return y < p.y;
}
};
?

bool comp(string a, string b) {
if (a.size() != b.size()) return a.size() < b.size();
return a < b;
}
sort(v.begin(), v.end(), comp);
    */
}