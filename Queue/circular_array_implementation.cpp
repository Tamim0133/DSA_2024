#include <iostream>
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
            exit(EXIT_FAILURE);
        return arr[front];
    }

    T Rear()
    {
        if (rear == -1)
            exit(EXIT_FAILURE);
        return arr[rear];
    }

    int Size()
    {
        return size;
    }
};
int main()
{
    Queue<char> q(3);

    q.enQueue('1');
    cout << "F " << q.Front() << endl;
    cout << "R " << q.Rear() << endl;
    cout << "S " << q.Size() << endl;

    q.enQueue('2');
    cout << "F " << q.Front() << endl;
    cout << "R " << q.Rear() << endl;
    cout << "S " << q.Size() << endl;

    q.deQueue();
    cout << "F " << q.Front() << endl;
    cout << "R " << q.Rear() << endl;
    cout << "S " << q.Size() << endl;

    q.enQueue('3');
    cout << "F " << q.Front() << endl;
    cout << "R " << q.Rear() << endl;
    cout << "S " << q.Size() << endl;

    q.enQueue('4');
    cout << "F " << q.Front() << endl;
    cout << "R " << q.Rear() << endl;
    cout << "S " << q.Size() << endl;

    q.enQueue('4');
    cout << "F " << q.Front() << endl;
    cout << "R " << q.Rear() << endl;
    cout << "S " << q.Size() << endl;

    // for (auto i : q.arr)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;
}