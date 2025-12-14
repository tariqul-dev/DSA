#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long y, x;
        cin >> y >> x;

        long long result = 1;

        if (x > y)
        {
            long long maxVal = max(y, x);

            if (maxVal % 2 == 0)
            {
                result = (maxVal - 1) * (maxVal - 1) + y;
            }
            else
            {
                result = (maxVal * maxVal) - (y - 1);
            }
        }
        else
        {
            long long maxVal = max(y, x);
            if (maxVal % 2 == 0)
            {
                result = (maxVal * maxVal) - (x - 1);
            }
            else
            {
                result = (y - 1) * (y - 1) + x;
            }
        }
        cout << result << endl;
    }

    cout << endl;

    return 0;
}