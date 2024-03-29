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

    void delete_range(int l, int u)
    {
        // deletes values within the range l and u, inclusive

        // Your code starts here #002
        //  node *p = head;
        node *curr = head;
        node *prev = NULL;
        int pos = 1;
        while (curr != NULL)
        {
            // p = p->next;
            // prev->next = curr->next;
            // curr->next = NULL;

            if (curr->val >= l and curr->val <= u)
            {
                if (pos == 1)
                {
                    node *temp = head;
                    head = head->next;
                    temp->next = NULL;
                    // cout << "Deleteed 1 : " << temp->val << endl;
                    curr = head;
                    // delete temp;
                }
                else
                {
                    prev->next = curr->next;
                    node *a = curr;
                    curr = curr->next;
                    a->next = NULL;
                    pos++;
                    // cout << "Deleteed 2 : " << a->val << endl;
                    // delete a;
                }
            }
            else
            {

                prev = curr;
                curr = curr->next;
                pos++;
            }
            // delete curr;
        }
        // cout << "Out of loop " << endl;
        // Your code ends here #002
    }

    void print()
    {
        // prints elements from head to tail

        // Your code starts here #003
        node *p = head;
        if (head == NULL)
        {
            // cout << "Head is Null" << endl;
        }
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

    int x, y;
    cin >> x >> y;

    l.delete_range(x, y);

    l.print();

    // Your code ends here #004
    return 0;
}