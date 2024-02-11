#include <iostream>
using namespace std;

int main()
{
    int n, maxi = 0;
    cin >> n;

    int inp[n], out[n];

    for (int i = 0; i < n; i++)
    {
        cin >> inp[i];
        if (inp[i] > maxi)
            maxi = inp[i];
    }

    int count[maxi + 1];
    for (int i = 0; i <= maxi; i++)
    {
        count[i] = 0;
    }

    for (auto i : inp)
    {
        count[i]++;
    }

    for (int i = 1; i < maxi + 1; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        out[--count[inp[i]]] = inp[i];
    }

    for (auto i : out)
    {
        cout << i << " ";
    }
    cout << endl;
}