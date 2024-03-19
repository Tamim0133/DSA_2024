#include <bits/stdc++.h>
using namespace std;
int n;

void print(vector<int> &arr, int i, vector<int> &print_arr, vector<int> freq)
{

    if (i == n)
    {
        for (int i = 0; i < print_arr.size(); i++)
        {
            cout << print_arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (auto ele : arr)
    {
        if (!freq[ele])
        {
            freq[ele] = 1;
            print_arr.push_back(ele);
            print(arr, i + 1, print_arr, freq);
            print_arr.pop_back();
            freq[ele] = 0;
        }
    }
}

int main()
{
    cin >> n;
    vector<int> arr(n), print_arr, freq(1000, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    print(arr, 0, print_arr, freq);
}
