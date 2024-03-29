#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int arr[26];

    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }

    for (auto i : s)
    {
        arr[i - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        while (arr[i]--)
        {
            cout << (char)(i + 'a');
        }
    }
    cout << endl;
}