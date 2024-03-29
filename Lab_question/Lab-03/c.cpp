#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    float arr[n];

    int len = n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int j = 0; j < len; j++)
    {
        for (int k = j; k < len; k++)
        {
            if ((float)arr[k] <= (float)arr[j])
            {
                float x = (float)arr[k];
                arr[k] = (float)arr[j];
                arr[j] = (float)x;
            }
        }
    }

    // sort(arr, arr+n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    // vector<float> v(n);

    // for(int i = 0; i < n;i++)
    // {
    //     cin >> v[i];
    // }

    // sort(v.begin(), v.end());

    // for(auto i : v){
    //     cout << i << '\n';
    // }
}