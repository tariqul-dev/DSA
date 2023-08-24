#include <bits/stdc++.h>

using namespace std;

void subSetSum(vector<int> &arr, vector<int> &result, int sum = 0, int index = 0)
{
    if (index == arr.size())
    {
        result.push_back(sum);
        return;
    }

    sum += arr[index];

    subSetSum(arr, result, sum, index + 1);

    sum -= arr[index];

    subSetSum(arr, result, sum, index + 1);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> result;

    subSetSum(arr, result);

    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}