#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    cout << "You have entered " << argc-1
         << " arguments:" << "\n";
    string dpda_file, input_file, output_file;
    dpda_file = argv[1];
    input_file = argv[2];
    output_file = argv[3];
    cout << dpda_file << input_file << output_file;
    return 0;
}