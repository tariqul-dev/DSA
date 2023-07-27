#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr, int low, int high)
{
    if (low == high)
        return;

    cout << arr[low] << " ";
    print(arr, low + 1, high);
}

int getPartition(vector<int> &arr, int low, int high)
{

    int pVot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pVot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pVot && j >= low + 1)
        {
            j--;
        }

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int partitionIndex = getPartition(arr, low, high);
    quickSort(arr, low, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, high);

}

int main()
{

    vector<int> arr = {5, 7, 3, 2, 9, 6};

    print(arr, 0, arr.size());
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    print(arr, 0, arr.size());

    return 0;
}