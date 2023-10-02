#include <bits/stdc++.h>
using namespace std;

string getString(int &num)
{
    string s;

    while (num > 0)
    {
        s += (num % 10) + '0';
        num /= 10;
    }

    return s;
}

int minimumSum(int num)
{
    string s = getString(num);

    sort(s.begin(), s.end());

    string s1 = "", s2 = "";

    s1 += s[0];
    s2 += s[1];

    s1 += s[3];
    s2 += s[2];

    return stoi(s1) + stoi(s2);

    return 0;
}

int main()
{

    int num = 4009;

    cout << minimumSum(num) << endl;

    return 0;
}