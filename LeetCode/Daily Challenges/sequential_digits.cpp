#include <bits/stdc++.h>

using namespace std;

vector<int> sequentialDigits(int low, int high)
{
    queue<int> q;
    vector<int> ans;

    for (int i = 1; i <= 8; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        int temp = q.front();
        q.pop();

        if (temp >= low && temp <= high)
        {
            ans.push_back(temp);
        }

        int ld = temp % 10;

        if (ld + 1 > 9)
            continue;

        int nextDigit = (temp * 10) + (ld + 1);
        q.push(nextDigit);
    }

    return ans;
}

int main()
{
    int low = 100, high = 300;

    for (int num : sequentialDigits(low, high))
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}