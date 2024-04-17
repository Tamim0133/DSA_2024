#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int id;
    int value;
    node *Left;
    node *Right;
    node *mid;
};

class BinaryTree
{
public:
    node *root;

    BinaryTree()
    {
        root = NULL;
    }

    node *CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->value = value;
        newnode->Left = NULL;
        newnode->Right = NULL;
        newnode->mid = NULL;
        return newnode;
    }

    void Search(node *a, int value, int replace_value, int op_no)
    {
        if (a == NULL)
            return;
        if (a->value == value)
        {
            if (op_no == 0)
            {
                if (a->Left == NULL)
                {
                    node *newnode = CreateNewNode(replace_value);
                    a->Left = newnode;
                }
                else
                {
                    a->Left->value = replace_value;
                }
            }
            else if (op_no == 1)
            {
                if (a->mid == NULL)
                {
                    node *newnode = CreateNewNode(replace_value);
                    a->mid = newnode;
                }
                else
                {
                    a->mid->value = replace_value;
                }
            }
            else
            {
                if (a->Right == NULL)
                {
                    node *newnode = CreateNewNode(replace_value);
                    a->Right = newnode;
                }
                else
                {
                    a->Right->value = replace_value;
                }
            }
        }
        Search(a->Left, value, replace_value, op_no);
        Search(a->Right, value, replace_value, op_no);
        Search(a->mid, value, replace_value, op_no);
    }

    void Postorder(node *a)
    {
        if (a == NULL)
        {
            return;
        }

        Postorder(a->Left);
        Postorder(a->mid);

        cout << a->value << endl;

        Postorder(a->Right);
    }
};

int main()
{
    int r;
    cin >> r;

    int operations;
    cin >> operations;
    BinaryTree bt;

    node *a = bt.CreateNewNode(r);
    bt.root = a;
    while (operations--)
    {
        int op, key, val;
        cin >> op >> key >> val;

        bt.Search(bt.root, key, val, op);
    }

    bt.Postorder(bt.root);
}