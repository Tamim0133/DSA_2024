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

int evaluatePostfix(string str)
{
    // stack<int> s;
    Stack<int> s;

    for (auto i : str)
    {
        if (i >= '0' and i <= '9')
            s.push(i - '0');
        else
        {
            int val1 = s.top();
            s.pop();
            int val2 = s.top();
            s.pop();
            switch (i)
            {
            case '+':
                s.push(val2 + val1);
                break;
            case '*':
                s.push(val2 * val1);
                break;
            case '/':
                s.push(val2 / val1);
                break;
            case '-':
                s.push(val2 - val1);
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string str;
    cin >> str;

    cout << evaluatePostfix(str);
    cout << endl;

    return 0;
}