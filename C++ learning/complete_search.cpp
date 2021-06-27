#include <bits/stdc++.h>

using namespace std;
void vector_yazdir(vector<int> subset)
{
    int i, size = subset.size();
    for ( i = 0; i < size; i++)
    {
        cout << subset[i] << " ";
    }
    cout << endl;
}
void all_subsets(int k, int n, vector<int> subset)
{
    if (k == n)
    {
        // process subset
        vector_yazdir(subset);
    }
    else
    {
        all_subsets(k+1, n, subset);
        subset.push_back(k);
        all_subsets(k+1, n, subset);
        subset.pop_back();
    }
}
int main()
{
    vector<int> v = {};
    all_subsets(1, 5, v);

    return 0;
}