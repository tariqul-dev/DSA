#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr, int i = 0)
{
    if (i >= arr.size())
        return;

    cout << arr[i] << " ";

    print(arr, i + 1);
}

int findMinElementIndex(vector<int> &arr, int minIndex = 0, int startIndex = 0)
{
    if (startIndex >= arr.size())
        return minIndex;

    if (arr[startIndex] < arr[minIndex])
        minIndex = startIndex;

    return findMinElementIndex(arr, minIndex, startIndex + 1);
}

void selectionSort(vector<int> &arr, int startIndex = 0)
{
    if (startIndex >= arr.size() - 1)
        return;

    int minIndex = findMinElementIndex(arr, startIndex, startIndex);

    swap(arr[startIndex], arr[minIndex]);

    selectionSort(arr, startIndex + 1);
}

int main()
{

    vector<int> arr = {4, 5, 2, 6, 9, 1};

    print(arr);
    cout << endl;

    selectionSort(arr);

    print(arr);
    cout << endl;

    return 0;
}