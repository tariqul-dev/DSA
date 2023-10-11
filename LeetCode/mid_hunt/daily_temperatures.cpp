#include <bits/stdc++.h>

using namespace std;

void print(vector<int> result)
{
    for (auto r : result)
    {
        cout << r << " ";
    }

    cout << endl;
}

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> ans(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); i++)
    {
        int count = 0;

        for (int j = i + 1; j < temperatures.size(); j++)
        {
            if (temperatures[i] < temperatures[j])
            {
                count = abs(j - i);
                break;
            }
        }
        ans[i] = count;
    }

    return ans;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> ans = dailyTemperatures(temperatures);

    cout << endl;
    print(ans);

    return 0;
}