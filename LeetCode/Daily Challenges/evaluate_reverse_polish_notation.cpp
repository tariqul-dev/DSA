#include <bits/stdc++.h>

using namespace std;

int calculate(int a, int b, string token)
{
    int result = 0;

    switch (token[0])
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = (long)a * (long)b;
        break;
    case '/':
        result = a / b;
        break;
    }

    return result;
}

int stringToInt(string s)
{
    int number = 0;
    int neg = s[0] == '-';

    int i = neg ? 1 : 0;

    while (s[i] >= '0' && s[i] <= '9')
    {
        number *= 10;
        number += s[i] - '0';
        i++;
    }

    if (neg)
        number *= -1;

    return number;
}

int evalRPN(vector<string> &tokens)
{
    stack<int> st;

    for (string token : tokens)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            int result = calculate(a, b, token);

            st.push(result);
        }
        else
        {
            st.push(stringToInt(token));
        }
    }

    return st.top();
}

int main()
{
    vector<string> tokens = {"4", "13", "5", "/", "+"};

    cout << evalRPN(tokens) << endl;

    return 0;
}