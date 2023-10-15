#include <bits/stdc++.h>

using namespace std;

void print(vector<int> ans)
{
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    int largest = INT_MIN, secondLargest = INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        if (a[i] > secondLargest && a[i] < largest)
            secondLargest = a[i];

        if (a[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = a[i];
        }
        if (a[i] < secondSmallest && a[i] != smallest)
            secondSmallest = a[i];
    }

    return {secondLargest, secondSmallest};
}

int main()
{

    int n = 5;
    vector<int> a = {1, 2, 3, 4, 5};

    print(getSecondOrderElements(n, a));

    return 0;
}