// Anirban Roy Sourov
// A

// 32
#include <iostream>
using namespace std;

#define INT_MAX 2147483647

struct LinkedListNode
{
    LinkedListNode *next;
    int val;
};

struct LinkedList
{

    LinkedListNode *head = NULL;
    LinkedListNode *tail = NULL;

    void insert_last(int x)
    {
        // insert int x at last
        LinkedListNode *a = (LinkedListNode *)malloc(sizeof(LinkedListNode));
        a->next = NULL;
        a->val = x;
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
    }

    void print()
    {
        LinkedListNode *p = head;
        while (p)
        {
            cout << p->val << endl;
            p = p->next;
        }
    }
};

struct LinkedListofLinkedListNode
{
    LinkedListofLinkedListNode *next;
    LinkedList *list;
};

struct LinkedListofLinkedList
{

    LinkedListofLinkedListNode *head = NULL;
    LinkedListofLinkedListNode *tail = NULL;

    void insert_last(LinkedList *x)
    {
        // insert LinkedList x at last
        LinkedListofLinkedListNode *a = (LinkedListofLinkedListNode *)malloc(sizeof(LinkedListofLinkedListNode));
        a->next = NULL;
        a->list = x;
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
    }
};

LinkedList *sortLinkedListofLinkedList(LinkedListofLinkedList *lol)
{
    // You code starts here - 001

    LinkedList *sorted = lol->head->list;
    sorted->insert_last(INT_MAX);

    LinkedListofLinkedListNode *temp = lol->head->next;

    // sorted->print(); // checking

    while (temp)
    {
        LinkedList *new_sorted = new LinkedList();
        LinkedList *tempp = temp->list;
        sorted->insert_last(INT_MAX);
        tempp->insert_last(INT_MAX);

        LinkedListNode *head1 = sorted->head;
        LinkedListNode *head2 = tempp->head;

        while (true)
        {
            if (head1->val < head2->val)
            {
                new_sorted->insert_last(head1->val);
                head1 = head1->next;
            }
            else
            {
                new_sorted->insert_last(head2->val);
                head2 = head2->next;
            }

            if ((head1->val == INT_MAX) && (head2->val == INT_MAX))
                break;
        }

        sorted = new_sorted;

        temp = temp->next;
    }

    return sorted;

    // You code ends here - 001
}

int main()
{

    int n, m, v;
    cin >> n;
    LinkedListofLinkedList *lol = new LinkedListofLinkedList();
    for (int i = 0; i < n; i++)
    {
        LinkedList *l = new LinkedList();
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> v;
            l->insert_last(v);
        }
        lol->insert_last(l);
    }

    LinkedList *sorted = sortLinkedListofLinkedList(lol);

    sorted->print();

    return 0;
}