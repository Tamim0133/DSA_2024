#include <iostream>
using namespace std;
const int N = 1005;

int main()
{
    int n;
    cin >> n;

    int arr[N][N] = {};

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[x][y]++;
    }

    for (int i = 0; i < 1005; i++)
    {
        for (int j = 0; j < 1005; j++)
        {
            while (arr[i][j]--)
            {
                cout << i << " " << j << endl;
            }
        }
    }
}