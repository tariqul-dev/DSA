#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
    stack<char> st;

    st.push(s[0]);

    for (int i = 1; i < s.size(); i++)
    {
        if (!st.empty())
        {
            char top = st.top();
            if ((top == '(' && s[i] == ')') || (top == '{' && s[i] == '}') || (top == '[' && s[i] == ']'))
            {
                
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }

    return st.empty();
}

int main()
{
    string s = "({[)";

    cout << isValid(s) << endl;

    return 0;
}