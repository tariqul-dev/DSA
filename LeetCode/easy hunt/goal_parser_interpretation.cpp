#include <bits/stdc++.h>

using namespace std;

string interpret(string command)
{
    string s = "";

    for (int i = 0; i < command.size(); i++)
    {
        if (command[i] == 'G')
            s += 'G';
        else if (command[i] == '(' && command[i + 1] == ')')
            s += 'o', i++;
        else
            s += "al", i += 3;
    }

    return s;
}

int main()
{
    string command = "(al)G(al)()()G";

    cout << interpret(command) << endl;

    return 0;
}