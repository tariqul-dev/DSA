#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[10] = {3, 9, 6, 7, 4};

    int size = 5;

    int index;
    cin >> index;
    if (index < 0 || index >= 5)
        return -1;

    cout << "Before deletion" << endl;
    printArray(arr, size);

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;

    cout << "After deletion" << endl;
    printArray(arr, size);

    return 0;
}