#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int precedence(char op)
    {
        if (op == '+')
        {
            return 1;
        }
        if (op == '-')
        {
            return 1;
        }
        if (op == '*')
        {
            return 2;
        }
        else
        {
            return 2;
        }
    }

    int result(int a, int b, char op)
    {
        if (op == '+')
        {
            return a + b;
        }
        if (op == '-')
        {
            return a - b;
        }
        if (op == '*')
        {
            return a * b;
        }
        else
        {
            return a / b;
        }
    }

public:
    int calculate(string s)
    {
        stack<int> res;
        stack<char> op;

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                if (i >= 1 && isdigit(s[i - 1]))
                {
                    string x = to_string(res.top()) + s[i];
                    res.pop();
                    res.push(stoi(x));
                }
                else
                {
                    res.push(s[i] - '0');
                }
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
            {
                while (op.size() > 0 && precedence(s[i]) <= precedence(op.top()))
                {
                    char x = op.top();
                    op.pop();
                    int b = res.top();
                    res.pop();
                    int a = res.top();
                    res.pop();
                    res.push(result(a, b, x));
                }
                op.push(s[i]);
            }
        }
        while (op.size() > 0)
        {
            char x = op.top();
            op.pop();
            int b = res.top();
            res.pop();
            int a = res.top();
            res.pop();
            res.push(result(a, b, x));
        }
        return res.top();
    }
};