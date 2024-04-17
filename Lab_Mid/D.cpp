// 53
#include <iostream>
using namespace std;

#define INT_MAX 2147483647

struct BST
{
    struct node
    {
        int val;
        node *left;
        node *right;
        node *parent;
    };
    node *root = NULL;

    void insert_value(node *p, int x)
    {
        // Your code starts here - 001
        node *newnode = new node;
        newnode->val = x;
        newnode->left = NULL;
        newnode->right = NULL;
        if (root == NULL)
        {
            root = newnode;
            return;
        }

        node *cur = root;
        node *prv = NULL;
        while (cur != NULL)
        {
            if (newnode->val > cur->val)
            {
                prv = cur;
                cur = cur->right;
            }
            else
            {
                prv = cur;
                cur = cur->left;
            }
        }
        if (newnode->val > prv->val)
        {
            prv->right = newnode;
        }
        else
        {
            prv->left = newnode;
        }

        // Your code ends here - 001
    }

    void inorder(node *p)
    {
        // Your code starts here - 002
        if (p == NULL)
        {
            return;
        }
        inorder(p->left);
        cout << p->val << endl;
        inorder(p->right);

        // Your code ends here - 002
    }

    void delete_value(int x)
    {
        // Your code starts here - 003
        node *cur = root;
        node *prv = NULL;

        while (cur != NULL)
        {
            if (x > cur->val)
            {
                prv = cur;
                cur = cur->right;
            }
            else if (x < cur->val)
            {
                prv = cur;
                cur = cur->left;
            }
            else
            {
                break;
            }
        }
        if (cur == NULL)
        {
            // cout << "Value is not present in BST\n";
            return;
        }
        // Case 1: both child is NULL
        if (cur->left == NULL && cur->right == NULL)
        {
            if (prv->left != NULL && prv->left->val == cur->val)
            {
                prv->left = NULL;
            }
            else
            {
                prv->right = NULL;
            }
            delete cur;
            return;
        }
        // Case 2: node has only one child
        if (cur->left == NULL && cur->right != NULL)
        {
            if (prv->left != NULL && prv->left->val == cur->val)
            {
                prv->left = cur->right;
            }
            else
            {
                prv->right = cur->right;
            }
            delete cur;
            return;
        }
        if (cur->left != NULL && cur->right == NULL)
        {
            if (prv->left != NULL && prv->left->val == cur->val)
            {
                prv->left = cur->left;
            }
            else
            {
                prv->right = cur->left;
            }
            delete cur;
            return;
        }
        // Case 3: node has two child
        node *tmp = cur->right;
        while (tmp->left != NULL)
        {
            tmp = tmp->left;
        }
        int saved = tmp->val;
        delete_value(saved);
        cur->val = saved;
        // saved = NULL;

        // Your code ends here - 003
    }
};

int main()
{

    BST *bst = new BST();
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        bst->insert_value(bst->root, v);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int v;
        cin >> v;
        bst->delete_value(v);
    }

    bst->inorder(bst->root);
    return 0;
}