#include <bits/stdc++.h>
using namespace std;
int n, k;
bool ekbar = false;

void print(vector<int> &arr, int i, vector<int> &print_arr, vector<int> freq, int k)
{

    if (i == k)
    {
        for (int i = 0; i < print_arr.size(); i++)
        {
            if (i != 0)
                cout << " ";
            cout << print_arr[i];
        }
        cout << endl;
        return;
    }

    for (auto ele : arr)
    {
        if (!freq[ele])
        {
            if (!print_arr.empty() and print_arr.back() > ele or print_arr.empty())
            {
                freq[ele] = 1;
                print_arr.push_back(ele);
                print(arr, i + 1, print_arr, freq, k);
                print_arr.pop_back();
                freq[ele] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    vector<int> arr(n), print_arr, freq(1000, 0);
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i - 1;
    }
    print(arr, 0, print_arr, freq, k);
}