#include <bits/stdc++.h>

using namespace std;

// this function will print every element of an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// finding max value from an array
int findMaxValue(int arr[], int size)
{
    int maxValue = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxValue)
        {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

// populate the counter with frequency of element of arr array
void populateCounter(int arr[], int counter[], int size)
{

    for (int i = 0; i < size; i++)
    {
        counter[arr[i]]++;
    }
}

// caltulating prefix/cumulative sum of counter array
void prefixSum(int counter[], int size)
{
    for (int i = 1; i <= size; i++)
    {
        counter[i] += counter[i - 1];
    }
}

// sorting the arr and populate finalArr with sorted value
void counterSort(int arr[], int counter[], int finalArr[], int size)
{

    for (int i = size - 1; i >= 0; i--)
    {
        counter[arr[i]]--;

        int index = counter[arr[i]];
        finalArr[index] = arr[i];
    }
}

int main()
{

    int n = 12;

    int arr[n] = {8, 7, 6, 5, 4, 3, 2, 1, 2, 6, 7, 4};

    cout << "Before sorting" << endl;
    printArray(arr, n);
    // s1: finding max value
    int maxValue = findMaxValue(arr, n);
    cout << "max value: " << maxValue << endl;
    // s2: create counter array length maxValue + 1
    int counter[maxValue + 1];
    memset(counter, 0, sizeof(counter));

    // s3: populate counter array with frequency number of arr
    populateCounter(arr, counter, n);

    // s4: calculate prefix sum of counter
    prefixSum(counter, maxValue + 1);
    cout << "prefix sum: " << endl;

    printArray(counter, maxValue + 1);
    // s5: sort the array
    int finalArr[n];
    counterSort(arr, counter, finalArr, n);

    printArray(finalArr, n);

    return 0;
}