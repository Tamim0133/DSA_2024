#include <iostream>
using namespace std;

struct ll
{

    struct node
    {
        node *next;
        int val;
    };
    node *head = NULL;
    node *tail = NULL;

    void insert_last(int x)
    {
        // insert x at last
        // Your code starts here #001
        node *a = new node();
        a->val = x;
        a->next = NULL;

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

        // Your code ends here #001
    }

    void sort()
    {
        // Sorts the linked list

        // Your code starts here #002

        for (node *i = head; i != NULL; i = i->next)
        {
            for (node *j = i->next; j != NULL; j = j->next)
            {
                if (i->val > j->val)
                    swap(i->val, j->val);
            }
        }

        // Your code ends here #002
    }

    void print()
    {
        // prints elements from head to tail
        // Your code starts here #003
        node *p = head;
        while (p)
        {
            printf("%d", p->val);
            cout << endl;
            p = p->next;
        }
        // cout << endl;

        // Your code ends here #003
    }
};

int main()
{

    // Your code starts here #004
    int n;
    cin >> n;

    ll l;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        l.insert_last(x);
    }

    l.sort();
    l.print();

    // Your code ends here #004
    return 0;
}