#include <bits/stdc++.h>

using namespace std;

// vector<int> dailyTemperatures(vector<int> &temperatures)
// {
//     int n = temperatures.size();
//     vector<int> ans(n, 0);

//     for (int i = 0; i < n; i++)
//     {

//         int count = 0;

//         for (int j = i + 1; j < n; j++)
//         {
//             if (temperatures[j] > temperatures[i])
//             {
//                 count = j - i;
//                 break;
//             }
//         }

//         ans[i] = count;
//     }

//     return ans;
// }

// Optimal (Monotonic stack)
vector<int> dailyTemperatures(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && temperatures[i] >= temperatures[st.top()])
            st.pop();

        if (st.empty())
            ans[i] = 0;
        else
            ans[i] = st.top() - i;

        st.push(i);
    }

    return ans;
}

int main()
{
Input:
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    for (int &temp : dailyTemperatures(temperatures))
    {
        cout << temp << " ";
    }

    cout << endl;

    //    Output : [ 1, 1, 4, 2, 1, 1, 0, 0 ]

    return 0;
}