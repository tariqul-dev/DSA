#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n = 5;
    int k = 50;
    int arr[n] = {1, 2, 3, 4, 5};

    for (int i = 0; i < (k > n ? k % 5 : k); i++)
    {
        cout << "I: " << i << " " << endl;

        int fs = arr[0];
        for (int j = 1; j < n; j++)
        {
            arr[j - 1] = arr[j];
        }

        arr[n - 1] = fs;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}