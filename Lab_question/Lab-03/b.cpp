#include <bits/stdc++.h>
using namespace std;

struct Queue
{

    struct node
    {
        node *next;
        int val;
    };
    node *head = NULL;
    node *tail = NULL;

    void enqueue(int x)
    {

        // Your code starts here #001
        node *temp = new node();
        temp->val = x;
        temp->next = NULL;

        // size++;
        // If queue is empty, then
        // new node is head and tail both
        if (tail == NULL)
        {
            head = tail = temp;
            return;
        }

        // Add the new node at
        // the end of queue and change rear
        tail->next = temp;
        tail = temp;

        // Your code ends here #001
    }

    int dequeue()
    {

        // Your code starts here #002
        if (head == NULL)
            return -10001;

        // Store previous head and
        // move head one node ahead
        node *temp = head;
        head = head->next;

        // If head becomes NULL, then
        // change tail also as NULL
        if (head == NULL)
            tail = NULL;
        int x = temp->val;
        delete (temp);
        // size--;
        return x;

        // Your code ends here #002
    }
};

Queue *sortQueue(Queue *q)
{
    // Your code starts here #003
    int arr[1000000];
    int len = 0;
    while (1)
    {
        int x = q->dequeue();
        // cout << "x  : " << x << endl;
        if (x == -10001)
            break;
        arr[len] = x;
        len++;
    }

    // cout << "array -> elements : " << endl;
    // cout <<"i : " << i << endl;

    // for(int j = 0; j < i; j++)
    // {
    //     cout << arr[j] << endl;
    // }

    // for(int j = 0; j < len; j++){
    //     for(int k = j + 1; k < len; k++){
    //         if(arr[k]<arr[j]){
    //             int x = arr[k];
    //             arr[k] = arr[j];
    //             arr[j] = x;
    //         }
    //     }
    // }

    //  int n = len, maxi = 0;
    // // cin >> n;

    // int inp[n], out[n];

    // for (int i = 0; i < n; i++)
    // {
    //     inp[i] = arr[i] + 10100;
    //     if (inp[i] > maxi)
    //         maxi = inp[i];
    // }

    // int count[maxi + 1];
    // for (int i = 0; i <= maxi; i++)
    // {
    //     count[i] = 0;
    // }

    // for (auto i : inp)
    // {
    //     count[i]++;
    // }

    // for (int i = 1; i < maxi + 1; i++)
    // {
    //     count[i] += count[i - 1];
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     out[--count[inp[i]]] = inp[i];
    // }

    // for (auto i : out)
    // {
    //     q->enqueue(i - 10100);
    // }
    // cout << endl;

    // Queue kk;
    // for(int j = 0; j < len; j++)
    // {
    //     q->enqueue(arr[j]);
    //     // q.enqueue(arr[j]);
    // }

    sort(arr, arr + len);
    for (int j = 0; j < len; j++)
    {
        q->enqueue(arr[j]);
        // q.enqueue(arr[j]);
    }

    return q;

    // Your code ends here #003
}

int main()
{

    Queue *q = new Queue();
    int i, n;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        q->enqueue(value);
    }
    Queue *sq = sortQueue(q);
    for (i = 0; i < n; i++)
    {
        cout << sq->dequeue() << endl;
    }
    return 0;
}