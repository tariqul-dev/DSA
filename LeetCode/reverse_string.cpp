#include <bits/stdc++.h>

using namespace std;

void reverseString(vector<char> &s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
    reverseString(s);

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}