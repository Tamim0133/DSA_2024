#include <bits/stdc++.h>
using namespace std;

int first(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x) // jodi boro hoy , pichone khujbe
        {
            high = mid - 1;
        }
        else if (arr[mid] < x) // jodi choto hoy, samne khujbo
        {
            low = mid + 1;
        }
        else // arr[mid] == x
        {
            res = mid, high = mid - 1; // save and keep looking back
        }
    }
    return res;
}

int last(int arr[], int x, int n)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x) // jodi boro hoy pichone khujbo
        {
            high = mid - 1;
        }
        else if (arr[mid] < x) // jodi choto hoy samne khujbo
        {
            low = mid + 1;
        }
        else // arr[m] == x
        {
            res = mid;
            low = mid + 1; // save and keep looking forward
            // high = mid - 1; // If last occurence was asked
        }
    }
    return res;
}

// Driver code
int main()
{
    int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int n = sizeof(arr) / sizeof(int);

    int x = 8;
    cout << "First Occurrence = " << first(arr, x, n);
    cout << "\nLast Occurrence = " << last(arr, x, n);

    return 0;
}
