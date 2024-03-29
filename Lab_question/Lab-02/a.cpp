#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

class ll
{
public:
    Node *head;
    Node *tail;
    int sz;

    // constructor
    ll()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    /*---------------------------------------
                01: Insert At Head
    ---------------------------------------*/
    void insertAtHead(int d)
    {

        // new node create
        Node *a = new Node(d);
        if (head == NULL)
        {
            head = a;
            tail = a;
        }
        else
        {
            a->next = head;
            head = a;
        }

        sz++;
    }

    /*---------------------------------------
                   02: Insert At Tail
    ---------------------------------------*/
    void insertAtTail(int d)
    {
        // new node create
        Node *a = new Node(d);
        if (tail)
        {
            tail->next = a;
            tail = a;
        }
        else
        {
            head = a;
            tail = a;
        }

        sz++;
    }

    void print()
    {
        Node *p = head;
        while (p)
        {
            printf("%d", p->data);
            cout << endl;
            p = p->next;
        }
        // cout << endl;
    }
};

int main()
{
    ll l;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p, v;
        cin >> p >> v;

        if (p == 0)
        {
            l.insertAtHead(v);
        }
        else
        {
            l.insertAtTail(v);
        }
    }
    l.print();
    return 0;
}