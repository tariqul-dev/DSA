#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long totalSum = (n * (n + 1)) / 2;

    if (totalSum % 2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    long long i = 1, j = n;
    long long tergetSum = totalSum / 2;
    vector<long long> set1, set2;
    long long setSum = 0;

    while (i <= j)
    {
        if ((setSum + i + j) <= tergetSum)
        {
            setSum += (i + j);
            set1.push_back(i++);
            set1.push_back(j--);
        }
        else
        {
            set2.push_back(j--);
        }
    }

    if (i == j)
        set2.push_back(i);

    cout << set1.size() << endl;
    for (long long s : set1)
    {
        cout << s << " ";
    }

    cout << endl
         << set2.size() << endl;
    for (long long s : set2)
    {
        cout << s << " ";
    }

    cout << endl;

    return 0;
}