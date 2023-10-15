#include <bits/stdc++.h>

using namespace std;

string convertToTitle(int columnNumber)
{
    string result = "";

    while (columnNumber > 0)
    {
        columnNumber--;
        char c = 'A' + columnNumber % 26;
        result += c;
        columnNumber /= 26;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main()
{
    int columnNumber = 53;

    cout << convertToTitle(columnNumber) << endl;

    return 0;
}