#include <bits/stdc++.h>
using namespace std;
bool found(int arr[], int n, int x)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == x)
        {
            return true;
        }
        else if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    while (q--)
    {

        int x;
        cin >> x;

        if (found(arr, n, x))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}