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
    stack<int> st;

    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            st.pop();

        if (!st.empty())
            ans[i] = st.top() - i;

        st.push(i);
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