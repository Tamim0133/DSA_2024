#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node(T x)
    {
        data = x;
        next = NULL;
    }
};

template <class T>
class LinkedList
{
public:
    Node<T> *head;
    T size;

    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    void insertAtHead(T d)
    {
        size++;
        Node<T> *newNode = new Node<T>(d);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node<T> *a = head;
        newNode->next = a;
        head = newNode;
    }

    void deleteAtHead()
    {
        if (head == NULL)
            return;
        Node<T> *a = head;
        head = head->next;
        delete a;
        size--;
    }
    T Size()
    {
        return size;
    }
};

template <class T>
class Stack
{
public:
    LinkedList<T> ll;
    Stack()
    {
    }
    T top()
    {
        if (ll.Size() == 0)
        {
            return -1;
        }
        return ll.head->data;
    }
    void push(T d)
    {
        ll.insertAtHead(d);
    }
    void pop()
    {
        ll.deleteAtHead();
    }
    bool isEmpty()
    {
        return ll.Size() == 0;
    }
};
int prec(char a)
{
    if (a == '+' or a == '-')
        return 1;
    else if (a == '*' or a == '/')
        return 2;
    else if (a == '^')
        return 3;
    else
        return -1;
}

int main()
{
    string str;
    cin >> str;

    // stack<char> s;
    Stack<char> s;

    for (auto i : str)
    {
        if ((i >= 'A' and i <= 'Z') or (i >= 'a' and i <= 'z') or (i >= '0' and i <= '9'))
            cout << i;
        else if (i == '(')
            s.push(i);
        else if (i == ')')
        {
            while (s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.isEmpty() and prec(i) <= prec(s.top()))
            {
                cout << s.top();
                s.pop();
            }
            s.push(i);
        }
    }

    while (!s.isEmpty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;

    return 0;
}