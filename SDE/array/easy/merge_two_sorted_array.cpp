#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    // Brute force : tc-> O(n1*logn + n2*logn) + O(n1 + n2), sc->O(n + n1 + n2) + O(n1 + n2)
    // set<int> st;

    // vector<int> unionArr;

    // for (int i : a)
    //     st.insert(i);

    // for (int i : b)
    //     st.insert(i);

    // for (int i : st)
    //     unionArr.push_back(i);

    // return unionArr;

    // Better
    vector<int> ans;

    int left = 0, right = 0;

    while (left < a.size() && right < b.size())
        if (a[left] <= b[right])
        {
            if (ans.size() == 0 || ans.back() != a[left])
                ans.push_back(a[left]);

            left++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != b[right])
                ans.push_back(b[right]);

            right++;
        }

    while (left < a.size())
    {
        if (ans.back() != a[left])
            ans.push_back(a[left]);

        left++;
    }

    while (right < b.size())
    {
        if (ans.back() != b[right])
            ans.push_back(b[right]);

        right++;
    }

    return ans;
}

int main()
{

    vector<int> a = {2, 3, 5, 5, 6, 8, 8, 9};
    vector<int> b = {1, 5, 7, 7, 9, 10};

    vector<int> c = sortedArray(a, b);

    print(c);

    return 0;
}