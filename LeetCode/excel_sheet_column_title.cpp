#include <bits/stdc++.h>

using namespace std;

string convertToTitle(int columnNumber)
{
    string result = "";

    cout << 'A' + columnNumber - 1 << endl;
    cout << char('A' + columnNumber - 1) << endl;
}

int main()
{
    int columnNumber = 1;

    cout << convertToTitle(columnNumber) << endl;

    return 0;
}