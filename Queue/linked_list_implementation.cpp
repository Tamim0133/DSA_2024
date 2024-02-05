/*
## Create a class QNode with data members integer data and QNode* next
A parameterized constructor that takes an integer x value as a parameter and sets data equal to x and next as NULL
Create a class Queue with data members QNode front and rear

## Enqueue Operation with parameter x:
- Initialize QNode* temp with data = x
- If the rear is set to NULL then set the front and rear to temp and return(Base Case)
- Else set rear next to temp and then move rear to temp

## Dequeue Operation:
- If the front is set to NULL return(Base Case)
- Initialize QNode temp with front and set front to its next
- If the front is equal to NULL then set the rear to NULL
- Delete temp from the memory

*/

#include <bits/stdc++.h>
using namespace std;

template <class T>
class QNode
{
public:
    T data;
    QNode *next;
    QNode(T d)
    {
        data = d;
        next = NULL;
    }
};

template <class T>
class Queue
{
    QNode<T> *front;
    QNode<T> *rear;
    int size;

public:
    Queue()
    {
        front = rear = NULL;
        size = 0;
    }

    void enQueue(T x)
    {

        // Create a new LL node
        QNode<T> *temp = new QNode<T>(x);

        size++;
        // If queue is empty, then
        // new node is front and rear both
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }

        // Add the new node at
        // the end of queue and change rear
        rear->next = temp;
        rear = temp;
    }

    // Function to remove
    // a key from given queue q
    void deQueue()
    {
        // If queue is empty, return NULL.
        if (front == NULL)
            return;

        // Store previous front and
        // move front one node ahead
        QNode<T> *temp = front;
        front = front->next;

        // If front becomes NULL, then
        // change rear also as NULL
        if (front == NULL)
            rear = NULL;

        delete (temp);
        size--;
    }

    T Front()
    {
        if (front)
            return front->data;
        else
            return -1;
    }
    T Rear()
    {
        if (rear)
            return rear->data;
        else
            return -1;
    }

    int Size()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

// Driver code
int main()
{

    Queue<int> q;
    q.enQueue(10);
    q.enQueue(20);
    cout << "Front : " << q.Front() << endl;
    cout << "Size : " << q.Size() << endl;
    q.deQueue();
    cout << "Front : " << q.Front() << endl;
    cout << "Size : " << q.Size() << endl;
    q.deQueue();
    cout << "Front : " << q.Front() << endl;
    cout << "Size : " << q.Size() << endl;
    q.deQueue();
    cout << "Size : " << q.Size() << endl;

    return 0;
}
// This code is contributed by rathbhupendra
