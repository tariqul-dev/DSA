#include <bits/stdc++.h>

using namespace std;

void print(vector<int> ans)
{
    for (int a : ans)
        cout << a << " ";
    cout << endl;
}

vector<int> superiorElements(vector<int> &a)
{
    vector<int> ans;
    int n = a.size();

    int maxValue = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > maxValue)
        {
            ans.push_back(a[i]);
            maxValue = max(a[i], maxValue);
        }
    }

    return ans;
}

int main()
{

    vector<int> a = {1, 2, 3, 2};
    int n = 4;

    print(superiorElements(a));

    cout << endl;

    return 0;
}