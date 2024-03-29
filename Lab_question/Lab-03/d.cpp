#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k; cin >> n >> k;

    int arr[n+1];
    arr[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    for(int i = k , j = 0; i <= n; i++ , j++){
        cout << arr[i] - arr[j] << endl;
    }
}