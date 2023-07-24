#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr, int index = 0)
{
    if (index >= arr.size())
        return;

    cout << arr[index] << " ";
    print(arr, index + 1);
}

void printKSum(vector<int> &arr, vector<int> output, int key, int index = 0, int sum = 0)
{
    if (index >= arr.size())
    {
        if (sum == key)
        {
            print(output);
            cout << endl;
        }

        return;
    }

    output.push_back(arr[index]);
    sum += arr[index];

    printKSum(arr, output, key, index + 1, sum);

    output.pop_back();
    sum -= arr[index];

    printKSum(arr, output, key, index + 1, sum);
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

    int maxValue = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }


    printKSum(arr, vector<int>(), maxValue);

    cout << endl;
}