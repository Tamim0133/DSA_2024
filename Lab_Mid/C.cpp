// Anirban Roy Sourov
// C

// 32
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node
{
    int val;
    Node *left;
    Node *mid;
    Node *right;

    Node(int val, Node *left, Node *mid, Node *right)
    {
        this->val = val;
        this->left = left;
        this->mid = mid;
        this->right = right;
    }
};

struct Tree
{
    Node *root;

    void insertRoot(int value)
    {
        root = new Node(value, NULL, NULL, NULL);
    }

    void search(Node *node, int key, int op, int val)
    {
        if (node == NULL)
            return;

        if (node->val == key)
        {
            Node *new_node = new Node(val, NULL, NULL, NULL);
            switch (op)
            {
            case 0:
                node->left = new_node;
                break;
            case 1:
                node->mid = new_node;
                break;
            case 2:
                node->right = new_node;
                break;

            default:
                break;
            }
            return;
        }

        search(node->left, key, op, val);
        search(node->mid, key, op, val);
        search(node->right, key, op, val);
    }

    void insert(int op, int key, int val)
    {
        search(root, key, op, val);
    }

    void print(Node *node)
    {
        if (node == NULL)
            return;

        print(node->left);
        print(node->mid);
        cout << node->val << endl;
        print(node->right);
    }
};

void isEqual(Node *node1, Node *node2, bool &equal)
{
    if (equal == false)
        return;

    if ((node1 == NULL) && (node2 == NULL))
        return;

    if (node1 && (node2 == NULL))
    {
        equal = false;
        return;
    }

    if ((node1 == NULL) && node2)
    {
        equal = false;
        return;
    }

    if (node1->val != node2->val)
    {
        equal = false;
        return;
    }

    isEqual(node1->left, node2->left, equal);
    isEqual(node1->mid, node2->mid, equal);
    isEqual(node1->right, node2->right, equal);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Tree *tree1 = new Tree(), *tree2 = new Tree();

    int root;
    cin >> root;
    tree1->insertRoot(root);
    int operations;
    cin >> operations;
    for (int i = 0; i < operations; i++)
    {
        int op, key, val;
        cin >> op >> key >> val;
        tree1->insert(op, key, val);
    }

    cin >> root;
    tree2->insertRoot(root);

    cin >> operations;
    for (int i = 0; i < operations; i++)
    {
        int op, key, val;
        cin >> op >> key >> val;
        tree2->insert(op, key, val);
    }

    bool equal = true;

    isEqual(tree1->root, tree2->root, equal);

    cout << equal << endl;

    // int root;
    // cin >> root;

    // tree->insertRoot(root);

    // int operations;
    // cin >> operations;

    // while (operations--)
    // {
    //     int op, key, val;
    //     cin >> op >> key >> val;
    //     tree->insert(op, key, val);
    // }

    // tree->print(tree->root);

    return 0;
}