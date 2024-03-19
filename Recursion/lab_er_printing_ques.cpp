
#include <bits/stdc++.h>
using namespace std;
int n;
void print(vector<int> arr, int i)
{
    if (i == n + 1)
        return;

    if (i == n)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int curr = 0;
    if (i % 2)
        curr++;

    while (curr <= 4)
    {
        arr.push_back(curr);
        print(arr, i + 1);
        arr.pop_back();

        curr += 2;
    }
}

int main()
{
    cin >> n;
    vector<int> arr;
    print(arr, 0);
}
