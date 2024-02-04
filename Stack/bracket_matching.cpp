#include <bits/stdc++.h>
using namespace std;

bool isOpening(char c)
{
    return c == '(' or c == '{' or c == '[';
}

bool isMatching(char o, char c)
{
    return (o == '(' and c == ')') or (o == '{' and c == '}') or (o == '[' and c == ']');
}

bool isValid(string str, stack<char> s)
{
    for (auto i : str)
    {
        if (isOpening(i))
            s.push(i);
        else if (!s.empty() and isMatching(s.top(), i))
            s.pop();
        else
            s.push(i);
    }
    return s.empty();
}

int main()
{
    string str;
    cin >> str;

    stack<char> s;

    isValid(str, s) ? cout << "Valid" << endl : cout << "Not valid" << endl;

    return 0;
}