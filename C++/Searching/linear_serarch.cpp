#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int searchUniqueValue(int *arr, int size, int key)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int *searchMultiValue(int *arr, int size, int key)
{
    int flag = 0;
    int *result = new int(size);
    int index = 0;

    for (int i = 0; i < size; i++)
    {
        result[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            // cout << i << " ";
            result[index++] = i;
            flag = 1;
        }
    }

    if (flag == 0)
    {
        cout << "Not found";
    }

    cout << endl;
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 2, 2, 5, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 2;

    // cout << searchUniqueValue(arr, size, x) << endl;
    int *result;
    result = searchMultiValue(arr, size, x);

    for (int i = 0; i < size; i++)
    {
        cout << result[i] << " ";
    }

    cout << endl;
    return 0;
}
