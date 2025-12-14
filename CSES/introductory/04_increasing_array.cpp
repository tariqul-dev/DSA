#include <iostream>

using namespace std;

int main()
{
    long long moves = 0;
    long long n;
    long long last;

    cin >> n >> last;

    for (int i = 1; i < n; i++)
    {
        long x;
        cin >> x;
        if (x < last)
        {
            moves += (last - x);
        }
        else
        {
            last = x;
        }
    }

    cout << moves << endl;

    return 0;
}
