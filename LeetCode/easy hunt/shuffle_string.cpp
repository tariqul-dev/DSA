#include <bits/stdc++.h>

using namespace std;

string restoreString(string s, vector<int> &indices)
{
    string ans = s;

    for (int i = 0; i < s.size(); i++)
        ans[indices[indices[i]]] = s[indices[i]];

    return ans;
}

int main()
{
    string s = "aiohn";
    vector<int> indices = {3, 1, 4, 2, 0};

    cout << restoreString(s, indices) << endl;

    return 0;
}