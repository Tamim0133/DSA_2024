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

        node *p = new node();
        p->val = x;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }

        // Your code ends here #001
    }

    int dequeue()
    {

        // Your code starts here #002

        int x = head->val;
        if (head == tail)
        {
            delete (head);
            head = NULL;
            tail = NULL;
        }
        else
        {
            node *p = head;
            head = head->next;
            delete (p);
        }
        return x;

        // Your code ends here #002
    }
};
Queue *sortQueue(Queue *q)
{
    // Your code starts here #003

    int hsh[2020] = {};
    Queue::node *temp1 = q->head;
    while (temp1 != NULL)
    {
        hsh[temp1->val + 1000]++;
        temp1 = temp1->next;
    }
    Queue::node *temp2 = q->head;
    for (int i = 0; i <= 2000; i++)
    {
        while (hsh[i])
        {
            hsh[i]--;
            temp2->val = i - 1000;
            temp2 = temp2->next;
        }
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
// Write to Coding Enthusiasts💪
