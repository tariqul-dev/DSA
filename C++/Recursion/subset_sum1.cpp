#include <bits/stdc++.h>

using namespace std;

void subsetSum(vector<int> &arr, int index, vector<int> &result, int sum = 0)
{
    if (index >= arr.size())
    {
        result.push_back(sum);
        return;
    }

    sum += arr[index];

    subsetSum(arr, index + 1, result, sum);

    sum -= arr[index];

    subsetSum(arr, index + 1, result, sum);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> result;

    subsetSum(arr, 0, result);

    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}