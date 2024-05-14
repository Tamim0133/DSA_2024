#include <bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
struct heap
{
    int size = 0;
    int arr[1000001];
    void add_ele(int x)
    {
        arr[size] = x;
        size++;
        int current = size - 1;
        while (current > 0 and arr[current] < arr[(current - 1) / 2])
        {
            swap(arr[current], arr[(current - 1) / 2]);
            current = (current - 1) / 2;
        }
    }
    void del_ele(int ele)
    {
        int i;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] == ele)
            {
                i = j;
                break;
            }
        }
        arr[i] = arr[size - 1];
        size--;
        int current = i;
        while (current < size)
        {
            int left = 2 * current + 1;
            int right = 2 * current + 2;
            int minimum = -1;
            if (left < size)
                minimum = left;
            if (right < size and arr[right] < arr[left])
                minimum = right;
            if (minimum == -1 || arr[minimum] > arr[current])
                break;
            swap(arr[minimum], arr[current]);
            current = minimum;
        }
    }

    int top()
    {
        return arr[0];
    }
};
heap *h = new heap();
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ch, x;
        cin >> ch;
        if (ch != 3)
            cin >> x;
        if (ch == 1)
            h->add_ele(x);
        else if (ch == 2)
        {
            h->del_ele(x);
        }
        else
            cout << h->top() << endl;
    }
}