#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    vector<ll> ph(20000), nh(20000);
    for (int i = 0; i < n; i++)
    {
        double x;
        cin >> x;
        int p = abs(x * 10000);
        if (x > 0)
        {
            ph[p]++;
        }
        else
        {
            nh[p]++;
        }
    }
    for (int i = 10000; i >= 0; i--)
    {
        while (nh[i])
        {
            cout << -i * 1.0000 / 10000 << '\n';
            nh[i]--;
        }
    }
    for (int i = 0; i <= 10000; i++)
    {
        while (ph[i])
        {
            cout << i * 1.0000 / 10000 << '\n';
            ph[i]--;
        }
    }
}