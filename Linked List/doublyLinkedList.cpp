#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *nxt;
    node *prv;
};

class DoublyLinkedList
{
public:
    node *head;

    int sz;
    DoublyLinkedList()
    {
        head = NULL;
        sz = 0;
    }

    node *CreateNewNode(int data)
    {
        node *newnode = new node;

        newnode->data = data;
        newnode->nxt = NULL;
        newnode->prv = NULL;

        return newnode;
    }

    /*----------------------------------------
                    Insert
    ------------------------------------------*/
    void InsertAtHead(int data)
    {
        sz++;

        node *newnode = CreateNewNode(data);

        if (head == NULL)
        {
            head = newnode;
            return;
        }

        node *a = head;

        newnode->nxt = a;

        a->prv = newnode;

        head = newnode;
    }

    void Insert(int index, int data)
    {
        if (index > sz)
            return;

        if (index == 0)
        {
            InsertAtHead(data);
            return;
        }
        node *a = head;
        int cur_index = 0;

        while (cur_index != index - 1)
        {
            a = a->nxt;
            cur_index++;
        }
        sz++;
        node *newnode = CreateNewNode(data);
        newnode->nxt = a->nxt;
        newnode->prv = a;
        node *b = a->nxt;
        b->prv = newnode;
        a->nxt = newnode;
    }
    /*----------------------------------------
                    Delete
    ------------------------------------------*/

    // Deletes Given Index
    void Delete(int index)
    {
        if (index >= sz)
        {
            cout << "Index out of range" << endl;
            return;
        }

        node *a = head;
        int cur_index = 0;

        while (cur_index != index)
        {
            a = a->nxt;
            cur_index++;
        }

        node *b = a->prv;
        node *c = a->nxt;

        if (b != NULL)
        {
            b->nxt = c;
        }
        if (c != NULL)
        {
            c->prv = b;
        }

        delete a;
        if (index == 0)
        {
            head = c;
        }
        sz--;
    }
    /*----------------------------------------
                    Traverse
    ------------------------------------------*/
    void Traverse()
    {
        node *a = head;
        while (a != NULL)
        {
            cout << a->data << " ";
            a = a->nxt;
        }
        cout << endl;
    }
    // Inserts the given data at the given index
    void Reverse()
    {
        if (head == NULL)
            return;

        node *a = head;
        int cur_index = 0;

        while (cur_index != sz - 1)
        {
            a = a->nxt;
            cur_index++;
        }

        // Now the last index is in a

        node *b = head;

        while (b != NULL)
        {
            swap(b->nxt, b->prv);
            b = b->prv;
        }
        head = a;
    }

    // Size of the linked list
    int getSize()
    {
        return sz;
    }
};

int main()
{
    DoublyLinkedList dl;

    dl.InsertAtHead(10);
    dl.InsertAtHead(5);
    dl.InsertAtHead(1);

    dl.Traverse();

    cout << dl.getSize() << endl;

    dl.Insert(2, 100);
    dl.Traverse();

    dl.Reverse();
    dl.Traverse();

    cout << dl.getSize() << endl;

    return 0;
}