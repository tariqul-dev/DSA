#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int freqArr[26] = {0};

    for (char c : s)

        freqArr[c - 'A']++;

    int oddCount = 0;
    int middleChar = -1;

    for (int i = 0; i < 26; i++)
    {
        if (freqArr[i] % 2 != 0)
        {
            oddCount++;
            middleChar = i;
        }
    }

    if (oddCount > 1)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    int left = 0, right = s.length() - 1;

    for (int i = 0; i < 26; i++)
    {
        while (freqArr[i] >= 2)
        {
            s[left++] = i + 'A';
            s[right--] = i + 'A';

            freqArr[i] -= 2;
        }
    }

    if (middleChar != -1)
        s[left] = middleChar + 'A';

    cout << s << endl;

    return 0;
}