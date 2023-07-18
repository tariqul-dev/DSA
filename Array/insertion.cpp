#include <bits/stdc++.h>

using namespace std;

void printArrary(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{

    int arr[10] = {4, 10, 3, 5, 7};

    int size = 5;
    int index, value;

    cin >> index >> value;

    if (index < 0 || index > size)
        return 0;

    cout << "Before insertion" << endl;
    printArrary(arr, size);

    for (int i = size; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[index] = value;

    cout << "after insertion" << endl;
    printArrary(arr, size + 1);

    return 0;
}