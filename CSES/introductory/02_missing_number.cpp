#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long numberSum = 0;

    long long allSum = n;

    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        allSum += i;
        numberSum += num;
    }

    cout << (allSum - numberSum) << endl;

    return 0;
}
