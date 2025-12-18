#include <iostream>

using namespace std;

int main()
{

    long long t;
    cin >> t;

    while (t--)
    {
        long long a, b;
        cin >> a >> b;

        if ((max(a, b) / 2) > min(a, b))
        {
            cout << "NO" << endl;
            continue;
        }

        if ((a + b) % 3 == 0)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }

        cout << endl;
    }

    return 0;
}

