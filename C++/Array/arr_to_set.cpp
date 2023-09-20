#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> v = {5, 6, 6, 3, 2, 7, 8, 2, 7};

    set<int> s;

    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }

    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}