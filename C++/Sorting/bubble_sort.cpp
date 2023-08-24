#include <bits/stdc++.h>

using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }

    cout << endl;
}

void bubbleSort(int arr[], int size)
{

    for (int i = 1; i < size; i++)
    {
        cout << "iteration: " << i << endl;
        int flag = 0;

        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }

            printArray(arr, size);
        }

        cout << endl;

        if (flag == 0)
            break;
    }
}

int main()
{
    int size = 7;

    int arr[size] = {
        14, 11, 1, 3, 2, 5, 4};

    cout << "Before sorting" << endl;

    printArray(arr, size);

    bubbleSort(arr, size);

    cout << "After sorting" << endl;

    printArray(arr, size);

    return 0;
}