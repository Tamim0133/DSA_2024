

// } Driver Code Ends
// User function template for C
#include <bits/stdc++.h>
using namespace std;
template <class T>
class Queue
{
public:
    int rear, front; // Array er position

    int N;    // array er max size
    int size; // array er current size
    T *arr;

    Queue(int s)
    {
        front = rear = -1;
        N = s;
        arr = new T[s];
        size = 0;
    }

    void enQueue(T value)
    {
        if ((rear + 1) % N == front) // Q is Full
            return;
        if (front == -1) // Q is Empty
            front = 0;

        rear = (rear + 1) % N;

        arr[rear] = value;
        size++;
    }

    void deQueue()
    {
        if (front == -1) // Q is Empty
            return;
        if (front == rear) // Q has "one" element
            front = rear = -1;
        else
            front = (front + 1) % N;
        size--;
    }

    T Front()
    {
        if (front == -1)
            return -1;
        return arr[front];
    }

    T Rear()
    {
        if (rear == -1)
            return -1;
        return arr[rear];
    }

    int Size()
    {
        return size;
    }
};

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
            // return -1;
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

int isPalindrome(string S)
{
    int n = 0;

    while (S[n] != '\0')
        n++;

    Queue<char> q(n / 2);
    Stack<char> st;

    for (int i = 0; i < n / 2; i++)
    {
        q.enQueue(S[i]);
    }
    int k = n / 2;
    if (n % 2)
        k++;

    for (int i = k; i < n; i++)
    {
        st.push(S[i]);
    }
    // cout << n << endl;
    for (int i = 0; i < n / 2; i++)
    {
        if (q.Front() != st.top())
            return 0;

        q.deQueue();
        st.pop();
    }
    return 1;
}

//{ Driver Code Starts.

int main()
{

    string s;
    cin >> s;

    if (isPalindrome(s))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}