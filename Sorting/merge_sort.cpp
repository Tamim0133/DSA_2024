#include <iostream>
using namespace std;
int b[1000000];
void merge(int arr[], int lo, int mid, int hi)
{
    int curr1 = lo, curr2 = mid + 1;
    int ind = lo;
    while (curr1 <= mid and curr2 <= hi)
    {
        if (arr[curr1] < arr[curr2])
        {
            b[ind++] = arr[curr1++];
        }
        else
        {
            b[ind++] = arr[curr2++];
        }
    }
    while (curr1 <= mid)
        b[ind++] = arr[curr1++];
    while (curr2 <= hi)
        b[ind++] = arr[curr2++];
    for (int i = lo; i < ind; i++)
        arr[i] = b[i];
}
void merge_sort(int arr[], int lo, int hi)
{
    if (lo == hi)
        return;
    int mid = (lo + hi) >> 1;
    merge_sort(arr, lo, mid);
    merge_sort(arr, mid + 1, hi);
    merge(arr, lo, mid, hi);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (auto &i : arr)
        cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}