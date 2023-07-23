#include <bits/stdc++.h>

using namespace std;

// vector<int> arr = {3, 1, 2};

void printArray(vector<int> data, int i = 0)
{
    if (i >= data.size())
    {
        return;
    }

    cout << data[i] << " ";

    printArray(data, i + 1);
}

void printSubsequence(vector<int> &arr, vector<int> &output, int i = 0)
{
    if (i >= arr.size())
    {
        // cout << "terminate function" << endl;
        printArray(output);
        cout << endl;
        return;
    }

    output.push_back(arr[i]);

    // cout << "after pushing: " << endl;
    // printArray(output);

    printSubsequence(arr, output, i + 1);

    output.pop_back();
    // cout << "after poping: " << endl;
    // printArray(output);

    printSubsequence(arr, output, i + 1);
}

int main()
{

    vector<int> arr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    


    vector<int> output = {};
    // printArray(arr);
    printSubsequence(arr, output);

    return 0;
}