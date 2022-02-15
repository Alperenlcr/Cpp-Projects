#include <bits/stdc++.h>


using namespace std;
int main()
{
    vector<string> Q;
    vector<string> start_end;
    int c = 0;
    string str = "Q:q0,q1,q2,q3,q4 => (q0),[q0],[q1]";
    string token1;
    stringstream s(str);
    while(s >> token1)
    {
        istringstream ss(token1);
        string token2;
        
        while(getline(ss, token2, ':'))
        {
            if(c==1)
            {
                istringstream s(token2);
                string token3;
                while(getline(s, token3, ','))
                    Q.push_back(token3);
            }
            else if(c==3)
            {
                istringstream s(token2);
                string token3;
                while(getline(s, token3, ','))
                {
                    token3.pop_back();
                    token3.erase(token3.begin());
                    start_end.push_back(token3);
                }
            }
            c++;
        }
    }
    for (int i = 0; i < Q.size(); i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < start_end.size(); i++)
    {
        cout << start_end[i] << " ";
    }
    
    
    return 0;
}



/*
    cout << endl << "Q : ";
    for ( i = 0; i < Q.size(); i++)
        cout << Q[i] << " ";
    cout << endl << "start_end : ";
    for ( i = 0; i < start_end.size(); i++)
        cout << start_end[i] << " ";
    
    cout << "\nA : " << A << "\nZ : " << Z;
    cout << "\ninputs : ";
    for ( i = 0; i < inputs.size(); i++)
        cout << inputs[i] << " ";

    for ( i = 0; i < T.size(); i++)
    {
        cout << "\nT : ";
        for ( j = 0; j < T[i].size(); j++)
        {
            cout << T[i][j] << " ";
        }
    }
*/