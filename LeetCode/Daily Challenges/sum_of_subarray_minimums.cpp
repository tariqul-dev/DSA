#include <bits/stdc++.h>

using namespace std;

vector<int> getNsl(vector<int> &arr, int n)
{
    vector<int> result(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            result[i] = -1;
        }
        else
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            result[i] = st.empty() ? -1 : st.top();
        }

        st.push(i);
    }

    return result;
}

vector<int> getNsr(vector<int> &arr, int n)
{
    vector<int> result(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            result[i] = n;
        }
        else
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            result[i] = st.empty() ? n : st.top();
        }

        st.push(i);
    }

    return result;
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nsl = getNsl(arr, n); // nsl = next smaller left
    vector<int> nsr = getNsr(arr, n); // nsl = next smaller right

    long long sum = 0;

    int modulo = 1e9 + 7;

    for (int i = 0; i < n; i++)
    {
        long long ls = i - nsl[i]; // ls = left smaller count
        long long rs = nsr[i] - i; // rs = right smaller count

        long long totalWays = ls * rs;

        long long totalSum = arr[i] * totalWays;

        sum = (sum + totalSum) % modulo;
    }

    return sum;
}

int main()
{

    vector<int> arr = {3, 1, 2, 4};

    cout << sumSubarrayMins(arr) << endl;

    return 0;
}