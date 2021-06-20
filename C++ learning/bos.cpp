#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r)
{
    int i, j;
    int c,m,n,temp,stop,L,index;
    m = matrix.size();
    n = matrix[0].size();
    (m<n) ? stop=m/2:stop=n/2;
    vector<int>array_around;
	cout<<endl<<endl;
    for (i=0; i<matrix.size(); i++)
    {
        for (j=0; j<matrix[0].size(); j++)
			printf("%3d", matrix[i][j]);
		cout<<endl;
    }
    for (c=0; c<stop; c++)
    {
        //get array outer matrix
        j=c;
        for(i=c; i<=m-1-c; i++)
            array_around.push_back(matrix[i][j]);
        i=m-1-c;
        for(j=c+1; j<=n-1-c-1; j++)
            array_around.push_back(matrix[i][j]);
        j=n-1-c;
        for(i=m-1-c; i>=c; i--)
            array_around.push_back(matrix[i][j]);
        i=c;
        for(j=n-1-c-1; j>=c+1; j--)
            array_around.push_back(matrix[i][j]);
        
        //checking
        for (i=0; i<array_around.size(); i++)
            cout<<array_around[i]<<" ";
        cout<<endl;
        
        // shift array
        L=array_around.size();
		temp = r%L;
        for (i=0; i<L-temp; i++)
            array_around.push_back(array_around[i]);
        array_around.erase(array_around.begin(), array_around.begin()+(L-temp));
        
        //checking
        for (i=0; i<array_around.size(); i++)
            cout<<array_around[i]<<" ";
        cout<<endl;
        
        //put array to outer matrix
        j=c;
        index=0;
        for(i=c; i<=m-1-c; i++,index++)
            matrix[i][j] = array_around[index];
        i=m-1-c;
        for(j=c+1; j<=n-1-c-1; j++,index++)
            matrix[i][j] = array_around[index];
        j=n-1-c;
        for(i=m-1-c; i>=c; i--,index++)
            matrix[i][j] = array_around[index];
        i=c;
        for(j=n-1-c-1; j>=c+1; j--,index++)
            matrix[i][j] = array_around[index];
        array_around.clear();
    }
    // print matrix
	cout<<endl<<endl;
    for (i=0; i<matrix.size(); i++)
    {
        for (j=0; j<matrix[0].size(); j++)
			printf("%3d", matrix[i][j]);
		cout<<endl;
    }
}

int main()
{
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int m = stoi(first_multiple_input[0]);

    int n = stoi(first_multiple_input[1]);

    int r = stoi(first_multiple_input[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
/*
10 8 40
1 32 31 30 29 28 27 26
2 1 24 23 22 21 20 25
3 2 1 16 15 14 19 24
4 3 2 1 8 13 18 23
5 4 3 2 7 12 17 22
6 5 4 3 6 11 16 21
7 6 5 4 5 10 15 20
8 7 6 7 8 9 14 19
9 8 9 10 11 12 13 18
10 11 12 13 14 15 16 17

*/