#include <iostream>
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
        //   QNode<T> *temp = new QNode<T>(x);
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
            return -1;

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

int main()
{
    // Your code starts here #003
    int n;
    cin >> n;

    Queue q;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    while (n--)
    {
        cout << q.dequeue() << endl;
    }

    // Your code ends here #003
    return 0;
}