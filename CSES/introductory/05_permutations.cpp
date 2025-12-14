#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> results;

    int n;

    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 2; i <= n; i += 2)
    {
        results.push_back(i);
    }

    for (int i = 1; i <= n; i += 2)
    {
        results.push_back(i);
    }

    for (int i = 0; i < results.size(); i++)
    {
        if (abs(results[i] - results[i + 1]) == 1)
        {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }

    for (auto r : results)
    {
        cout << r << " ";
    }

    cout << endl;

    return 0;
}
