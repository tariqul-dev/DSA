#include <bits/stdc++.h>

using namespace std;

int fact(int n)
{
    if (n == 1)
        return n;
    return n * fact(n - 1);
}

void reverseArray(int *arr, int i, int n)
{
    if (i >= n / 2)
    {
        return;
    }

    swap(arr[i], arr[i + n - 1]);

    reverseArray(arr, i + 1, n);
}

bool isPalidrome(string s, int n, int i = 0)
{
    if (i >= n / 2)
        return true;

    if (s[i] != s[n - i - 1])
        return false;

    return isPalidrome(s, n, i + 1);
}

int main()
{
    // int n;
    // cin >> n;

    // cout << fact(n) << endl;

    // int arr[4] = {1, 2, 3, 4};

    // for (int i = 0; i < 4; i++)
    //     cout << arr[i] << " ";

    // reverseArray(arr, 0, 3);

    // cout << endl;

    // for (int i = 0; i < 4; i++)
    //     cout << arr[i] << " ";

    // cout << endl;

    string s = "211112";

    bool isPalin = isPalidrome(s, s.size());

    if (isPalin)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    cout << endl;

    return 0;
}