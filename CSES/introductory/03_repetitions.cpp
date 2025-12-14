#include <iostream>
#include <string>

using namespace std;

int main()
{
    char currentChar = ' ';
    int maxLength = -999;
    int currentLength = 0;
    string s;
    cin >> s;

    for (char c : s)
    {
        if (c != currentChar)
        {
            currentLength = 1;
            currentChar = c;
        }
        else
        {
            currentLength++;
        }

        maxLength = max(maxLength, currentLength);
    }

    cout << maxLength << endl;
}
