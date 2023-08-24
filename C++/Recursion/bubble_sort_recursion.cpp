#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr, int i = 0)
{
    if (i >= arr.size())
        return;
    cout << arr[i] << " ";

    print(arr, i + 1);
}

void swapElement(vector<int> &arr, int endIndex, int startIndex = 0)
{
    // base condision
    if (endIndex == startIndex)
        return;

    // Checking element before swap
    if (arr[startIndex] > arr[startIndex + 1])
        swap(arr[startIndex], arr[startIndex + 1]);

    // Recursion call with next index, here startIndex + 1
    swapElement(arr, endIndex, startIndex + 1);
}

void bubbleSort(vector<int> &arr, int endIndex)
{
    // base condision
    if (endIndex == 0)
        return;
    // swap every element from 0 to its size
    swapElement(arr, endIndex);

    // recursion call with endIndex - 1
    bubbleSort(arr, endIndex - 1);
}

int main()
{
    vector<int> arr = {4, 5, 2, 6, 9, 1};

    print(arr);
    cout << endl;

    bubbleSort(arr, arr.size() - 1);


    print(arr);

    return 0;
}