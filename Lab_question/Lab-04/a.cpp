#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    ll n;
    cin >> n;

    vector<pair<ll, ll>> a(n);

    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;

        a[i].first = x;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    ll m;
    cin >> m;
    vector<int> q(m);
    for (int i = 0; i < m; i++)
    {
        cin >> q[i];
    }
    for (int i = 0; i < m; i++)
    {
        int k = q[i];
        ll l = 0, h = n - 1;
        bool found = false;

        while (l <= h)
        {
            ll m = (l + h) >> 1;
            if (a[m].first == k)
            {
                // cout << m << endl;
                cout << a[m].second << endl;
                found = true;
                break;
            }
            else if (a[m].first < k)
            {
                l = m + 1;
            }
            else
            {
                h = m - 1;
            }
        }
        if (!found)
        {
            cout << -1 << endl;
        }
    }
}