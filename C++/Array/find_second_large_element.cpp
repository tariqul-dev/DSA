#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {5, 6, 6, 3, 2, 7, 8, 2, 7};
    int largest = arr[0];
    int secondLarge = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }

        if (arr[i] > secondLarge && arr[i] < largest)
        {
            secondLarge = arr[i];
        }
    }

    cout << largest << " " << secondLarge << endl;

    return 0;
}